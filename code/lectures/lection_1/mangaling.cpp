/**
 * Проверить мангалинг можно
 * nm a.out
 * objdump -d a.out
 *
 */

// Будет __Z3maxdd
int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

// Будет __Z3maxii
double max(double a, double b) {
  if (a > b) {
    return a;
  }
  return b;
}

extern "C" {  // "отключает" мангалинг
// Будет _max
char max(char a, char b) {
  if (a > b) {
    return a;
  }
  return b;
}
}

int main() {
  int i = max(1, 42);
  int d = max(2.01, 3.14);
  char c = max('a', 'b');
  return 0;
}
