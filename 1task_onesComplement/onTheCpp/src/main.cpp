#include <iostream>
#include "../include/visualization.h"

int main() {
    int num1_dec, num2_dec;
    std::cout << "Введите первое число (в десятичной системе счисления): ";
    std::cin >> num1_dec;

    std::cout << "Введите второе число (в десятичной системе счисления): ";
    std::cin >> num2_dec;

    visualization(num1_dec, num2_dec);
    
    // Пару тестиков
    visualization(6, 8);
    visualization(0, -10);
    visualization(-14, -7);

    return 0;
}
