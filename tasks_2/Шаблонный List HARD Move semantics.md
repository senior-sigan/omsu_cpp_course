---
tag: cpp, templates, move_semantics
---

# Шаблонный List HARD. Move semantics *

![img](/images/move.jpg)

Если вы чувствуете в себе силы и хотите понять глубже материалы семантики копирования и перемещения, я предлагаю вам попробовать сделать так, чтобы этот код компилировался у вас тоже:

```cpp
#include <memory>

int main() {
  ArrayList<std::unique_ptr<int>> arr;
  arr.Append(std::make_unique<int>(42)); // Вот тут у вас упадет программа с ошибкой, что у unique_ptr нет конструктора копирования или оператора присванивания
  assert(*arr[0].get() == 42);
  return 0;
}
```

Чтобы решить эту проблему вам придется переопределить метод Append:

```cpp
void Append(const T& value); // это остается как было. Добавление копированием
void Append(T&& value); // это новое - вставка с семантикой перемещения
```

Подробнее о том, как это сделать вы можете посмотреть в трансляции и в [исходниках здесь](https://github.com/senior-sigan/data-structures-training/blob/master/src/stack/stack.h). И в объяснениях ниже.

[youtu.be/mFjQFoO8fmc](https://youtu.be/mFjQFoO8fmc)

## Конструкторы копирования и перемещения, оператор присваивания

Так как ваши классы сложные внутри и хранят указатели на объекты в куче, то к конструкторам надо относиться серьезно.

Почему? Вот хорошее видео, которое на фруктах объясняет что происходит.

[www.youtube.com/watch?v=F-7Rpt2D-zo](https://www.youtube.com/watch?v=F-7Rpt2D-zo)

А это мой пример кода для правильной обработки копирования внутренних массивов.

[gist.github.com/senior-sigan/d527a3b76cd627e625116e64a0f1346f](https://gist.github.com/senior-sigan/d527a3b76cd627e625116e64a0f1346f)
