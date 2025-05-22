#pragma once

#include <cstddef> // Для size_t
#include <iostream> // Для print()

namespace ListNS {

    // Узел односвязного списка
    struct ListNode {
        int value;         // Значение узла
        ListNode* next;    // Указатель на следующий узел

        // Конструктор узла
        ListNode(int val, ListNode* next_node = nullptr);
    };

    // Сам односвязный список
    struct List {
    private:
        ListNode* head;    // Указатель на первый узел
        ListNode* tail;    // Указатель на последний узел
        size_t size;       // Количество элементов

    public:
        // Конструкторы и деструктор
        List();
        ~List();

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
        void concatenate(const List& other);
        void replace(size_t index, int value);
        void swap(size_t index1, size_t index2);
        void print() const;

        // Запрет копирования (для упрощения)
        List(const List&) = delete;
        List& operator=(const List&) = delete;
    };

}

