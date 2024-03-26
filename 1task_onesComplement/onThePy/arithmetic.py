class Binary:
    #инициализируем введенные цифры
    def __init__(self, num):
        self.num = num

    #переводим введенное число из десятичнной системы счисления
    # в 8-ми разрядный двоичный код
    def to_binary(self):
        binary_list = []
        temp1 = self.num
        temp2 = self.num
        
        if temp2 < 0:
            temp2 = -temp2
        while temp2 > 0:
            binary_list.insert(0, str(temp2 % 2))
            temp2 = temp2 // 2
        while len(binary_list) < 8:
            binary_list.insert(0, '0')
        
        #реализуем обратный код, если введенное число отрицательное
        if temp1 < 0:
            for bit in range(len(binary_list)):
                if binary_list[bit] == '1':
                    binary_list[bit] = '0'
                elif binary_list[bit] == '0':
                    binary_list[bit] = '1'
        
        #собираем все наши значения битов в двоичный код
        binary = ''.join(binary_list)
        return binary

    #перевод двоичного кода в десятичную систему счисления
    def to_decimal(self, binary):
        binary_list = [i for i  in binary]
        flag = 0 #флаг для проверки знака числа
        if self.num < 0:
            flag = 1
            for bit in range(len(binary_list)):
                if binary_list[bit] == '1':
                    binary_list[bit] = '0'
                elif binary_list[bit] == '0':
                    binary_list[bit] = '1'
        #собираем все наши значения битов в двоичный код
        binary = ''.join(binary_list)

        decimal = 0
        for i in range(len(binary)):
            decimal += int(binary[-(i + 1)]) * 2 ** i
        
        if flag == 1:
            decimal = -decimal
        return decimal

    #сложение
    def __add__(self, other):
        decimal_sum = self.to_decimal(self.to_binary()) + other.to_decimal(other.to_binary())
        return Binary(decimal_sum)

    #разность
    def __sub__(self, other):
        decimal_diff = self.to_decimal(self.to_binary()) - other.to_decimal(other.to_binary())
        return Binary(decimal_diff)

    #произведение
    def __mul__(self, other):
        decimal_prod = self.to_decimal(self.to_binary()) * other.to_decimal(other.to_binary())
        return Binary(decimal_prod)

    #частное
    def __truediv__(self, other):
        decimal_div = self.to_decimal(self.to_binary()) // other.to_decimal(other.to_binary())
        return Binary(decimal_div)

    #преобразовываем объект в строку
    def __str__(self):
        return self.to_binary()
