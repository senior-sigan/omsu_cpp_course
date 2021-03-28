#pragma once
#include <utility>  // std::exchange

template<typename T>
class unique_ptr {
  T* ptr_;  // указатель на объект, который держит unique_ptr
 public:
  typedef T element_type;  // просто чтобы следовать сигнатурам stdlib

  // явный конструктор для оборачивания указателя
  explicit unique_ptr(T* ptr = nullptr);

  // удалите конструктор копирования

  // конструктор перемещения
  unique_ptr(unique_ptr&& ptr) noexcept : ptr_(std::exchange(ptr.ptr_, nullptr)) {}

  // деструктор
  ~unique_ptr();

  // метод get чтобы взять указатель

  // оператор -> чтобы взять указатель.

  // оператор * разыменования указателя и получения ссылки на объект T

  // метод reset для очистки или замены указателя
  void reset(T* ptr = nullptr);

  // метод release чтобы _отдать_ сырой указатель, НО НЕ УДАЛЯТЬ его
  T* release();

  // это оператор, чтобы можно было писать if (sptr) { ... }.
  explicit operator bool() const;

  /**
   * Меняет местами указатели между двумя unique_ptr
   *
   * @param other - ссылка на другой unique_ptr с которым будем меняться указателями
   */
  void swap(unique_ptr& other) noexcept;

  // оператор присваивания с перемещением
  // указатель который держим в этом экземпляре нужно уничтожить
  // забираем себе указатель на объект из rhs
  // в rhs.ptr_ складываем nullptr
  unique_ptr& operator=(unique_ptr&& rhs) noexcept;
};
