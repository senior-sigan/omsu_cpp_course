# RAII + Templates. Smart Pointer

В этой практике мы познакомимся с идиомой RAII и реализуем свои умные указатели.

[Шаблон задачи в replit](https://replit.com/@IlyaSiganov/smartptr#main.cpp)

## RAII + Templates

Получение ресурса есть инициализация (англ. Resource Acquisition Is Initialization (RAII)) — программная **идиома** объектно-ориентированного программирования, смысл которой заключается в том, что с помощью тех или иных программных механизмов получение некоторого ресурса неразрывно совмещается с инициализацией, а освобождение — с уничтожением объекта.

## 😨 Что это было?

Разберёмся, что же имеется ввиду.

Если вы открыли файл, то вам надо его закрыть. Так написаны библиотеки. Так работает ОС. Так устроен мир. Давайте напишем код для обработки мемасов:

```cpp
void my_cool_function() {
  auto file = open("funny_meme.jpg"); // тут нам выдают какой-то ресурс
  // делаем всякие штуки тут
  // просто кодим
  // окда
  close(file); // а тут мы ресур "возвращаем". Как очистка памяти.
  // теперь всё ок, память не утекла, ОС не лагает, 
  // юзер счастлив и может открыть еще одну вкладку браузера
}
```

Почему бы не писать всегда так? В чём проблема? 

1. Во-первых, можно забыть написать `close(file)`. И я бы точно забыл. 🤪
2. Во-вторых, может быть непонятно, надо освобождать или нет. Когда освобождать? Вдруг через 10 минут и в другой функции? Или как-то вместе с чем-то еще? Или внутри вложенного if-else?  🤯
3. В-третьих, если произойдет какая-то ошибка в строчке `// окда` и выпадет исключение (вы же помните что это?), тогда ресурс окажется неосвобождённым, а это неэтично 😵. Принцип RAII и некоторые механизмы языка позволят нам ГАРАНТИРОВАННО освободить ресурс. Но как?

    ```cpp
    // !!!!!!
    // Пример кода для __гиков__.

    // lazy_string - это какой-то класс для ленивых строк, ок.
    // lhs - left hand side
    // rhs - right hand side
    lazy_string concat(lazy_string lhs, lazy_string rhs) {
        // тут мы выделяем память вручную
        // Забавно, но этот buffer утечет, если кто-то бросит исключение
        char* buffer = new char*[lhs.size() + rhs.size() + 1]{};

        for (size_t i = 0; i < lhs.size(); ++i) {
            buffer[i] = lhs.at(i);
        }
        // не по тому итерируемся, at бросит исключение
        for (size_t i = 0; i < lhs.size(); ++i) {
            buffer[lhs.size() + i] = rhs.at(i); // БДЫЩЬ!!!!!!!
        }
        auto result = lazy_string(buffer);
        // там вылетело исключение, а сюда мы больше НИКОГДА не дойдем
        // значит delete не будет вызван. Значит память утекла
        delete[] buffer;
        return result;
    }
    ```

## 🧐 Как сделать RAII в С++?

В с++ есть классы. У классов есть конструкторы и деструкторы. Сконструировать экземпляр класса можно на стеке, а можно в куче. Переменные, созданные на стеке называются "автоматическими". А автоматические переменные удаляются, хм, *автоматически,* когда заканчивается область их действия (закончился блок кода внутри фигурных скобок, выпало исключение, выключили интернет в этой стране). А когда экземпляр уничтожается, то вызывается деструктор (или вызывается деструктор, чтобы объект уничтожился? weird 😓). 

Чувствуете?

**За нас кто-то** автоматически вызовет функцию-деструктор, даже если вылетит исключение!!! Этот эффект мы и будем эксплуатировать. 🙀

## Память как ресурс

Память в куче - это тоже ресурс. Мы получаем этот ресурс вызывая `new` или `malloc`. И возвращаем с помощью `delete` или `free`. И мы можем забыть вызвать освобождение или освобождение может быть отложенным, непонятным или сломаным из-за исключения.

Давайте сделаем умные указатели

Я могу написать очень простой код для "умного указателя". Который будет использовать идиому RAII и автоматически очистит память!

```cpp
#include <iostream>

template <typename T>
class SmartPointer {
 private:
  T *ptr_; // в этой переменной ранится СЫРОЙ указатель
  // по сути этот класс ВЛАДЕЕТ сырым указателем. 

 public:
  SmartPointer(T *ptr) : ptr_(ptr) {
    std::cout << "SmartPointer is created and wraps a ptr" << std::endl;
  }

  T *Get() const { return ptr_; }

  ~SmartPointer() {
    std::cout << "Deleting SmartPointer and original ptr" << std::endl;
    delete ptr_; // весь сырбор ради этой строчки. 
  }
};

int main() {
  {  // Начался новый блок кода. Да, так можно.
    // Создадим на стеке умный указатель и положим в него указатель на int
    SmartPointer<int> sptr(new int(42));
    // получаем указатель на int методом get.
    std::cout << *sptr.Get() << std::endl;
    *sptr.Get() = 7;  // даже изменяем число по адресу!
    std::cout << *sptr.Get() << std::endl;
  }  // вот где-то тут вызовется деструктор sptr потому-что эта переменная
     // автоматическая, а так как внутри деструктора SmartPointer мы удалили
     // указатель, то мы освободили ресурс!!

  return 0;
}
```

![img](/images/smartptr.jpg)

К сожалению у этого умного указателя есть куча недостатков:

- этот объект можно скопировать, а значит будет два умных указателя, смотрящих на один и тот же ресурс. Значит, когда два умных указателя удалятся они попытаются дважды освободить ресурс, что приведет к сегфолту. (двойная очистка памяти, а это ошибка)
- так как это указатель, то он должен себя вести как указатель: надо переопределять оператор `*`, `->`, `bool`

## Задание

Следующее поколение должно исправлять ошибки предыдущего, поэтому вы напишите два вида умных указателей, которые намного круче моего `SmartPointer`.

## Задача 1. `scoped_ptr<T>`

Время жизни такого указателя - от места создания указателя до конца объемлющего скоупа.

### Интерфейс класса `scoped_ptr`

```cpp
template <typename T>
class scoped_ptr {
public:
  typedef T element_type; // просто оставьте это здесь.

  // явный конструктор для оборачивания указателя

  // удалите конструктор копирования

  // удалите конструктор перемещения

  // деструктор

  // метод get чтобы взять указатель
  
  // оператор -> чтобы взять указатель. 

  // оператор * разыменования указателя и получения ссылки на объект T

  // метод reset для очистки или замены указателя

  // метод release чтобы отдать сырой указатель, НО НЕ УДАЛЯТЬ его

  // это оператор, чтобы можно было писать if (sptr) { ... }.
  explicit operator bool() const;
};
```

### Финальный тест  `scoped_ptr`

```cpp
#include <cassert>

static void test_scoped_ptr() {
  static_assert(
      !std::is_convertible<int *, scoped_ptr<int>>::value,
      "scoped ptr should not have implicit constructor from pointer!");

  static_assert(!std::is_copy_constructible<scoped_ptr<int>>::value,
                "scoped ptr should not be copiable");

  static_assert(!std::is_move_constructible<scoped_ptr<int>>::value,
                "scoped ptr should not be movable");

  static_assert(!std::is_copy_assignable<scoped_ptr<int>>::value,
                "scoped ptr should not be copiable by operator=");

  static_assert(!std::is_move_assignable<scoped_ptr<int>>::value,
                "scoped ptr should not be movable by operator=");

  static_assert(std::is_same<scoped_ptr<int>::element_type, int>::value,
                "scoped ptr should contain element_type");

  static_assert(
      std::is_constructible<bool, scoped_ptr<int>>::value // explicit conversion
          && !std::is_convertible<scoped_ptr<int>,
                                  bool>::value, // implicit conversion
      "scoped ptr should convertible to the bool, but not implicitly");

  {
    scoped_ptr<int> empty_ptr;

    assert(!empty_ptr);
    assert(empty_ptr.get() == nullptr);
  }

  {
    struct entity {
      int f1;
      std::string f2;
    };

    static_assert(std::is_same<scoped_ptr<entity>::element_type, entity>::value,
                  "scoped ptr should contain element_type");

    scoped_ptr<entity> const ptr{new entity{10, "hello"}};

    assert(ptr->f1 == 10);
    assert(ptr->f2 == "hello");

    assert((*ptr).f1 == 10);
    assert((*ptr).f2 == "hello");

    assert(ptr.get()->f1 == 10);
    assert(ptr.get()->f2 == "hello");
  }

  {
    scoped_ptr<int> ptr{new int{10}};
    assert(*ptr == 10);
    assert(ptr);

    ptr.reset();
    assert(ptr.get() == nullptr);
    assert(!ptr);

    ptr.reset(new int{20});
    assert(*ptr == 20);
  }

  {
    int *i = new int{10};
    scoped_ptr<int> ptr{i};

    assert(i == ptr.release());

    delete i;
  }
}
```

### Пример использования `scoped_ptr`

```cpp
// Тут простой тест с примером использования
struct foo {
  int field1;
  int field2;
};

void bar() {
    scoped_ptr<foo> foo_ptr(new foo {0, 111});
    std::cout << (*foo_ptr).field1
        << foo_ptr->field1
        << foo_ptr.get()
        << std::endl;

    if (foo_ptr) foo_ptr->field1 += 1;

    foo_ptr = std::move(foo_ptr); // - compilation fails
    auto foo_ptr2(foo_ptr);// - compilation fails
    foo_ptr = foo_ptr; // - compilation fails
    bool status = foo_ptr; // - compilation fails
} // foo_ptr уничтожен. Оператор delete вызван автоматически.
```

## Задача 2. `shared_ptr<T>`

Это более умный указатель, которое поддерживает копирование и удаляет ресурс после удаления последнего ссылающегося умного указателя.

### финальный тест shared_ptr

```cpp
#include <cassert>

static void test_shared_ptr() {
  static_assert(
      !std::is_convertible<int *, shared_ptr<int>>::value,
      "shared ptr should not have implicit constructor from pointer!");

  static_assert(std::is_same<shared_ptr<int>::element_type, int>::value,
                "shared ptr should contain element_type");

  static_assert(
      std::is_constructible<bool, shared_ptr<int>>::value // explicit conversion
          && !std::is_convertible<shared_ptr<int>,
                                  bool>::value, // implicit conversion
      "shared ptr should convertible to the bool, but not implicitly");

  {
    shared_ptr<int> empty_ptr;

    assert(!empty_ptr);
    assert(empty_ptr.get() == nullptr);
  }

  {
    struct entity {
      int f1;
      std::string f2;
    };

    static_assert(std::is_same<shared_ptr<entity>::element_type, entity>::value,
                  "shared ptr should contain element_type");

    shared_ptr<entity> const ptr{new entity{10, "hello"}};

    assert(ptr->f1 == 10);
    assert(ptr->f2 == "hello");

    assert((*ptr).f1 == 10);
    assert((*ptr).f2 == "hello");

    assert(ptr.get()->f1 == 10);
    assert(ptr.get()->f2 == "hello");
  }

  {
    shared_ptr<int> ptr{new int{10}};
    assert(*ptr == 10);
    assert(ptr);

    ptr.reset();
    assert(ptr.get() == nullptr);
    assert(!ptr);

    ptr.reset(new int{20});
    assert(*ptr == 20);
  }

  {
    shared_ptr<int> ptr{new int{10}};

    ptr = static_cast<shared_ptr<int> const &>(ptr);

    {
      shared_ptr<int> other{ptr};

      assert(other.get() == ptr.get());
      assert(&(*other) == &(*ptr));
    }

    {
      shared_ptr<int> other;

      other = ptr;

      assert(other.get() == ptr.get());
      assert(&(*other) == &(*ptr));
    }
  }

  {
    shared_ptr<int> first{new int{10}};
    shared_ptr<int> second{first};

    first.reset();
    assert(first.get() != second.get());

    first = second;
    assert(first.get() == second.get());

    second.reset(new int{20});
    assert(first.get() != second.get());

    second = first;
    assert(first.get() == second.get());
  }
  {
    int trigger = 42;
    struct A {
      int *a_;
      explicit A(int *a) : a_(a) {}
      ~A() { *a_ = 0; }
    };

    {
      shared_ptr<A> first{new A{&trigger}};
      auto second = first;
      auto third = second;
      auto fourth = third;
      auto fifth = second;

      assert(first.get() == first.get());
      assert(*first->a_ == 42);
      assert(*fifth->a_ == 42);
    }
    assert(trigger == 0);
  }
}
```

### Интерфейс shared_ptr

```cpp
template <typename T> 
class shared_ptr {
  // сам сырой указатель
  // счетчик ссылок. Скорее всего это указатель на int :)
public:
  // явный конструктор для оборачивания указателя

  // конструктор копирования, который инкрементирует счетчик ссылок  и сохраняет указатель

  // конструктор перемещения оставьте тот, который генерируется по-умолчанию

  // деструктор (уменьшает счетчик ссылок. 
  //   Если видит, что счетчик ссылок == 0, то уничтожает данные и по самому указателю.

  // метод get чтобы взять указатель
  T* get() const;
  
  // оператор -> чтобы взять указатель. 

  // оператор * разыменования указателя и получения ссылки на объект T

  // заменяет хранимый указатель на другой
  void reset(T* other = nullptr);

  // метода release нет, так как он в жанном случае не имеет смысла

  // это оператор, чтобы можно было писать if (sptr) { ... }.
  explicit operator bool() const;
};
```

### пример использования shared_ptr

```cpp
shared_ptr<foo> foo_shptr(new foo {888, 999});
shared_ptr<foo> foo_shptr2 = foo_shptr;
assert(foo_shptr.get() == foo_shptr2.get());
std::cout << foo_shptr->field1
    << " "
    << foo_shptr2->field1
    << std::endl;

// плохое использование
// приводи к двойному удалению, так как теперь два умных указателя 
// "владеют" одним обхектом, не зная друг о друге
shared_ptr<foo> foo_shptr3(foo_shptr2.get());
/**
Тут выпадет segfault:
  
smart_pointer_2(2642,0x1180fddc0) malloc: *** error for object 0x7fe322504080: pointer being freed was not allocated
smart_pointer_2(2642,0x1180fddc0) malloc: *** set a breakpoint in malloc_error_break to debug
/**
```

## Задача 3. `weak_ptr<T>`

TODO: тут будет очень горячо....

@Ilya Siganov сделай описание задачи!!!

TODO: разобраться надо ли хранить указатель на старый shared_ptr в поле weak_ptr

## Ради чего всё это было?

> Ни в коем случае не пишите свои умные указатели. В стандарте с++11 они уже есть в STL, а для древних стандартов есть Библиотека boost. Написать правильно умный указатель очень сложно! В заданиях было много упрощений.

Почему мы любим java, go, python, ruby, js, c#? Потому что там не надо думать про память и  указатели. Думают об этом редко и только когда припекло. Платформы сами как-то следят за памятью и делают все более менее хорошо.

В с/с++ думают о памяти всегда. Постоянно. И это обычно приводит к тому, что сложные приложения на с++ пишут только хардкорные бородачи (это не сексизм).

Но так было раньше! В современном с++ (скажем, начиная со стандарта с++17) можно и НУЖНО писать код используя Только умные указатели. А умные указатели нам гарантируют безопасность, автоматичность и счастливую жизнь.

В с++17 и далее не принято использовать не то, чтобы malloc, но даже new! Категорически не рекомендуется владеть и использовать сырые указателями, которые надо будет чистить вручную.

Кстати, для зануд. Проблема не в том, что люди забывают очищать память. Проблема скорее в том, что не понятно кто ВЛАДЕЕТ данным указателем. ТО есть какая сущность в коде отвечает за удаление этого объекта. Умные указатели решают эту проблему.

Какие бывают умные указатели (перечислены в хедере `<memory>`)

1. `std::unique_ptr` - уникально владеет объектом. Не может быть скопирован. Уничтожает объект сразу, как только уничтожен сам. Внимание. 90% всех случаев покрывает этот вид указателя. Просто ВСЕГДА начинайте с него.
2. `std::shared_ptr` - в отличие от уникального, этот указатель РАЗДЕЛЯЕТ ВЛАДЕНИЕ между другими объектами. Нужно использовать если есть два объекта A и B. Оба владеют указателем на PTR. Уничтожен PTR должен быть только тогда, когда A и B оба уничтожены. В каком порядке A и B уничтожаются - неизвестно.
3. `std::weak_ptr` - слабый "невладеющий" указатель. нужен для сложных циклических зависимостей.

TODO: добавить тест на reset

TODO: Добавить тест на move семантику

TODO: Добавить тест на weak_ptr
