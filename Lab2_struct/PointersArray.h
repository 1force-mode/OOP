#pragma once

#include <cstddef> // ��� size_t

namespace PointersArrayNS {

    struct PointersArray {
    private:
        int** data;        // ��������� �� ������ ���������� �� int
        size_t size;       // ������� ���������� ���������
        size_t capacity;   // ����������� �������

    public:
        // ������������ � ����������
        PointersArray();
        PointersArray(const PointersArray& other); // ����������� �����������
        ~PointersArray();

        // ������ �������
        int at(size_t index) const;
        size_t get_size() const;
        size_t count() const { return size; }

        // ������ �����������
        void push_back(int* value);
        void push_front(int* value);
        void insert(size_t index, int* value);
        void pop_back();
        void pop_front();
        void pop_out(size_t index);

        // �������������� ������
        void concatenate(const PointersArray& other);
        void replace(size_t index, int* value);
        void swap(size_t index1, size_t index2);
        void print() const;

        // �������� ������������
        PointersArray& operator=(const PointersArray& other);
    };

}


