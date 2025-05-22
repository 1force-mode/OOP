#include "ListNode.h"
#include <iostream>

using namespace std;

namespace ListNS {

    // ���������� ListNode
    ListNode::ListNode(int val, ListNode* next_node)
        : value(val), next(next_node) {
    }

    // ���������� List

    // ����������� (������ ������)
    List::List() : head(nullptr), tail(nullptr), size(0) {}

    // ���������� (������� ������)
    List::~List() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* next = current->next;
            delete current;
            current = next;
        }
    }

    // �������� �������� �� �������
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

    // ������� ������ ������
    size_t List::get_size() const {
        return size;
    }

    // �������� ������� � �����
    void List::push_back(int value) {
        ListNode* new_node = new ListNode(value);

        if (tail == nullptr) { // ���� ������ ����
            head = tail = new_node;
        }
        else {
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }

    // �������� ������� � ������
    void List::push_front(int value) {
        ListNode* new_node = new ListNode(value, head);
        head = new_node;

        if (tail == nullptr) { // ���� ������ ��� ����
            tail = head;
        }
        size++;
    }

    // �������� ������� �� �������
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

    // ������� ��������� �������
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

    // ������� ������ �������
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

    // ������� ������� �� �������
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

    // ���������� ��� ������
    void List::concatenate(const List& other) {
        ListNode* other_current = other.head;
        while (other_current != nullptr) {
            push_back(other_current->value);
            other_current = other_current->next;
        }
    }

    // �������� �������� �� �������
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

    // �������� �������� ���� ����� �������
    void List::swap(size_t index1, size_t index2) {
        if (index1 >= size || index2 >= size) {
            cout << "Index out of range\n";
            return;
        }

        if (index1 == index2) return;

        // ������� ������ ����
        ListNode* node1 = head;
        for (size_t i = 0; i < index1; ++i) {
            node1 = node1->next;
        }

        // ������� ������ ����
        ListNode* node2 = head;
        for (size_t i = 0; i < index2; ++i) {
            node2 = node2->next;
        }

        // ������ ��������
        int temp = node1->value;
        node1->value = node2->value;
        node2->value = temp;
    }

    // ������� ������ � �������
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