#include "SimpleDynamicArray.h"
#include <iostream>  // для print()
#include <algorithm> // для std::copy (в конструкторе копирования)

using namespace std;

namespace SimpleDynamicArrayNS {

    // Конструктор (создаёт пустой массив)
    SimpleDynamicArray::SimpleDynamicArray()
        : data(nullptr), size(0), capacity(0) {
    }

    // Деструктор (освобождает память)
    SimpleDynamicArray::~SimpleDynamicArray() {
        delete[] data;
    }

    // Конструктор копирования (создаёт копию другого массива)
    SimpleDynamicArray::SimpleDynamicArray(const SimpleDynamicArray& other)
        : data(new int[other.capacity]), size(other.size), capacity(other.capacity) {
        copy(other.data, other.data + size, data); // Копируем элементы
    }

    // Оператор присваивания (копирует данные из другого массива)
    SimpleDynamicArray& SimpleDynamicArray::operator=(const SimpleDynamicArray& other) {
        if (this != &other) { // Защита от самоприсваивания
            delete[] data;
            data = new int[other.capacity];
            size = other.size;
            capacity = other.capacity;
            copy(other.data, other.data + size, data);
        }
        return *this;
    }

    // Получить элемент по индексу (без проверки границ)
    int SimpleDynamicArray::at(size_t index) const {
        if (index >= size) {
            return -1;
        }
        return *(data + index); // Аналог data[index], но без оператора []
    }

    // Текущее количество элементов
    size_t SimpleDynamicArray::get_size() const {
        return size;
    }

    // Добавить элемент в конец
    void SimpleDynamicArray::push_back(int value) {
        if (size >= capacity) { // Если места нет — увеличиваем массив
            size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
            int* new_data = new int[new_capacity];

            // Копируем старые элементы
            for (size_t i = 0; i < size; ++i) {
                *(new_data + i) = *(data + i);
            }

            delete[] data;     // Освобождаем старую память
            data = new_data;   // Переключаемся на новый массив
            capacity = new_capacity;
        }

        *(data + size) = value; // Добавляем элемент
        size++;
    }

    // Добавить элемент в начало (со сдвигом всех элементов вправо)
    void SimpleDynamicArray::push_front(int value) {
        if (size >= capacity) { // Увеличиваем массив, если нужно
            size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
            int* new_data = new int[new_capacity];

            // Сначала кладём новый элемент, затем старые
            *new_data = value;
            for (size_t i = 0; i < size; ++i) {
                *(new_data + i + 1) = *(data + i);
            }

            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
        else {
            // Сдвигаем все элементы вправо
            for (size_t i = size; i > 0; --i) {
                *(data + i) = *(data + i - 1);
            }
            *data = value; // Записываем новый элемент в начало
        }
        size++;
    }

    // Вставить элемент в произвольную позицию
    void SimpleDynamicArray::insert(size_t index, int value) {
        if (index > size) {
            cout << "Index out of range\n";
            return;
        }

        if (size >= capacity) { // Увеличиваем массив, если нужно
            size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
            int* new_data = new int[new_capacity];

            // Копируем элементы до индекса
            for (size_t i = 0; i < index; ++i) {
                *(new_data + i) = *(data + i);
            }

            // Вставляем новый элемент
            *(new_data + index) = value;

            // Копируем оставшиеся элементы
            for (size_t i = index; i < size; ++i) {
                *(new_data + i + 1) = *(data + i);
            }

            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
        else {
            // Сдвигаем элементы вправо, начиная с конца
            for (size_t i = size; i > index; --i) {
                *(data + i) = *(data + i - 1);
            }
            *(data + index) = value; // Вставляем элемент
        }
        size++;
    }

    // Удалить последний элемент
    void SimpleDynamicArray::pop_back() {
        if (size == 0) {
            cout << "Array is empty\n";
            return;
        }
        size--; // Просто уменьшаем размер (память не освобождаем)
    }

    // Удалить первый элемент (со сдвигом всех элементов влево)
    void SimpleDynamicArray::pop_front() {
        if (size == 0) {
            cout << "Array is empty\n";
            return;
        }

        for (size_t i = 0; i < size - 1; ++i) {
            *(data + i) = *(data + i + 1); // Сдвигаем все элементы влево
        }
        size--;
    }

    // Удалить элемент по индексу
    void SimpleDynamicArray::pop_out(size_t index) {
        if (index >= size) {
            cout << "Index out of range\n";
            return;
        }

        for (size_t i = index; i < size - 1; ++i) {
            *(data + i) = *(data + i + 1); // Сдвигаем элементы влево
        }
        size--;
    }

    // Объединить два массива
    void SimpleDynamicArray::concatenate(const SimpleDynamicArray& other) {
        size_t new_size = size + other.size;

        if (new_size > capacity) { // Если места мало — увеличиваем массив
            size_t new_capacity = new_size;
            int* new_data = new int[new_capacity];

            // Копируем текущие элементы
            for (size_t i = 0; i < size; ++i) {
                *(new_data + i) = *(data + i);
            }

            // Копируем элементы из другого массива
            for (size_t i = 0; i < other.size; ++i) {
                *(new_data + size + i) = *(other.data + i);
            }

            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
        else {
            // Просто добавляем элементы другого массива
            for (size_t i = 0; i < other.size; ++i) {
                *(data + size + i) = *(other.data + i);
            }
        }
        size = new_size;
    }

    // Заменить элемент по индексу
    void SimpleDynamicArray::replace(size_t index, int value) {
        if (index >= size) {
            cout << "Index out of range\n";
            return;
        }
        *(data + index) = value;
    }

    // Поменять местами два элемента
    void SimpleDynamicArray::swap(size_t index1, size_t index2) {
        if (index1 >= size || index2 >= size) {
            cout << "Index out of range\n";
            return;
        }
        int temp = *(data + index1);
        *(data + index1) = *(data + index2);
        *(data + index2) = temp;
    }

    // Вывести массив в консоль
    void SimpleDynamicArray::print() const {
        std::cout << "[ ";
        for (size_t i = 0; i < size; ++i) {
            std::cout << *(data + i) << " ";
        }
        std::cout << "]" << std::endl;
    }

}