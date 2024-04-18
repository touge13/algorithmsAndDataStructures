#include "../include/visualization.h"
#include "../include/arithmetic.h"

void visualization(int num1_dec, int num2_dec) {
    std::cout << "------------------------------------------test {" << num1_dec << ", " << num2_dec << "}------------------------------------------------------" << std::endl;
    
    const size_t length = 8;
    BinaryNumber<length> num1(num1_dec);
    BinaryNumber<length> num2(num2_dec);

    std::bitset<length> binary_num1 = num1.getValue();
    std::bitset<length> binary_num2 = num2.getValue();

    std::cout << "Первое число в двоичном коде: " << binary_num1 << std::endl;
    std::cout << "Второе число в двоичном коде: " << binary_num2 << std::endl;

    BinaryNumber<length> sum = num1 + num2;
    BinaryNumber<length> difference = num1 - num2;
    BinaryNumber<length> product = num1 * num2;
    BinaryNumber<length> quotient = num1 / num2;

    std::cout << "Сумма чисел в двоичном коде: " << sum << ", в десятичной системе счисления: " << num1_dec + num2_dec << std::endl;
    std::cout << "Разность чисел в двоичном коде: " << difference << ", в десятичной системе счисления: " << num1_dec - num2_dec << std::endl;
    std::cout << "Произведение чисел в двоичном коде: " << product << ", в десятичной системе счисления: " << num1_dec * num2_dec << std::endl;
    std::cout << "Частное чисел в двоичном коде: " << quotient << ", в десятичной системе счисления: " << num1_dec / num2_dec << std::endl;
}
