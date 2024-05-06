#include <iostream>
#include <cmath>
#include <thread>
#include <vector>
#include <chrono>
#include <random>
#include <atomic>
#include <algorithm>

// Функция для вычисления значения функции f(x) = sin(πx)
double function(double x) {
    return sin(M_PI * x);
}

// Функция для вычисления интеграла методом Монте-Карло на отрезке [a, b] с N точками
double monte_carlo_integration(double a, double b, int N) {
    int count_inside = 0;

    // Генерация случайных точек и подсчёт количества точек, попадающих под кривую
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<double> distribution(a, b);
    for (int i = 0; i < N; ++i) {
        double x = distribution(generator); // Генерация случайной точки x на [a, b]
        double y = distribution(generator); // Генерация случайной точки y на [a, b]

        if (y <= function(x)) {
            count_inside++;
        }
    }

    // Оценка значения интеграла
    double integral_estimate = (double)count_inside / N * (b - a);
    return integral_estimate;
}

// Функция для запуска вычислений в нескольких потоках
void calculate_with_threads(int num_threads, int num_points_per_thread) {
    std::vector<std::thread> threads;
    std::atomic<int> satisfying_count(0);

    auto start_time = std::chrono::high_resolution_clock::now();

    double D_V = 1.0; // Объем области интегрирования [0, 1]
    double epsilon = 0.001; // Пример значения epsilon для оценки неравенства

    // Создание потоков для параллельных вычислений
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back([num_points_per_thread, &satisfying_count, D_V, num_threads, epsilon]() {
            // Выполняем вычисления в текущем потоке
            double integral_estimate = monte_carlo_integration(0.0, 1.0, num_points_per_thread);

            // Проверяем условие неравенства
            int K = static_cast<int>(integral_estimate * D_V); // K как количество точек под функцией
            if (std::abs(integral_estimate / D_V - K / num_threads) >= epsilon) {
                satisfying_count.fetch_add(1, std::memory_order_relaxed);
            }
        });
    }

    // Ожидание завершения всех потоков
    for (auto& thread : threads) {
        thread.join();
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end_time - start_time;

    // Вычисляем вероятность выполнения неравенства
    double probability = (double)satisfying_count.load(std::memory_order_relaxed) / num_threads;

    // Вычисляем integral_estimate после завершения всех вычислений
    double integral_estimate = monte_carlo_integration(0.0, 1.0, num_threads * num_points_per_thread);

    // Вычисляем правую часть неравенства с использованием std::min
    double right_hand_side = std::min(1.0, (integral_estimate * (D_V - integral_estimate)) /
                            (num_threads * num_points_per_thread * epsilon * epsilon * D_V * D_V));

    // Вывод результатов
    std::cout << "Left-hand side of the inequality: " << probability << std::endl;
    std::cout << "Right-hand side of the inequality: " << right_hand_side << std::endl;
    // Проверяем выполнение неравенства
    if (probability <= right_hand_side) {
        std::cout << "The inequality is satisfied." << std::endl;
    } else {
        std::cout << "The inequality is not satisfied." << std::endl;
    }

    std::cout << "Execution time with " << num_threads << " threads and " << num_points_per_thread << " points per thread: "
              << elapsed_seconds.count() << " seconds" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <num_threads>" << std::endl;
        return 1;
    }

    int num_threads = std::stoi(argv[1]);
    int num_points_per_thread = 100000 / num_threads; // Распределение точек между потоками

    if (num_threads <= 0) {
        std::cerr << "Invalid number of threads." << std::endl;
        return 1;
    }

    // Выполнение вычислений с заданным количеством потоков и точек
    calculate_with_threads(num_threads, num_points_per_thread);

    return 0;
}
