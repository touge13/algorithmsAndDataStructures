from arithmetic import Binary
from tests import tests

num1 = Binary(int(input("Введите первое число: ")))
num2 = Binary(int(input("Введите второе число: ")))
binary_num1 = num1.to_binary()
binary_num2 =num2.to_binary()

print(f"Первое число в двоичном коде: {binary_num1}")
print(f"Второе число в двоичном коде: {binary_num2}")

print(f"Сумма чисел в двоичном коде: {num1 + num2}, в десятичной системе счисления: {num1.to_decimal(binary_num1) + num2.to_decimal(binary_num2)}")
print(f"Разность чисел в двоичном коде: {num1 - num2}, в десятичной системе счисления: {num1.to_decimal(binary_num1) - num2.to_decimal(binary_num2)}")
print(f"Произведение чисел в двоичном коде: {num1 * num2}, в десятичной системе счисления: {num1.to_decimal(binary_num1) * num2.to_decimal(binary_num2)}")
print(f"Частное чисел в двоичном коде: {num1 / num2}, в десятичной системе счисления: {num1.to_decimal(binary_num1) // num2.to_decimal(binary_num2)}")

#выведем пару тестов
tests(6, 8)
tests(0, -10)
tests(-14, -7)