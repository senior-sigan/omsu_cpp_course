#include <stdio.h>

int main(void) {
  // двухмерные массивы - матрицы
  // на самом деле лежат в памяти одним куском подряд
  // а не "магически" в 2д
  // НО!!!! их нельзя передавать как двойной указатель
  // Почему? потому что двойной указатель - это массив указателей,
  // которые ссылаются на другие непрерывные куски памяти
  // а у нас ОДИН непрерывный кусок, аккуратно нарезанный
  int m[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  printf("%d", *(m + 8));
  return 0;
}