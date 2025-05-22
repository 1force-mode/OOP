#include "ListNode.h"
#include <iostream>

using namespace std;

namespace ListNS {

    // Реализация ListNode
    ListNode::ListNode(int val, ListNode* next_node)
        : value(val), next(next_node) {
    }

    // Реализация List

    // Конструктор (пустой список)
    List::List() : head(nullptr), tail(nullptr), size(0) {}

    // Деструктор (очистка памяти)
    List::~List() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* next = current->next;
            delete current;
            current = next;
        }
    }

    // Получить значение по индексу
    int List::at(size_t index) const {
        if (index >= size) {
            cout << "Index out of range\n";
            return -1;
        }

        ListNode* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->value;
    }

    // Текущий размер списка
    size_t List::get_size() const {
        return size;
    }

    // Добавить элемент в конец
    void List::push_back(int value) {
        ListNode* new_node = new ListNode(value);

        if (tail == nullptr) { // Если список пуст
            head = tail = new_node;
        }
        else {
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }

    // Добавить элемент в начало
    void List::push_front(int value) {
        ListNode* new_node = new ListNode(value, head);
        head = new_node;

        if (tail == nullptr) { // Если список был пуст
            tail = head;
        }
        size++;
    }

    // Вставить элемент по индексу
    void List::insert(size_t index, int value) {
        if (index > size) {
            cout << "Index out of range\n";
            return;
        }

        if (index == 0) {
            push_front(value);
        }
        else if (index == size) {
            push_back(value);
        }
        else {
            ListNode* current = head;
            for (size_t i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            ListNode* new_node = new ListNode(value, current->next);
            current->next = new_node;
            size++;
        }
    }

    // Удалить последний элемент
    void List::pop_back() {
        if (size == 0) {
            cout << "List is empty\n";
            return;
        }

        if (size == 1) {
            delete head;
            head = tail = nullptr;
        }
        else {
            ListNode* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        size--;
    }

    // Удалить первый элемент
    void List::pop_front() {
        if (size == 0) {
            cout << "List is empty\n";
            return;
        }

        ListNode* temp = head;
        head = head->next;
        delete temp;

        if (head == nullptr) {
            tail = nullptr;
        }
        size--;
    }

    // Удалить элемент по индексу
    void List::pop_out(size_t index) {
        if (index >= size) {
            cout << "Index out of range\n";
            return;
        }

        if (index == 0) {
            pop_front();
        }
        else if (index == size - 1) {
            pop_back();
        }
        else {
            ListNode* current = head;
            for (size_t i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            ListNode* temp = current->next;
            current->next = temp->next;
            delete temp;
            size--;
        }
    }

    // Объединить два списка
    void List::concatenate(const List& other) {
        ListNode* other_current = other.head;
        while (other_current != nullptr) {
            push_back(other_current->value);
            other_current = other_current->next;
        }
    }

    // Заменить значение по индексу
    void List::replace(size_t index, int value) {
        if (index >= size) {
            cout << "Index out of range\n";
            return;
        }

        ListNode* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        current->value = value;
    }

    // Поменять значения двух узлов местами
    void List::swap(size_t index1, size_t index2) {
        if (index1 >= size || index2 >= size) {
            cout << "Index out of range\n";
            return;
        }

        if (index1 == index2) return;

        // Находим первый узел
        ListNode* node1 = head;
        for (size_t i = 0; i < index1; ++i) {
            node1 = node1->next;
        }

        // Находим второй узел
        ListNode* node2 = head;
        for (size_t i = 0; i < index2; ++i) {
            node2 = node2->next;
        }

        // Меняем значения
        int temp = node1->value;
        node1->value = node2->value;
        node2->value = temp;
    }

    // Вывести список в консоль
    void List::print() const {
        ListNode* current = head;
        std::cout << "[ ";
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << "]" << std::endl;
    }

} // namespace ListNodeNS