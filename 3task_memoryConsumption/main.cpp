#include <iostream>
#include <chrono>
#include <thread>

const size_t MEMORY_SIZE = 3ULL * 1024 * 1024 * 1024; // Выделение 3 ГБ памяти
const size_t PAGE_SIZE = 4 * 1024; // Размер страницы 4 КБ

volatile char* memory = nullptr;

void readMemoryWithDelay(size_t delayPages) {
    for (size_t i = 0; i < MEMORY_SIZE / PAGE_SIZE; ++i) {
        if (i % delayPages == 0) {
            // Задержка для контроля роста потребления памяти
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        // Чтение из памяти с шагом 4 КБ
        volatile char value = memory[i * PAGE_SIZE];

        if (value == 0) {
            std::cout << "Read value: " << static_cast<int>(value) << std::endl;
        }
    }
}

void writeMemoryWithDelay(size_t delayPages) {
    for (size_t i = 0; i < MEMORY_SIZE / PAGE_SIZE; ++i) {
        if (i % delayPages == 0) {
            // Задержка для контроля роста потребления памяти
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        // Запись в память с шагом 4 КБ
        memory[i * PAGE_SIZE] = '@'; // Записываем символ '@'
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <delayPages> <mode>" << std::endl;
        std::cerr << "Mode: 'read' or 'write'" << std::endl;
        return 1;
    }

    int delayPages = std::atoi(argv[1]);
    std::string mode(argv[2]);

    // Выделение памяти с помощью new (можно также использовать malloc)
    memory = new (std::nothrow) volatile char[MEMORY_SIZE];
    if (!memory) {
        std::cerr << "Failed to allocate memory." << std::endl;
        return 1;
    }

    // Доступ к выделенной памяти с заданной задержкой
    if (mode == "write") {
        writeMemoryWithDelay(delayPages);
    } else if (mode == "read") {
        readMemoryWithDelay(delayPages);
    }

    // Освобождение памяти
    delete[] memory;
    return 0;
}
