#include <iostream>
#include "arithmetic.h"

void visualization(int input1, int input2) {
  std::cout << "------------------------------------------test " << input1 << ", " << input2 << "------------------------------------------------------" << std::endl;

  Binary num1(input1);
  Binary num2(input2);
  std::string binary_num1 = num1.to_binary();
  std::string binary_num2 = num2.to_binary();

  std::cout << "Первое число в двоичном коде: " << binary_num1 << std::endl;
  std::cout << "Второе число в двоичном коде: " << binary_num2 << std::endl;

  std::cout << "Сумма чисел в двоичном коде: " << (num1 + num2).to_binary() << ", в десятичной системе счисления: " << num1.to_decimal(binary_num1) + num2.to_decimal(binary_num2) << std::endl;
  std::cout << "Разность чисел в двоичном коде: " << (num1 - num2).to_binary() << ", в десятичной системе счисления: " << num1.to_decimal(binary_num1) - num2.to_decimal(binary_num2) << std::endl;
  std::cout << "Произведение чисел в двоичном коде: " << (num1 * num2).to_binary() << ", в десятичной системе счисления: " << num1.to_decimal(binary_num1) * num2.to_decimal(binary_num2) << std::endl;
  std::cout << "Частное чисел в двоичном коде: " << (num1 / num2).to_binary() << ", в десятичной системе счисления: " << num1.to_decimal(binary_num1) / num2.to_decimal(binary_num2) << std::endl;
}