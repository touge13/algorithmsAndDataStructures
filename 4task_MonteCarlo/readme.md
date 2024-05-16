
# Монте-Карло

## Условие задачи
Вычисление какого-либо определённого интеграла или математической константы (например, π) при помощи метода Монте-Карло.

Реализуйте и испытайте
Программа должна получать в качестве параметра командной строки количество потоков.

Измерьте скорость работы программы для достижения N точек.
Многократно запустив подсчёт с заданным количеством точек убедитесь, что справедлива данная оценка (https://dluciv.github.io/algs_and_data_structs-spbu-CB.5001/slides.html?md=b5.02.randomized#/3/8).

## Результаты
```
admin@MacBook-ProMisa 4task_MonteCarlo %  g++ -o main main.cpp -pthread -std=c++17
./main 2
```
```
Integral estimate: 0.63638. (Истинное значение интеграла функции sin(pi * x) на [0, 1] равно 2/pi = 0.6366...)
Left-hand side of the inequality: 1
Right-hand side of the inequality: 1
The inequality is satisfied.
Execution time with 2 threads and 50000 points per thread: 0.0183125 seconds
```
```
admin@MacBook-ProMisa 4task_MonteCarlo %  g++ -o main main.cpp -pthread -std=c++17
./main 100
```
```
Integral estimate: 0.63724. (Истинное значение интеграла функции sin(pi * x) на [0, 1] равно 2/pi = 0.6366...)
Left-hand side of the inequality: 1
Right-hand side of the inequality: 1
The inequality is satisfied.
Execution time with 100 threads and 1000 points per thread: 0.0147978 seconds
```
