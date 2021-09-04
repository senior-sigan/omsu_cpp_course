#ifndef LIST_LIST_H
#define LIST_LIST_H

typedef struct List List; // не специфицированная структура, конкретные реализации должны быть описаны в c-файлах

List *NewList(); // создание пустого списка
void DestroyList(List*); // освобождает всю памят, занимаемую списком

void Append(List *, int); // вставка элемента в конец списка
void Prepend(List *, int); // вставка элемента в начало списка
void AppendAll(List *, const List *); // вставить все элементы одного списка в конец другого
void InsertAt(List *, int, int); // вставка элемента после индекса

void RemoveAt(List *, int); // удаление элемента по индексу
void RemoveAll(List *); // удаление всех элементов из списка

int Pop(List *); // удаление элемента с конца списка, функция возвращает удаленный элемент
int Dequeue(List *); // удаление элемента с начала списка, функция возвращает удаленный элемент

int Length(const List *); // вычисление длины списка
int GetAt(const List *, int); // взятие элемента списка по индексу

#endif //LIST_LIST_H