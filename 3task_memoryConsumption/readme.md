Характеристики ПК:
- **RAM:** 16 gb 1867 MHz DDR3
- **macOS:** Monterey 12.6.7

Запустим программу на macOS и посмотрим результаты в "Мониторинге системы"
- **На чтение:** 
```
cd "../3task_memoryConsumption/" && g++ main.cpp -o main && "../3task_memoryConsumption/"main 1000 read
```
![alt text](image-read.png)

-  **На запись:** 
```
cd "../3task_memoryConsumption/" && g++ main.cpp -o main && "../3task_memoryConsumption/"main 1000 write
```
![alt text](image-write.png)