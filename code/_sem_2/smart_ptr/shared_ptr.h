#pragma once

#include <utility>  // std::exchange

// forward declaration
// если будете делать weak_ptr То это понадобится
template<class T>
class weak_ptr;

// Специальный класс-обёртка, который хранит указатель на объект и счетчики.
// Код control_block не надо менять.
template<typename T>
struct control_block {
  T* ptr;             // указатель на контролируемый объект
  long ref_counter;   // счётчик сильных ссылок
  long weak_counter;  // счетчик слабых ссылок

  ControlBlock(T* ptr, long ref_counter, long weak_counter)
      : ptr(ptr), ref_counter(ref_counter), weak_counter(weak_counter) {}
};

template<typename T>
class shared_ptr {
  control_block<T>* cb_;  // объект, который хранит указатель и счетчики
 public:
  using element_type = T;  // просто чтобы следовать сигнатурам stdlib

  // явный конструктор для оборачивания указателя
  explicit shared_ptr(T* ptr = nullptr);
  // конструктор копирования, который инкрементирует счетчик ссылок  и сохраняет указатель
  shared_ptr(shared_ptr& other);
  shared_ptr(const shared_ptr& other);
  shared_ptr(shared_ptr&& other) noexcept;  // тут понадобится std::exchange

  //!!!!!!!! РАСКОММЕНТИРУЙТЕ если будете делать weak ptr
  // explicit shared_ptr(const weak_ptr<T>& ptr);

  // Деструктор (уменьшает счетчик ссылок.
  // Если видит, что счетчик ссылок == 0, то уничтожает данные и по самому указателю.
  ~shared_ptr();

  // метод get чтобы взять указатель
  T* get() const;

  // оператор * разыменования указателя и получения ссылки на объект T
  T& operator*() const;

  // оператор -> чтобы взять указатель.
  T* operator->() const;

  // это оператор, чтобы можно было писать if (sptr) { ... }.
  explicit operator bool() const;

  /**
   * Replaces the managed object with an object pointed to by ptr.
   * If *this already owns an object and it is the last shared_ptr owning it,
   * the object is destroyed
   *
   * @param ptr - pointer to an object to acquire ownership of
   */
  void reset(T* ptr = nullptr);

  // метода release нет, так как он в данном случае не имеет смысла

  void swap(shared_ptr& r) noexcept;

  shared_ptr& operator=(const shared_ptr& rhs) noexcept;
  shared_ptr& operator=(shared_ptr&& rhs) noexcept;

  long use_count() const noexcept;

  //!!!!!!!! РАСКОММЕНТИРУЙТЕ если будете делать weak ptr
  // friend weak_ptr<T>; // чтобы иметь доступ до приватного control_block
};
