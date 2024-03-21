from arithmetic import Binary

def tests(input1, input2):
    print(f"------------------------------------------test {input1, input2}------------------------------------------------------")

    num1 = Binary(input1)
    num2 = Binary(input2)
    binary_num1 = num1.to_binary()
    binary_num2 =num2.to_binary()

    print(f"Первое число в двоичном коде: {binary_num1}")
    print(f"Второе число в двоичном коде: {binary_num2}")

    print(f"Сумма чисел в двоичном коде: {num1 + num2}, в десятичной системе счисления: {num1.to_decimal(binary_num1) + num2.to_decimal(binary_num2)}")
    print(f"Разность чисел в двоичном коде: {num1 - num2}, в десятичной системе счисления: {num1.to_decimal(binary_num1) - num2.to_decimal(binary_num2)}")
    print(f"Произведение чисел в двоичном коде: {num1 * num2}, в десятичной системе счисления: {num1.to_decimal(binary_num1) * num2.to_decimal(binary_num2)}")
    print(f"Частное чисел в двоичном коде: {num1 / num2}, в десятичной системе счисления: {num1.to_decimal(binary_num1) // num2.to_decimal(binary_num2)}")

