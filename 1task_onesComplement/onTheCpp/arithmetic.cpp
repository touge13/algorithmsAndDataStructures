#include "arithmetic.h"

#include <bitset>

std::string Binary::to_binary() const {
    std::bitset<8> binary(num_); // Преобразование числа в битовую строку
    return binary.to_string();
}

int Binary::to_decimal(const std::string& binary) const {
    std::bitset<8> bits(binary); // Преобразование битовой строки в битовый набор
    return static_cast<int>(bits.to_ulong());
}

Binary Binary::operator+(const Binary& other) const {
    int decimal_sum = num_ + other.num_;
    return Binary(decimal_sum);
}

Binary Binary::operator-(const Binary& other) const {
    int decimal_diff = num_ - other.num_;
    return Binary(decimal_diff);
}

Binary Binary::operator*(const Binary& other) const {
    int decimal_prod = num_ * other.num_;
    return Binary(decimal_prod);
}

Binary Binary::operator/(const Binary& other) const {
    int decimal_div = num_ / other.num_;
    return Binary(decimal_div);
}