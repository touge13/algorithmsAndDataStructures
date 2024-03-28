#include <iostream>
#include <bitset>

// Класс для работы с двоичными числами
template<size_t length>
class BinaryNumber {
private:
    std::bitset<length> value;
public:
    // Геттер
    std::bitset<length> getValue() const {
        return value;
    }
    // Конструкторы
    BinaryNumber() : value(0) {} // Конструктор по умолчанию инициализирует значение нулем
    // Конструктор инициализации значения переданным целым числом
    BinaryNumber(int num) {
        if (num < 0) {
            value = std::bitset<length>(-num).flip(); // Преобразуем отрицательное число в положительное и получаем обратный код
        } else {
            value = std::bitset<length>(num);
        }
    } 
    BinaryNumber(std::bitset<length> num) : value(num) {} // Конструктор инициализации значения переданным двоичным числом

    // Метод для преобразования двоичного числа в десятичное
    int toDecimal() const {
        std::string binary = value.to_string(); // Преобразуем двоичное число в строку
        bool isNegative = false;

        if (binary[0] == '1') {
            isNegative = true;
            for (char& bit : binary) {
                bit = (bit == '1') ? '0' : '1'; // Инвертируем биты
            }
        }

        int decimalValue = 0;
        for (int i = 0; i < length; i++) {
            decimalValue += (binary[length - 1 - i] - '0') * (1 << i); // Преобразуем двоичное число в десятичное
        }

        if (isNegative) {
            decimalValue = -decimalValue;
        }

        return decimalValue;
    }

    // Перегрузка операторов
    BinaryNumber operator+(const BinaryNumber& other) {
        std::bitset<length> result = value ^ other.value;
        std::bitset<length> carry = (value & other.value) << 1;

        while (carry != 0) {
            std::bitset<length> temp = result;
            result = result ^ carry;
            carry = (temp & carry) << 1;
        }
        return BinaryNumber(result);
    }

    BinaryNumber operator-(const BinaryNumber& other) {
        std::bitset<length> invertedOther = ~other.value;
        std::bitset<length> result = value ^ invertedOther;
        std::bitset<length> carry = (value & invertedOther) << 1;

        while (carry != 0) {
            std::bitset<length> temp = result;
            result = result ^ carry;
            carry = (temp & carry) << 1;
        }
        return BinaryNumber(result);
    }

    BinaryNumber operator*(const BinaryNumber& other) {
        int result = toDecimal() * other.toDecimal();
        return BinaryNumber(result);
    }

    BinaryNumber operator/(const BinaryNumber& other) {
        int result = toDecimal() / other.toDecimal();
        return BinaryNumber(result);
    }

    // Перегрузка оператора вывода в поток
    friend std::ostream& operator<<(std::ostream& os, const BinaryNumber& num) {
        os << num.value;
        return os;
    }
};