#pragma once

#include <cassert>

#include "unique_ptr.h"

static void test_unique_ptr() {
  static_assert(!std::is_convertible<int*, unique_ptr<int>>::value,
                "unique ptr should not have implicit constructor from pointer!");

  static_assert(!std::is_copy_constructible<unique_ptr<int>>::value,
                "unique ptr should not be copiable");

  static_assert(!std::is_move_constructible<unique_ptr<int>>::value,
                "unique ptr should not be movable");

  static_assert(!std::is_copy_assignable<unique_ptr<int>>::value,
                "unique ptr should not be copiable by operator=");

  static_assert(!std::is_move_assignable<unique_ptr<int>>::value,
                "unique ptr should not be movable by operator=");

  static_assert(std::is_same<unique_ptr<int>::element_type, int>::value,
                "unique ptr should contain element_type");

  static_assert(std::is_constructible<bool, unique_ptr<int>>::value  // explicit conversion
                    && !std::is_convertible<unique_ptr<int>,
                                            bool>::value,  // implicit conversion
                "unique ptr should convertible to the bool, but not implicitly");

  {
    unique_ptr<int> empty_ptr;

    assert(!empty_ptr);
    assert(empty_ptr.get() == nullptr);
  }

  {
    struct entity {
      int f1;
      std::string f2;
    };

    static_assert(std::is_same<unique_ptr<entity>::element_type, entity>::value,
                  "unique ptr should contain element_type");

    unique_ptr<entity> const ptr{new entity{10, "hello"}};

    assert(ptr->f1 == 10);
    assert(ptr->f2 == "hello");

    assert((*ptr).f1 == 10);
    assert((*ptr).f2 == "hello");

    assert(ptr.get()->f1 == 10);
    assert(ptr.get()->f2 == "hello");
  }

  {
    unique_ptr<int> ptr{new int{10}};
    assert(*ptr == 10);
    assert(ptr);

    ptr.reset();
    assert(ptr.get() == nullptr);
    assert(!ptr);

    ptr.reset(new int{20});
    assert(*ptr == 20);
  }

  {
    int* i = new int{10};
    unique_ptr<int> ptr{i};

    assert(i == ptr.release());

    delete i;
  }
}
