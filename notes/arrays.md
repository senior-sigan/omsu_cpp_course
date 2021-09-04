# Массивы

На этой практике разбираем алгоритмы работы с одномерными массивами и двумерными массивами (матрицами).

## Примеры

```c
/**
 * Эта программа заполнит двумерный массив числами от 0 до 8. 
 * И будет выведено на экран:
 * 0 1 2                                                     
 * 3 4 5
 * 6 7 8
 */

#include<stdio.h>

int main(void) {
  short matrix[3][3];
  int el = 0;
  for (unsigned int i = 0; i < 3;i++) {
    for (unsigned int j = 0; j < 3; j++) {
      matrix[i][j] = el;
      el++;
    }
  }

  for (unsigned int i = 0; i < 3;i++) {
    printf("\n");
    for (unsigned int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
  }

  return 0;
}
```

## Задания

В задачах этой темы не требуется выделять память динамически. То есть всё должно работать на обычных массивах на стеке. 

НИ в коем случае не делайте так:

```c
/**
 *
 * Это пример НЕ РАБОТАЮЩЕГО КОДА.
 * НИКОГДА ТАК НЕ ДЕЛАЙТЕ.
 **/

#include <stdio.h>

int main() {
  int n = 0;
  scanf("%d", &n); // в n появится значение во время выполнения

  // для arr[] память должна быть выделена на этапе компиляции
  // на этапе компиляции в n лежит 0
  int arr[n]; // НИКОГДА НЕ ИСПОЛЬЗУЙТЕ ДЛЯ РАЗМЕРА МАССИВА ПЕРЕМЕННУЮ

  for (int i = 0; i < n; i++) {
    arr[i] = i; // тут будет ошибка с 99.99% вероятностью
  }

  return 0;
}
```

Делайте так:

```c
#include <stdio.h>

#define N 10

int main() {
  // на этапе препроцессинга сюда подставится 10.
  // на этапе компиляции будет размечена память на 10 int-ов
  int arr[N];

  for (int i = 0; i < N; i++) {
    arr[i] = i; // всё хорошо
  }
}
```