#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

// Функция для создания матрицы и заполнения ее рандомными числами
std::vector<std::vector<int>> createRandomMatrix(int rows, int cols) {
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    static bool seeded = false;
    if (!seeded) {
        srand(42); // Используем один и тот же seed
        seeded = true;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 100; // заполняем случайными числами от 0 до 99
        }
    }
    return matrix;
}

// Функция для суммирования элементов матрицы по строкам
int sumRows(const std::vector<std::vector<int>>& matrix) {
    int rowSums = 0;
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            rowSums += matrix[i][j];
        }
    }
    return rowSums;
}

// Функция для суммирования элементов матрицы по столбцам
int sumCols(const std::vector<std::vector<int>>& matrix) {
    int colSums = 0;
    for (size_t j = 0; j < matrix[0].size(); ++j) {
        for (size_t i = 0; i < matrix.size(); ++i) {
            colSums += matrix[i][j];
        }
    }
    return colSums;
}

int main() {
    int rows = 1000;
    int cols = 1000;

    // Создаем матрицу и заполняем ее случайными числами
    std::vector<std::vector<int>> matrix = createRandomMatrix(rows, cols);

    // Измеряем время выполнения функции sumRows
    auto startRow = std::chrono::high_resolution_clock::now();
    int rowSumResult = sumRows(matrix);
    auto endRow = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> rowDuration = endRow - startRow;

    // Измеряем время выполнения функции sumCols
    auto startCol = std::chrono::high_resolution_clock::now();
    int colSumResult = sumCols(matrix);
    auto endCol = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> colDuration = endCol - startCol;

    std::cout << "\nRow sums: " << rowSumResult << " Time: " << rowDuration.count() << " milliseconds\n";
    std::cout << "Column sums: " << colSumResult << " Time: " << colDuration.count() << " milliseconds\n";

    return 0;
}
