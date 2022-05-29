#pragma once

#include <utility>  // std::exchange

#include "shared_ptr.h"

template<typename T>
class weak_ptr {
  const shared_ptr<T>* ptr_;
  control_block<T>* cb_;

 public:
  using element_type = T;  // просто чтобы следовать сигнатурам stdlib

  weak_ptr();
  weak_ptr(const weak_ptr& r);
  weak_ptr(weak_ptr&& r) noexcept;
  weak_ptr(const shared_ptr<T>& r);

  ~weak_ptr();

  void reset() noexcept;
  void swap(weak_ptr& r) noexcept;
  long use_count() const noexcept;
  bool expired() const noexcept;
  shared_ptr<T> lock() const noexcept;

  weak_ptr& operator=(const weak_ptr& rhs);
  weak_ptr& operator=(const shared_ptr<T>& rhs);

  friend shared_ptr<T>;  // чтобы иметь доступ до приватного control_block
};
