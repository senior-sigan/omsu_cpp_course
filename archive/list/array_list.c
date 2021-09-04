#include <stdlib.h>
#include "list.h"

// Пользовательская структура, которая скрывает механизм хранения данных.
struct List {
  int *array;  // динамический массив, в котором будут раниться все данные
  int length;  // размер списка: последний занятый индекс в array
  int capacity;  // ёмкость списка: реальный размер массива array
  // если нужно, то добавьте дополнительные поля
};

List *NewList() {
  // TODO: напиши меня!
  return NULL;
}

void DestroyList(List *this) {
  // TODO: напиши меня!
}

void Append(List *this, int value) {
  // TODO: напиши меня!
}
void Prepend(List *this, int value) {
  // TODO: напиши меня!
}
void AppendAll(List *this, const List *that) {
  // TODO: напиши меня!
}
void InsertAt(List *this, int index, int value) {
  // TODO: напиши меня!
}

void RemoveAt(List *this, int index) {
  // TODO: напиши меня!
}
void RemoveAll(List *this) {
  // TODO: напиши меня!
}

int Pop(List *this) {
  // TODO: напиши меня!
  return 0;
}
int Dequeue(List *this) {
  // TODO: напиши меня!
  return 0;
}

int Length(const List *this) {
  // TODO: напиши меня!
  return 0;
}
int GetAt(const List *this, int index) {
  // TODO: напиши меня!
  return 0;
}
