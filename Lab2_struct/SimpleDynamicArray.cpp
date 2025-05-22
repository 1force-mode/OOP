#include "SimpleDynamicArray.h"
#include <iostream>  // ��� print()
#include <algorithm> // ��� std::copy (� ������������ �����������)

using namespace std;

namespace SimpleDynamicArrayNS {

    // ����������� (������ ������ ������)
    SimpleDynamicArray::SimpleDynamicArray()
        : data(nullptr), size(0), capacity(0) {
    }

    // ���������� (����������� ������)
    SimpleDynamicArray::~SimpleDynamicArray() {
        delete[] data;
    }

    // ����������� ����������� (������ ����� ������� �������)
    SimpleDynamicArray::SimpleDynamicArray(const SimpleDynamicArray& other)
        : data(new int[other.capacity]), size(other.size), capacity(other.capacity) {
        copy(other.data, other.data + size, data); // �������� ��������
    }

    // �������� ������������ (�������� ������ �� ������� �������)
    SimpleDynamicArray& SimpleDynamicArray::operator=(const SimpleDynamicArray& other) {
        if (this != &other) { // ������ �� ����������������
            delete[] data;
            data = new int[other.capacity];
            size = other.size;
            capacity = other.capacity;
            copy(other.data, other.data + size, data);
        }
        return *this;
    }

    // �������� ������� �� ������� (��� �������� ������)
    int SimpleDynamicArray::at(size_t index) const {
        if (index >= size) {
            return -1;
        }
        return *(data + index); // ������ data[index], �� ��� ��������� []
    }

    // ������� ���������� ���������
    size_t SimpleDynamicArray::get_size() const {
        return size;
    }

    // �������� ������� � �����
    void SimpleDynamicArray::push_back(int value) {
        if (size >= capacity) { // ���� ����� ��� � ����������� ������
            size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
            int* new_data = new int[new_capacity];

            // �������� ������ ��������
            for (size_t i = 0; i < size; ++i) {
                *(new_data + i) = *(data + i);
            }

            delete[] data;     // ����������� ������ ������
            data = new_data;   // ������������� �� ����� ������
            capacity = new_capacity;
        }

        *(data + size) = value; // ��������� �������
        size++;
    }

    // �������� ������� � ������ (�� ������� ���� ��������� ������)
    void SimpleDynamicArray::push_front(int value) {
        if (size >= capacity) { // ����������� ������, ���� �����
            size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
            int* new_data = new int[new_capacity];

            // ������� ����� ����� �������, ����� ������
            *new_data = value;
            for (size_t i = 0; i < size; ++i) {
                *(new_data + i + 1) = *(data + i);
            }

            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
        else {
            // �������� ��� �������� ������
            for (size_t i = size; i > 0; --i) {
                *(data + i) = *(data + i - 1);
            }
            *data = value; // ���������� ����� ������� � ������
        }
        size++;
    }

    // �������� ������� � ������������ �������
    void SimpleDynamicArray::insert(size_t index, int value) {
        if (index > size) {
            cout << "Index out of range\n";
            return;
        }

        if (size >= capacity) { // ����������� ������, ���� �����
            size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
            int* new_data = new int[new_capacity];

            // �������� �������� �� �������
            for (size_t i = 0; i < index; ++i) {
                *(new_data + i) = *(data + i);
            }

            // ��������� ����� �������
            *(new_data + index) = value;

            // �������� ���������� ��������
            for (size_t i = index; i < size; ++i) {
                *(new_data + i + 1) = *(data + i);
            }

            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
        else {
            // �������� �������� ������, ������� � �����
            for (size_t i = size; i > index; --i) {
                *(data + i) = *(data + i - 1);
            }
            *(data + index) = value; // ��������� �������
        }
        size++;
    }

    // ������� ��������� �������
    void SimpleDynamicArray::pop_back() {
        if (size == 0) {
            cout << "Array is empty\n";
            return;
        }
        size--; // ������ ��������� ������ (������ �� �����������)
    }

    // ������� ������ ������� (�� ������� ���� ��������� �����)
    void SimpleDynamicArray::pop_front() {
        if (size == 0) {
            cout << "Array is empty\n";
            return;
        }

        for (size_t i = 0; i < size - 1; ++i) {
            *(data + i) = *(data + i + 1); // �������� ��� �������� �����
        }
        size--;
    }

    // ������� ������� �� �������
    void SimpleDynamicArray::pop_out(size_t index) {
        if (index >= size) {
            cout << "Index out of range\n";
            return;
        }

        for (size_t i = index; i < size - 1; ++i) {
            *(data + i) = *(data + i + 1); // �������� �������� �����
        }
        size--;
    }

    // ���������� ��� �������
    void SimpleDynamicArray::concatenate(const SimpleDynamicArray& other) {
        size_t new_size = size + other.size;

        if (new_size > capacity) { // ���� ����� ���� � ����������� ������
            size_t new_capacity = new_size;
            int* new_data = new int[new_capacity];

            // �������� ������� ��������
            for (size_t i = 0; i < size; ++i) {
                *(new_data + i) = *(data + i);
            }

            // �������� �������� �� ������� �������
            for (size_t i = 0; i < other.size; ++i) {
                *(new_data + size + i) = *(other.data + i);
            }

            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
        else {
            // ������ ��������� �������� ������� �������
            for (size_t i = 0; i < other.size; ++i) {
                *(data + size + i) = *(other.data + i);
            }
        }
        size = new_size;
    }

    // �������� ������� �� �������
    void SimpleDynamicArray::replace(size_t index, int value) {
        if (index >= size) {
            cout << "Index out of range\n";
            return;
        }
        *(data + index) = value;
    }

    // �������� ������� ��� ��������
    void SimpleDynamicArray::swap(size_t index1, size_t index2) {
        if (index1 >= size || index2 >= size) {
            cout << "Index out of range\n";
            return;
        }
        int temp = *(data + index1);
        *(data + index1) = *(data + index2);
        *(data + index2) = temp;
    }

    // ������� ������ � �������
    void SimpleDynamicArray::print() const {
        std::cout << "[ ";
        for (size_t i = 0; i < size; ++i) {
            std::cout << *(data + i) << " ";
        }
        std::cout << "]" << std::endl;
    }

}