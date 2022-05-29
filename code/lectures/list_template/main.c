#include "list.h"
#include <stdio.h>
#include <stdlib.h>

static void AssertEq(int expected, int actual, const char* msg) {
  if (expected != actual) {
    printf("Test failed: %s\n expected %d but got %d\n", msg, expected, actual);
    exit(-1);
  }
}

int main(void) {
  List* list = NewList();
  AssertEq(0, Length(list), "empty list length should be zero");
  Append(list, 42);
  AssertEq(1, Length(list), "Length([42]) should be 1");
  AssertEq(42, GetAt(list, 0), "GetAt([42], 0) should be 42");
  DestroyList(list);
  
  //TODO: Здесь куча разных ваших тестов!!!
}   