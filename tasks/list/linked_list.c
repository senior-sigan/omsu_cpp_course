#include <stdlib.h>
#include "list.h"

// В узле списка хранится само значение value и указатель на следующий узел.
// Эту структуру пользователи списка не должны видеть, так как она относится к
// внутренней реализации.
typedef struct Node_ {
  int value;  // само значение, которое хранит узел
  struct Node_ *next;  // указатель на следующий узел
} Node;

// Пользовательская структура, которая скрывает механизм хранения данных.
struct List {
  Node *head;  // указатель на голову списка
  Node *tail;  // указатель на хвост списка
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
