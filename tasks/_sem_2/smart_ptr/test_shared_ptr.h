#pragma once

#include <cassert>

#include "shared_ptr.h"

static void test_shared_ptr() {
  static_assert(!std::is_convertible<int*, shared_ptr<int>>::value,
                "shared ptr should not have implicit constructor from pointer!");

  static_assert(std::is_same<shared_ptr<int>::element_type, int>::value,
                "shared ptr should contain element_type");

  static_assert(std::is_constructible<bool, shared_ptr<int>>::value  // explicit conversion
                    && !std::is_convertible<shared_ptr<int>,
                                            bool>::value,  // implicit conversion
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

    ptr = static_cast<shared_ptr<int> const&>(ptr);

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
      int* a_;
      explicit A(int* a) : a_(a) {}
      ~A() {
        *a_ = 0;
      }
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
