#ifndef SIMPLE_DYNAMIC_ARRAY_H
#define SIMPLE_DYNAMIC_ARRAY_H

#include <cstddef> // ��� size_t

namespace SimpleDynamicArrayNS {

    struct SimpleDynamicArray {
    private:
        int* data;         // ��������� �� ������ ���������
        size_t size;       // ������� ���������� ���������
        size_t capacity;   // ����������� �������

    public:
        // ������������ � ����������
        SimpleDynamicArray();
        SimpleDynamicArray(const SimpleDynamicArray& other); // ����������� �����������
        ~SimpleDynamicArray();

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
        void concatenate(const SimpleDynamicArray& other);
        void replace(size_t index, int value);
        void swap(size_t index1, size_t index2);
        void print() const;
        

        // �������� ������������
        SimpleDynamicArray& operator=(const SimpleDynamicArray& other);
    };

} // namespace SimpleDynamicArrayNS

#endif // SIMPLE_DYNAMIC_ARRAY_H