#pragma once

#include <cstddef> // ��� size_t
#include <iostream> // ��� print()

namespace ListNS {

    // ���� ������������ ������
    struct ListNode {
        int value;         // �������� ����
        ListNode* next;    // ��������� �� ��������� ����

        // ����������� ����
        ListNode(int val, ListNode* next_node = nullptr);
    };

    // ��� ����������� ������
    struct List {
    private:
        ListNode* head;    // ��������� �� ������ ����
        ListNode* tail;    // ��������� �� ��������� ����
        size_t size;       // ���������� ���������

    public:
        // ������������ � ����������
        List();
        ~List();

        // ������ �������
        int at(size_t index) const;
        size_t get_size() const;
        size_t count() const { return size; }

        // ������ �����������
        void push_back(int value);
        void push_front(int value);
        void insert(size_t index, int value);
        void pop_back();
        void pop_front();
        void pop_out(size_t index);

        // �������������� ������
        void concatenate(const List& other);
        void replace(size_t index, int value);
        void swap(size_t index1, size_t index2);
        void print() const;

        // ������ ����������� (��� ���������)
        List(const List&) = delete;
        List& operator=(const List&) = delete;
    };

}

