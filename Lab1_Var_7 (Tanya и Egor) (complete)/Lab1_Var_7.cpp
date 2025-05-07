//Selection Sort + Merge Sort
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;

//Значения для диапазона чисел minValue - минимальное, maxValue - максимальное (от minValue до maxValue)
const int minValue = 0;
const int maxValue = 100;

//Блок функций для действий с массивом

// Функция генерации массива
int* generateArray(int length) {
    int* array = new int[length];
    for (int i = 0; i < length; i++) {
        array[i] = minValue + rand() % (maxValue - minValue);
    }
    return array;
}

// Функция копирования массива
int* copyArray(int* src, int length) {
    int* copiedArray = new int[length];
    copy(src, src + length, copiedArray); // Используем std::copy
    return copiedArray;
}

//Функция для переворота массива
void reverseArray(int* arr, int length) {
    for (int i = 0; i < length / 2; ++i) {
        int temp = arr[i];
        arr[i] = arr[length - i - 1];
        arr[length - i - 1] = temp;
    }
}


//Selection sort
void sortN2(int* arr, int length) {
    for (int i = 0; i < length - 1; i++) {
        // Находим минимальный элемент в оставшейся части массива
        int minIndex = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Меняем местами найденный минимальный элемент с текущим
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}


// Блок функций Merge Sort 

// Функция слияния двух отсортированных частей массива
void merge(int* arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // Создаем временные массивы
    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    // Копируем данные
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Слияние
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Добавляем оставшиеся элементы
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Рекурсивная реализация алгоритма
void mergeSortHelper(int* arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        // Рекурсивное разделение
        mergeSortHelper(arr, low, mid);
        mergeSortHelper(arr, mid + 1, high);

        // Слияние
        merge(arr, low, mid, high);
    }
}

// Точка входа для сортировки
void sortNlgN(int* arr, int length) {
    mergeSortHelper(arr, 0, length - 1);
}

//Точка вызова
int main() {
    int length;
    std::cout << "Enter length of array:\n";
    std::cin >> length;

    const int N = 10; // Количество прогонов

    // Переменные для хранения суммарного времени
    double sumOfBestTimeN2 = 0, sumOfWorstTimeN2 = 0, sumOfTimeN2 = 0;
    double sumOfBestTimeNlgN = 0, sumOfWorstTimeNlgN = 0, sumOfTimeNlgN = 0;
    double sumOfBestTimeStd = 0, sumOfWorstTimeStd = 0, sumOfTimeStd = 0;

    for (int i = 0; i < N; i++) {
        // Генерация массива один раз для каждого прогона
        int* arr = generateArray(length);

        // Копии массива для каждой сортировки
        int* arrN2 = copyArray(arr, length);
        int* arrNlgN = copyArray(arr, length);
        int* arrStd = copyArray(arr, length);

        // Измерение времени для sortN2 (Selection sort)
        auto startN2 = chrono::high_resolution_clock::now();
        sortN2(arrN2, length);
        auto endN2 = chrono::high_resolution_clock::now();
        auto timeN2 = chrono::duration_cast<chrono::microseconds>(endN2 - startN2);
        sumOfTimeN2 += timeN2.count();

        // Лучшее время для sortN2 (уже отсортированный массив)
        auto startBestN2 = chrono::high_resolution_clock::now();
        sortN2(arrN2, length);
        auto endBestN2 = chrono::high_resolution_clock::now();
        auto timeBestN2 = chrono::duration_cast<chrono::microseconds>(endBestN2 - startBestN2);
        sumOfBestTimeN2 += timeBestN2.count();

        // Худшее время для sortN2 (перевернутый массив)
        reverseArray(arrN2, length);
        auto startWorstN2 = chrono::high_resolution_clock::now();
        sortN2(arrN2, length);
        auto endWorstN2 = chrono::high_resolution_clock::now();
        auto timeWorstN2 = chrono::duration_cast<chrono::microseconds>(endWorstN2 - startWorstN2);
        sumOfWorstTimeN2 += timeWorstN2.count();

        // Измерение времени для sortNlgN (Merge Sort)
        auto startNlgN = chrono::high_resolution_clock::now();
        sortNlgN(arrNlgN, length);
        auto endNlgN = chrono::high_resolution_clock::now();
        auto timeNlgN = chrono::duration_cast<chrono::microseconds>(endNlgN - startNlgN);
        sumOfTimeNlgN += timeNlgN.count();

        // Лучшее время для sortNlgN (уже отсортированный массив)
        auto startBestNlgN = chrono::high_resolution_clock::now();
        sortNlgN(arrNlgN, length);
        auto endBestNlgN = chrono::high_resolution_clock::now();
        auto timeBestNlgN = chrono::duration_cast<chrono::microseconds>(endBestNlgN - startBestNlgN);
        sumOfBestTimeNlgN += timeBestNlgN.count();

        // Худшее время для sortNlgN (перевернутый массив)
        reverseArray(arrNlgN, length);
        auto startWorstNlgN = chrono::high_resolution_clock::now();
        sortNlgN(arrNlgN, length);
        auto endWorstNlgN = chrono::high_resolution_clock::now();
        auto timeWorstNlgN = chrono::duration_cast<chrono::microseconds>(endWorstNlgN - startWorstNlgN);
        sumOfWorstTimeNlgN += timeWorstNlgN.count();

        // Измерение времени для std::sort
        auto startStd = chrono::high_resolution_clock::now();
        sort(arrStd, arrStd + length);
        auto endStd = chrono::high_resolution_clock::now();
        auto timeStd = chrono::duration_cast<chrono::microseconds>(endStd - startStd);
        sumOfTimeStd += timeStd.count();

        // Лучшее время для std::sort (уже отсортированный массив)
        auto startBestStd = chrono::high_resolution_clock::now();
        sort(arrStd, arrStd + length);
        auto endBestStd = chrono::high_resolution_clock::now();
        auto timeBestStd = chrono::duration_cast<chrono::microseconds>(endBestStd - startBestStd);
        sumOfBestTimeStd += timeBestStd.count();

        // Худшее время для std::sort (перевернутый массив)
        reverseArray(arrStd, length);
        auto startWorstStd = chrono::high_resolution_clock::now();
        sort(arrStd, arrStd + length);
        auto endWorstStd = chrono::high_resolution_clock::now();
        auto timeWorstStd = chrono::duration_cast<chrono::microseconds>(endWorstStd - startWorstStd);
        sumOfWorstTimeStd += timeWorstStd.count();
    }

    // Вычисление среднего времени (в микросекундах)
    double avgTimeN2 = sumOfTimeN2 / N;
    double avgBestTimeN2 = sumOfBestTimeN2 / N;
    double avgWorstTimeN2 = sumOfWorstTimeN2 / N;

    double avgTimeNlgN = sumOfTimeNlgN / N;
    double avgBestTimeNlgN = sumOfBestTimeNlgN / N;
    double avgWorstTimeNlgN = sumOfWorstTimeNlgN / N;

    double avgTimeStd = sumOfTimeStd / N;
    double avgBestTimeStd = sumOfBestTimeStd / N;
    double avgWorstTimeStd = sumOfWorstTimeStd / N;

    // Вывод результатов (в миллисекундах)
    cout << "Selection Sort (sortN2):\n" << "Best Time: " << avgBestTimeN2 / 1000 << "\n" << "Worst Time: " << avgWorstTimeN2 / 1000 << "\n" << "Average Time: " << avgTimeN2 / 1000 << "\n\n";

    cout << "Merge Sort (sortNlgN):\n" << "Best Time: " << avgBestTimeNlgN / 1000 << "\n" << "Worst Time: " << avgWorstTimeNlgN / 1000 << "\n" << "Average Time: " << avgTimeNlgN / 1000 << "\n\n";

    cout << "std::sort:\n" << "Best Time: " << avgBestTimeStd / 1000 << "\n" << "Worst Time: " << avgWorstTimeStd / 1000 << "\n" << "Average Time: " << avgTimeStd / 1000 << "\n";

    return 0;
}