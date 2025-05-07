#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>
#include "SimpleDynamicArray.h"
#include "PointersArray.h"
#include "ListNode.h"

using namespace std;
using namespace std::chrono;

template<typename Func>
long long measure_time(Func operation) {
    auto start = high_resolution_clock::now();
    operation();
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();
}

void test_SimpleDynamicArray(long long results[12], int TEST_SIZE) {
    SimpleDynamicArrayNS::SimpleDynamicArray arr;
    results[0] = measure_time([&]() { for (int i = 0; i < TEST_SIZE; ++i) arr.push_back(i); });
    results[1] = measure_time([&]() { for (int i = 0; i < TEST_SIZE; ++i) arr.push_front(i); });
    results[2] = measure_time([&]() { for (int i = 0; i < TEST_SIZE / 10; ++i) arr.insert(i % (arr.get_size() + 1), i); });
    results[3] = measure_time([&]() { for (int i = 0; i < TEST_SIZE; ++i) if (arr.get_size() > 0) arr.pop_back(); });
    results[4] = measure_time([&]() { for (int i = 0; i < TEST_SIZE; ++i) if (arr.get_size() > 0) arr.pop_front(); });
    results[5] = measure_time([&]() { for (int i = 0; i < TEST_SIZE / 10; ++i) if (arr.get_size() > 0) arr.pop_out(i % arr.get_size()); });
    results[6] = measure_time([&]() { for (int i = 0; i < TEST_SIZE / 10; ++i) if (arr.get_size() > 0) arr.replace(i % arr.get_size(), i); });
    results[7] = measure_time([&]() { for (int i = 0; i < TEST_SIZE / 10; ++i) if (arr.get_size() > 1) arr.swap(i % arr.get_size(), (i + 1) % arr.get_size()); });
    results[8] = measure_time([&]() { if (arr.get_size() > 0) arr.at(arr.get_size() / 2); });
    results[9] = measure_time([&]() { SimpleDynamicArrayNS::SimpleDynamicArray arr2; arr2.concatenate(arr); });
    results[10] = measure_time([&]() { arr.count(); });
    results[11] = measure_time([&]() { arr.print(); });
}

void test_PointersArray(long long results[12], int TEST_SIZE) {
    PointersArrayNS::PointersArray arr;
    vector<int*> pointers(TEST_SIZE);
    for (int i = 0; i < TEST_SIZE; ++i) pointers[i] = new int(i);

    results[0] = measure_time([&]() { for (int i = 0; i < TEST_SIZE; ++i) arr.push_back(pointers[i]); });
    results[1] = measure_time([&]() { for (int i = 0; i < TEST_SIZE; ++i) arr.push_front(pointers[i]); });
    results[2] = measure_time([&]() { for (int i = 0; i < TEST_SIZE / 10; ++i) arr.insert(i % (arr.get_size() + 1), pointers[i]); });
    results[3] = measure_time([&]() { for (int i = 0; i < TEST_SIZE; ++i) if (arr.get_size() > 0) arr.pop_back(); });
    results[4] = measure_time([&]() { for (int i = 0; i < TEST_SIZE; ++i) if (arr.get_size() > 0) arr.pop_front(); });
    results[5] = measure_time([&]() { for (int i = 0; i < TEST_SIZE / 10; ++i) if (arr.get_size() > 0) arr.pop_out(i % arr.get_size()); });
    results[6] = measure_time([&]() { for (int i = 0; i < TEST_SIZE / 10; ++i) if (arr.get_size() > 0) arr.replace(i % arr.get_size(), pointers[i]); });
    results[7] = measure_time([&]() { for (int i = 0; i < TEST_SIZE / 10; ++i) if (arr.get_size() > 1) arr.swap(i % arr.get_size(), (i + 1) % arr.get_size()); });
    results[8] = measure_time([&]() { if (arr.get_size() > 0) arr.at(arr.get_size() / 2); });
    results[9] = measure_time([&]() { PointersArrayNS::PointersArray arr2; arr2.concatenate(arr); });
    results[10] = measure_time([&]() { arr.count(); });
    results[11] = measure_time([&]() { arr.print(); });

    // Очистка памяти
    for (auto ptr : pointers) delete ptr;
}

void test_List(long long results[12], int TEST_SIZE) {
    ListNS::List list;
    results[0] = measure_time([&]() { for (int i = 0; i < TEST_SIZE; ++i) list.push_back(i); });
    results[1] = measure_time([&]() { for (int i = 0; i < TEST_SIZE; ++i) list.push_front(i); });
    results[2] = measure_time([&]() { for (int i = 0; i < TEST_SIZE / 10; ++i) list.insert(i % (list.get_size() + 1), i); });
    results[3] = measure_time([&]() { for (int i = 0; i < TEST_SIZE; ++i) if (list.get_size() > 0) list.pop_back(); });
    results[4] = measure_time([&]() { for (int i = 0; i < TEST_SIZE; ++i) if (list.get_size() > 0) list.pop_front(); });
    results[5] = measure_time([&]() { for (int i = 0; i < TEST_SIZE / 10; ++i) if (list.get_size() > 0) list.pop_out(i % list.get_size()); });
    results[6] = measure_time([&]() { for (int i = 0; i < TEST_SIZE / 10; ++i) if (list.get_size() > 0) list.replace(i % list.get_size(), i); });
    results[7] = measure_time([&]() { for (int i = 0; i < TEST_SIZE / 10; ++i) if (list.get_size() > 1) list.swap(i % list.get_size(), (i + 1) % list.get_size()); });
    results[8] = measure_time([&]() { if (list.get_size() > 0) list.at(list.get_size() / 2); });
    results[9] = measure_time([&]() { ListNS::List list2; list2.concatenate(list); });
    results[10] = measure_time([&]() { list.count(); });
    results[11] = measure_time([&]() { list.print(); });
}

int main() {
    const int TEST_SIZE = 10000;
    long long results[3][12] = { 0 };

    cout << "Testing SimpleDynamicArray..." << endl;
    test_SimpleDynamicArray(results[0], TEST_SIZE);

    cout << "Testing PointersArray..." << endl;
    test_PointersArray(results[1], TEST_SIZE);

    cout << "Testing List..." << endl;
    test_List(results[2], TEST_SIZE);

    // Вывод результатов
    const char* op_names[] = {
        "push_back", "push_front", "insert", "pop_back", "pop_front",
        "pop_out", "replace", "swap", "at", "concatenate", "count", "print"
    };

    cout << "\nComparison of execution time (microseconds):\n";
    cout << "------------------------------------------------------------------------------------------\n";
    cout << "Operation\t\tSimpleDynamicArray\tPointersArray\t\tList\n";
    cout << "------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < 12; ++i) {
        cout << left << setw(16) << op_names[i] << "\t"
            << setw(16) << results[0][i] << "\t"
            << setw(16) << results[1][i] << "\t"
            << results[2][i] << endl;
    }

    // Таблица сложности операций
    cout << "\nTheoretical complexity of operations:\n";
    cout << "-------------------------------------------------\n";
    cout << "Operation\t\tSimpleArray\tPointersArray\tList\n";
    cout << "-------------------------------------------------\n";
    cout << "push_back\t\tO(1)*\t\tO(1)*\t\tO(1)\n";
    cout << "push_front\t\tO(n)\t\tO(n)\t\tO(1)\n";
    cout << "insert\t\t\tO(n)\t\tO(n)\t\tO(n)\n";
    cout << "pop_back\t\tO(1)\t\tO(1)\t\tO(n)\n";
    cout << "pop_front\t\tO(n)\t\tO(n)\t\tO(1)\n";
    cout << "pop_out\t\t\tO(n)\t\tO(n)\t\tO(n)\n";
    cout << "replace\t\t\tO(1)\t\tO(1)\t\tO(n)\n";
    cout << "swap\t\t\tO(1)\t\tO(1)\t\tO(n)\n";
    cout << "at\t\t\tO(1)\t\tO(1)\t\tO(n)\n";
    cout << "concatenate\t\tO(n)\t\tO(n)\t\tO(n)\n";
    cout << "count\t\t\tO(1)\t\tO(1)\t\tO(1)\n";
    cout << "print\t\t\tO(n)\t\tO(n)\t\tO(n)\n";
    cout << "-------------------------------------------------\n";
    cout << "* Amortized complexity\n";

    return 0;
}