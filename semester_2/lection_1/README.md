# Что нового в с++ по сравнению с Си

- stl
- bool
- Перегрузка функций!!!!

```cpp
int min(int a, int b) {
    if ( a < b) return a;
    return b;
}
float min(float a, float b);
char min(char a, char b);
```

- вместо printf и scanf БУДТ cout и cin
- namespace
- появились СТРОКИ string
- появились ССЫЛКИ!
- ультрахардкорная магия на ссылках ИЛИ rvalue, lvalue, rvalue-ref, lvalue-ref
- move семантика
- появились классы
