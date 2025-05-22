#include "PointersArray.h"
#include <iostream>


using namespace std;

namespace PointersArrayNS {

    // Конструктор (пустой массив)
    PointersArray::PointersArray()
        : data(nullptr), size(0), capacity(0) {
    }

    // Деструктор (освобождаем память)
    PointersArray::~PointersArray() {
        for (size_t i = 0; i < size; ++i) {
            delete data[i]; // Удаляем каждый int*
        }
        delete[] data;     // Удаляем массив указателей
    }

    // Конструктор копирования (глубокая копия)
    PointersArray::PointersArray(const PointersArray& other)
        : data(new int* [other.capacity]), size(other.size), capacity(other.capacity) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = new int(*other.data[i]); // Копируем значения
        }
    }

    // Оператор присваивания
    PointersArray& PointersArray::operator=(const PointersArray& other) {
        if (this != &other) {
            // Очищаем текущие данные
            for (size_t i = 0; i < size; ++i) {
                delete data[i];
            }
            delete[] data;

            // Копируем новые данные
            capacity = other.capacity;
            size = other.size;
            data = new int* [capacity];
            for (size_t i = 0; i < size; ++i) {
                data[i] = new int(*other.data[i]);
            }
        }
        return *this;
    }

    // Получить значение по индексу
    int PointersArray::at(size_t index) const {
        if (index >= size) {
            cout << "Index out of range\n";
            return -1;
        }
        return *data[index]; // Разыменовываем указатель
    }

    // Текущий размер массива
    size_t PointersArray::get_size() const {
        return size;
    }

    // Добавить указатель в конец
    void PointersArray::push_back(int* value) {
        if (size >= capacity) {
            size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
            int** new_data = new int* [new_capacity];

            // Копируем старые указатели
            for (size_t i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }

            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
        data[size] = value; // Сохраняем указатель
        size++;
    }

    // Добавить указатель в начало
    void PointersArray::push_front(int* value) {
        if (size >= capacity) {
            size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
            int** new_data = new int* [new_capacity];

            // Сначала новый элемент, затем старые
            new_data[0] = value;
            for (size_t i = 0; i < size; ++i) {
                new_data[i + 1] = data[i];
            }

            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
        else {
            // Сдвигаем элементы вправо
            for (size_t i = size; i > 0; --i) {
                data[i] = data[i - 1];
            }
            data[0] = value;
        }
        size++;
    }

    // Вставить указатель по индексу
    void PointersArray::insert(size_t index, int* value) {
        if (index > size) {
            cout << "Index out of range\n";
            return;
        }

        if (size >= capacity) {
            size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
            int** new_data = new int* [new_capacity];

            // Копируем элементы до индекса
            for (size_t i = 0; i < index; ++i) {
                new_data[i] = data[i];
            }

            // Вставляем новый элемент
            new_data[index] = value;

            // Копируем остальные
            for (size_t i = index; i < size; ++i) {
                new_data[i + 1] = data[i];
            }

            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
        else {
            // Сдвигаем элементы вправо
            for (size_t i = size; i > index; --i) {
                data[i] = data[i - 1];
            }
            data[index] = value;
        }
        size++;
    }

    // Удалить последний элемент (без освобождения памяти int*)
    void PointersArray::pop_back() {
        if (size == 0) {
            cout << "Array is empty\n";
            return;
        }
        size--;
    }

    // Удалить первый элемент
    void PointersArray::pop_front() {
        if (size == 0) {
            cout << "Array is empty\n";
            return;
        }

        // Сдвигаем все элементы влево
        for (size_t i = 0; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        size--;
    }

    // Удалить элемент по индексу
    void PointersArray::pop_out(size_t index) {
        if (index >= size) {
            cout << "Index out of range\n";
            return;
        }

        // Сдвигаем элементы влево
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        size--;
    }

    // Объединить два массива указателей
    void PointersArray::concatenate(const PointersArray& other) {
        size_t new_size = size + other.size;

        if (new_size > capacity) {
            size_t new_capacity = new_size;
            int** new_data = new int* [new_capacity];

            // Копируем текущие элементы
            for (size_t i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }

            // Копируем элементы из другого массива
            for (size_t i = 0; i < other.size; ++i) {
                new_data[size + i] = other.data[i];
            }

            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
        else {
            // Просто добавляем элементы
            for (size_t i = 0; i < other.size; ++i) {
                data[size + i] = other.data[i];
            }
        }
        size = new_size;
    }

    // Заменить указатель по индексу
    void PointersArray::replace(size_t index, int* value) {
        if (index >= size) {
            cout << "Index out of range\n";
            return;
        }
        data[index] = value;
    }

    // Поменять два указателя местами
    void PointersArray::swap(size_t index1, size_t index2) {
        if (index1 >= size || index2 >= size) {
            cout << "Index out of range\n";
            return;
        }
        int* temp = data[index1];
        data[index1] = data[index2];
        data[index2] = temp;
    }

    // Вывести массив в консоль
    void PointersArray::print() const {
        std::cout << "[ ";
        for (size_t i = 0; i < size; ++i) {
            std::cout << *data[i] << " "; // Разыменовываем указатель
        }
        std::cout << "]" << std::endl;
    }

} // namespace PointersArrayNS