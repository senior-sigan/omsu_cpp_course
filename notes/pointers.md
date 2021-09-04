# Указатели

На этой практике разбираемся с указателями, строками и массивами. После этой практики вы должны уметь без Google объяснить:

- что такое указатели и как их использовать
- что такое массивы и как их использовать
- в чем разница между указателями и массивами

## Примеры

### Просто указатели

Запустите программу и посмотрите что будет выведено на экран.

```c
#include <stdio.h>

int main(void) {
  int a = 10; // это обычная переменная
  int* b; // это объявление указателя на int
  // & - операция взятия указателя
  b = &a; // это присвоение указателю b адреса переменной a
  // * - операция разыменования указателя. То есть взятия значения по адресу
  int c = 32 + *b; // *b - это получение данных лежащих в памяти по адрему b.
  printf("&c=%p\tс=%d\n",&c, c);
  *b = 100500; // можно изменить объект в памяти по указателю
  printf("&a=%p b=%p\ta=%d, *b=%d\n", &a, b, a, *b); // значение переменной изменилось, так как изменили сам объект в памяти по адресу, на который показывает указателю.
  b = &c; // можно поменять адрес, на который смотрит указатель
  printf("b=%p &c=%p\t*b=%d\n",b, &c, *b); // %p - распечатать адрес в виде 16-ричного числа.
  return 0;
}
```

Результат вывода. Адреса переменных будут другими, а значения переменных такими же.

```text
&c=0x7ffeec08a8cc с=42
&a=0x7ffeec08a8dc b=0x7ffeec08a8dc  a=100500, *b=100500
b=0x7ffeec08a8cc &c=0x7ffeec08a8cc *b=42
```

### Указатели как аргументы функции

С одной такой функцией вы знакомы. Это `scanf`.

```c
#include <stdio.h>

//функция, чтобы считать число с консоли
void read_int(int* var) {
  // обычно мы пишем scanf("%d", &i), потому что i - это переменная, но не указатель
  scanf("%d", var); // обратите внимание, что var - это указатель
}

int main(void) {
  int digit;
  read_int(&digit);
  printf("%d\n", digit);
  return 0;
}
```

### Указатели и массивы

```c
#include <stdio.h>

int main(void) {
  short arr[10]; // создадим массив на стеке
  // заполним массив числами 10,20...100
  for (int i = 0; i<10;i++){
    arr[i] = (i+1)*10;
  }
  short* ptr; // объявим указатель на int
  ptr = &arr[0]; // положим в ptr указатель на первый элемент массива arr

  printf("%p == %p\n", arr, ptr); // arr и ptr по указывают на одно и то же место в памяти

  // если к указателю прибавить/удалить число, то мы получим смещение в памяти на sizeof(POINTER TYPE).
  // Внезапно *(ptr+i) == ptr[i]
  printf("%p\t%d\t%d\n", ptr+1, *(ptr+1), ptr[1]);
  printf("%p\t%d\t%d\n", ptr+2, *(ptr+2), ptr[2]);
  printf("%p\t%d\t%d\n", ptr+3, *(ptr+3), ptr[3]);

  // грязые хаки
  printf("==========\n");
  int* sh_ptr = (int*)ptr;
  printf("%d %d\n", sh_ptr[0], sh_ptr[1]);
  sh_ptr[0] = 1000500;
  printf("%d %d\n", ptr[0], ptr[1]);
}
```

Результат работы программы. Адреса могут быть другими.

```text
0x7ffeec9a78c0 == 0x7ffeec9a78c0
0x7ffeec9a78c2	20	20
0x7ffeec9a78c4	30	30
0x7ffeec9a78c6	40	40
==========
1310730 2621470
17460 15
```

## Задания

1. Разрешено использовать `malloc`, `calloc`, `realloc`, `free`, `printf`, `scanf`. Все остальные библиотечный функции запрещены.
2. Вам не требуется выделять память динамически в этих задачах.
3. Вся логика задания должна находиться в функциях.
4. В функции `main` ТОЛЬКО тестирование работоспособности функции.
5. Прототипы функций менять запрещено.
6. Вспомогательные функции создавать можно.