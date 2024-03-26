#ifndef ARITHMETIC_H
#define ARITHMETIC_H
#include <string>

class Binary {
 public:
  // Инициализация объекта класса Binary с десятичным числом
  Binary(int num) : num_(num) {}

  // Перевод десятичного числа в двоичный код
  std::string to_binary() const;

  // Перевод двоичного кода в десятичное число
  int to_decimal(const std::string& binary) const;

  // Операторы
  Binary operator+(const Binary& other) const;
  Binary operator-(const Binary& other) const;
  Binary operator*(const Binary& other) const;
  Binary operator/(const Binary& other) const;

 private:
  int num_; // Десятичное представление числа
};
#endif // ARITHMETIC_H