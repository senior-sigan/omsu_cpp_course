#include <iostream>

#include "array_list.h"
#include "linked_list.h"
#include "test.h"

#define List ArrayList  // TODO: проверить тесты с LinkedList

void TestConstructor() {
  {
    LinkedList l;
    ASSERT_EQ(0, l.Size(), "Default LinkedList constructor creates empty list");
  }
  {
    ArrayList l;
    ASSERT_EQ(0, l.Size(), "Default ArrayList constructor creates empty list");
  }
  {
    ArrayList l(42);
    ASSERT_EQ(0, l.Size(),
              "Non-default ArrayList constructor creates empty list but with capacity");
  }
}

void TestPushBack() {
  List l;
  l.PushBack(42);
  ASSERT_EQ(1, l.Size(), "Array size with 1 element should be 1");
  ASSERT_EQ(42, l.Front(), "array[0]=42");
  ASSERT_EQ(42, l[0], "array[0]=42");
  l.PushBack(7);
  ASSERT_EQ(1, l.Size(), "Array size with 2 element should be 2");
  ASSERT_EQ(42, l.Front(), "array[0]=42");
  ASSERT_EQ(42, l[0], "array[0]=42");
  ASSERT_EQ(7, l[1], "array[1]=7");
}

void TestClear() {
  List l;
  l.PushBack(42);
  l.PushBack(7);
  l.PushBack(13);
  ASSERT_EQ(3, l.Size(), "Array with 3 elements");
  l.Clear();
  ASSERT_EQ(0, l.Size(), "Array with 3 elements");
}

void VerifyConstAccess(const List l) {
  ASSERT_EQ(42, l[0], "access");
}

void TestConstAccess() {
  List l;
  l.PushBack(42);
  VerifyConstAccess(l);
  ASSERT_EQ(42, l[0], "access");
  l[0] = 13;
  ASSERT_EQ(13, l[0], "access after modification");
}

void TestMy() {
  // TODO: написать тесты, как сделано выше.
}

int main() {
  SETUP_TESTS();

  RUN_TEST(TestConstructor);
  RUN_TEST(TestPushBack);
  RUN_TEST(TestClear);
  RUN_TEST(TestConstAccess);
  RUN_TEST(TestMy);
}
