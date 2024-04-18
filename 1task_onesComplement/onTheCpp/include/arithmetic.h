#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include <iostream>
#include <bitset>

template<size_t length>
class BinaryNumber {
private:
    std::bitset<length> value;
public:
    std::bitset<length> getValue() const {
        return value;
    }

    BinaryNumber() : value(0) {}

    BinaryNumber(int num) {
        if (num < 0) {
            value = std::bitset<length>(-num).flip();
        } else {
            value = std::bitset<length>(num);
        }
    }

    BinaryNumber(std::bitset<length> num) : value(num) {}

    BinaryNumber operator+(const BinaryNumber& other) const {
        std::bitset<length> sum = value.to_ulong() + other.value.to_ulong();
        return BinaryNumber(sum);
    }

    BinaryNumber operator-(const BinaryNumber& other) const {
        std::bitset<length> inverted_other = other.value;
        for (size_t i = 0; i < length; ++i) {
            inverted_other.flip(i);
        }
        std::bitset<length> diff = value.to_ulong() + inverted_other.to_ulong();
        return BinaryNumber(diff);
    }

    BinaryNumber operator*(const BinaryNumber& other) const {
        std::bitset<length> product = value.to_ulong() * other.value.to_ulong();
        return BinaryNumber(product);
    }

    BinaryNumber operator/(const BinaryNumber& other) const {
        std::bitset<length> quotient = value.to_ulong() / other.value.to_ulong();
        return BinaryNumber(quotient);
    }

    friend std::ostream& operator<<(std::ostream& os, const BinaryNumber& num) {
        os << num.value;
        return os;
    }
};

#endif
