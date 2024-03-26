#include <iostream>
#include "arithmetic.h"
#include "visualization.cpp"

int main() {
  int input1, input2;

  // Ввод чисел
  std::cout << "Введите первое число: ";
  std::cin >> input1;
  std::cout << "Введите второе число: ";
  std::cin >> input2;

  // Визуализация
  visualization(input1, input2);

  // Тестовые вызовы
  visualization(6, 8);
  visualization(0, -10);
  visualization(-14, -7);

  return 0;
}
