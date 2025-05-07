#ifndef SIMPLE_DYNAMIC_ARRAY_H
#define SIMPLE_DYNAMIC_ARRAY_H

#include <cstddef> // Для size_t

namespace SimpleDynamicArrayNS {

    struct SimpleDynamicArray {
    private:
        int* data;         // Указатель на массив элементов
        size_t size;       // Текущее количество элементов
        size_t capacity;   // Вместимость массива

    public:
        // Конструкторы и деструктор
        SimpleDynamicArray();
        SimpleDynamicArray(const SimpleDynamicArray& other); // Конструктор копирования
        ~SimpleDynamicArray();

        // Методы доступа
        int at(size_t index) const;
        size_t get_size() const;
        size_t count() const { return size; }

        // Методы модификации
        void push_back(int value);
        void push_front(int value);
        void insert(size_t index, int value);
        void pop_back();
        void pop_front();
        void pop_out(size_t index);

        // Дополнительные методы
        void concatenate(const SimpleDynamicArray& other);
        void replace(size_t index, int value);
        void swap(size_t index1, size_t index2);
        void print() const;
        

        // Оператор присваивания
        SimpleDynamicArray& operator=(const SimpleDynamicArray& other);
    };

} // namespace SimpleDynamicArrayNS

#endif // SIMPLE_DYNAMIC_ARRAY_H