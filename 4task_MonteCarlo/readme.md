
# Монте-Карло

## Условие задачи
Вычисление какого-либо определённого интеграла или математической константы (например, π) при помощи метода Монте-Карло.

Реализуйте и испытайте
Программа должна получать в качестве параметра командной строки количество потоков.

Измерьте скорость работы программы для достижения N точек.
Многократно запустив подсчёт с заданным количеством точек убедитесь, что справедлива данная оценка (https://dluciv.github.io/algs_and_data_structs-spbu-CB.5001/slides.html?md=b5.02.randomized#/3/8).

## Результаты
```
admin@MacBook-ProMisa 4task_MonteCarlo % g++ -o main main.cpp -pthread -std=c++11
./main 1  
```
Left-hand side of the inequality: 1
Right-hand side of the inequality: 1
Execution time with 1 threads and 100000 points per thread: 0.028873 seconds
The inequality is satisfied.

```
admin@MacBook-ProMisa 4task_MonteCarlo % g++ -o main main.cpp -pthread -std=c++11
./main 100
```
Left-hand side of the inequality: 1
Right-hand side of the inequality: 1
Execution time with 100 threads and 1000 points per thread: 0.0135475 seconds
The inequality is satisfied.