# Абстракции на функциях

TODO: Тема про указатели на функции.

Так как у функции тоже есть адрес в памяти, то в си возможно получить указатель на функцию. Этот указатель потом можно передать в другую функцию как аргумент, сохранить в поле структуры и потом вызвать.

Синтаксис объявления переменной типа указатель на функцию:

```c
RETURN_TYPE (*func_name) (FUNC_ARGUMENTS); 

RETURN_TYPE (*funcs_array[]) (FUNC_ARGUMENTS); // массив указателей на функции
```

Рассмотрим пример:

```c
#include <stdio.h>

void hello(void) {
  printf("Hello");
}

void world(void) {
  printf("World");
}

int main(void) {
  void (*func_ptr)(void); // func_ptr - это ИМЯ переменной для указателя на функцию

  func_ptr = hello;

  func_ptr();

  func_ptr = world;

  func_ptr();

  return 0;
}
```

```c
/**
Пример с массиво указателей на функции
**/

#include <stdio.h>

void add(int x, int y){
    printf("x+y=%d \n", x+y);
}
void subtract(int x, int y){
    printf("x+y=%d \n", x-y);
}
void multiply(int x, int y){
    printf("x*y=%d \n", x*y);
}
int main(void)
{
  const int LEN = 3;
  int a = 10;
  int b = 5;
  void (*operations[LEN])(int, int) = {add, subtract, multiply};

  for(int i=0; i<LEN;i++) {
    operations[i](a, b);    // вызов функции по указателю
  }
    
  return 0;
}
```

Передача указателя на функцию в другую функцию

```c
#include <stdio.h>

int calc(int a, int b, int (*op)(int)) {
  return op(a) + op(b);
}

int inc(int a) {
  return a + 1;
}

int shift(int a) {
  return a << 1;
} 

int main(void) {
  printf("res=%d\n", calc(1,2, inc));
  printf("res=%d\n", calc(1,2, shift));
  return 0;
}
```

Для того чтобы не писать такое сложное объявление функции используют typedef:

```c
typedef тип_возвращаемого_значения (*имя_указ)(список_параметров_функции);
```

Например, для прошлого кода это будет:

```c
#include <stdio.h>

typedef int (*Operation)(int);

int calc(int a, int b, Operation op) { // теперь все просто
  return op(a) + op(b);
}

int inc(int a) {
  int res = a + 1;
  printf("inc(%d) = %d\n", a, res);
  return res;
}

int shift(int a) {
  int res = a << 1;
  printf("shift(%d) = %d\n", a, res);
  return res;
} 

int main(void) {
  printf("res=%d\n", calc(1,2, inc));
  printf("res=%d\n", calc(1,2, shift));
  return 0;
}
```

## Зачем использовать указатели на функции?

Если функцию можно передавать как аргумент функции, то можно создавать абстракции на основе функций, а не только данных.

Например

```c
#include <stdio.h>

double sum_nums(double a, double b) {
  if (a > b) {
    return 0;
  }

  double acc = 0;
  while (a < b) {
    acc += a;
    a++;
  }
  return acc;
}

double sum_nums_f(double a, double b, double (*map)(double)) {
  if (a > b) {
    return 0;
  }

  double acc = 0;
  while (a < b) {
    acc += map(a);
    a++;
  }
  return acc;

}

int sum_nums_f_step(double a, double b, double (*map)(double), double (*next)(double)) {
  if (a > b) {
    return 0;
  }

  double acc = 0;
  while (a < b) {
    acc += map(a);
    a = next(a);
  }
  return acc;

}

// Тогда можно вычислить число Пи

double pi_map(double x) {
  return 1.0 / x*(x+1);
}

double pi_next(double x) {
  return x + 4;
}

int main(void) {
  double pi = sum_nums_f_step(1, 1000, pi_map, pi_next);
  print("pi=%f\n", pi);
  return 0;
}

```

Далее - можно создавать еще более сложные функции, например map и reduce.

В sort используется указатель на void и отправлять в сортировку можно любые данные.

```c
#include "BearLibTerminal.h"

typedef struct GameObject_ {
    char tile;
    int x;
    int y;
    void (*GoUp)(struct GameObject_*);
    void (*GoDown)(struct GameObject_*);
    void (*GoRight)(struct GameObject_*);
    void (*GoLeft)(struct GameObject_*);
} GameObject;

void GoUpSlow(GameObject* player) {
    player->y -= 1;
}
void GoDownSlow(GameObject* player) {
    player->y += 1;
}
void GoRightSlow(GameObject* player) {
    player->x += 1;
}
void GoLeftSlow(GameObject* player) {
    player->x -= 1;
}

GameObject* NewPlayer() {
    GameObject* player = malloc(sizeof(GameObject));
    player->tile = '@';
    player->x = 2;
    player->y = 2;

    player->GoUp = GoUpSlow;
    player->GoDown = GoDownSlow;
    player->GoLeft = GoLeftSlow;
    player->GoRight = GoRightSlow;

    return player;
}

void ShuffleMovement(GameObject* go) {
    go->GoUp = GoLeftSlow;
    go->GoDown = GoRightSlow;
    go->GoLeft = GoUpSlow;
    go->GoRight = GoDownSlow;
}

void NormalizeMovement(GameObject* go) {
    go->GoUp = GoUpSlow;
    go->GoDown = GoDownSlow;
    go->GoLeft = GoLeftSlow;
    go->GoRight = GoRightSlow;
}

typedef struct World_ {
    GameObject *player;
} World;

World* NewWorld() {
    World *world = malloc(sizeof(World));
    return world;
}

void DrawWorld(const World* w) {
    terminal_put(w->player->x, w->player->y, w->player->tile);
    terminal_put(5,5,'%');
    terminal_put(10,10,'*');
}

void ApplyMovement(GameObject* go, int code) {
    if (code == TK_W) {
        go->GoUp(go);
    }
    if (code == TK_S) {
        go->GoDown(go);
    }
    if (code == TK_A) {
        go->GoLeft(go);
    }
    if (code == TK_D) {
        go->GoRight(go);
    }
}

void loop(World* world, int code) {
    GameObject* p = world->player;
    
    ApplyMovement(p, code);
    
    if (p->x == 5 && p->y == 5) {
        ShuffleMovement(p);
    }
    if (p->x == 10 && p->y == 10) {
        NormalizeMovement(p);
    }

    DrawWorld(world);
}

int main() {
    World* world = NewWorld();
    world->player = NewPlayer();

    terminal_open();
    
    DrawWorld(world);    
    terminal_refresh();

    while (1) {
        int code = terminal_read();
        terminal_clear();
        
        if (code == TK_CLOSE) {
            break;
        }

        loop(world, code);
        terminal_refresh();
    }
  
    terminal_close();
}
```
