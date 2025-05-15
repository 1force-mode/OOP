#include <iostream>
#include <random> //библиотека нужна для генераторов случайных чисел 
#include <cmath> //библиотека нужна для математических функций (pow (возведение в степень), sqrt (квадратный корень) и тд.)
#include <map> //библиотека нужна для контейнера, который хранит "ключ-значение", 75 строка -> map<int, int> histogram — хранение гистограммы (интервал → количество чисел в нём).
#include <iomanip> //библиотека нужна для форматированного вывода, для функции PrintArray, 39 строка

/*
-39 строка и пояснения (в целом эта функция не нужна и её можно удалить или переписать по другому)

fixed — вывод чисел в фиксированном формате (не в научной нотации).

setprecision(4) — 4 знака после запятой.

setw(10) — ширина поля вывода (10 символов).
*/

using namespace std;

//Генерация массива с равномерным распределением
double* GenUniformArray(int size, double a, double b) {
    //Этот код отвечает за генерацию случайных чисел (равномерное распределение)
    random_device rd; //random_device - это объявление генератора, rd - это название "зерна", начальное значение 
    mt19937 gen(rd()); //mt19937 - это псевдослучайный генератор, gen(rd()) - инициализирует генератор "зерном" из предыдущей строчки
    uniform_real_distribution<> dis(a, b); //создает равномерное распределение в диапазоне [a, b] (включая a, но не включая b)

    double* array = new double[size];
    for (int i = 0; i < size; i++) {
        array[i] = dis(gen);
        /*
        gen — это генератор случайных чисел (mt19937), который выдаёт псевдослучайные числа на основе начального «зерна» (random_device)
        dis — это распределение (uniform_real_distribution или normal_distribution), которое преобразует сырые случайные числа от gen в нужный диапазон и форму
        dis(gen) означает:
        «Дай мне следующее случайное число, соответствующее заданному распределению»
        */
    }
    return array;
}

//Генерация массива с нормальным распределением
double* GenNormalArray(int size, double mean, double stddev) {
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<> dis(mean, stddev); //эта строка создаёт генератор случайных чисел с нормальным распределением
    //mean - это центр распределения, а stddev - это то насколько можно отклониться от центра, например -- mean = 5, stddev = 2 будут в основном генерировать числа между 3 и 7

    double* array = new double[size];
    for (int i = 0; i < size; i++) {
        array[i] = dis(gen);
    }
    return array;
}

//Вывод массива
void PrintArray(double* array, int size) {
    cout << "\n=== Generated Array ===\n";
    for (int i = 0; i < size; i++) {
        cout << fixed << setprecision(4) << setw(10) << array[i];
        if ((i + 1) % 5 == 0) cout << endl;
    }
    cout << "\n====================\n";
}

//Расчёт математического ожидания
double CalculateMean(double* array, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

//Расчёт стандартного отклонения
double CalculateStdDev(double* array, int size, double mean) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += pow(array[i] - mean, 2);
    }
    return sqrt(sum / size);
}

//Построение гистограммы
//Эта функция строит гистограмму для массива чисел, показывая, как часто значения попадают в определённые интервалы
void CreateHistogram(double* array, int size) {
    double min_val = array[0];
    double max_val = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min_val) min_val = array[i];
        if (array[i] > max_val) max_val = array[i];
    }
    /*
    84-89 строки
    Ищет наименьшее (min_val) и наибольшее (max_val) значения в массиве
    Это нужно, чтобы определить диапазон данных для гистограммы
    */

    int num_bins = 1 + 3.322 * log10(size); //Формула Стёрджеса. Нужна для определения количества интервалов 
    double bin_width = (max_val - min_val) / num_bins; //Определение ширины каждого интервала

    map<int, int> histogram; //Создание гистограммы
    //Заполнение гистограммы. bin - это номер интервала
    for (int i = 0; i < size; i++) {
        int bin = (array[i] - min_val) / bin_width; //Здесь мы вычисляем в какой интервал попадает значение
        histogram[bin]++; //Увеличиваем счётчик этого интервала на 1
    }

    cout << "\n=== Histogram ===\n";
    //Вывод гистограммы
    //const - означает что переменная неизменямая, auto - автоматически определяет тип переменно, & - ссылка, чтобы избежать копирования элемента 
    //pair - это элемент контейнера map, который содержит пару "ключ-значение", histogram - это наш контейнер, куда мы засовываем элементы
    //Данный for это цикл по диапозону
    for (const auto& pair : histogram){
        double interval_start = min_val + pair.first * bin_width; //Начало интервала
        double interval_end = interval_start + bin_width; //Конец интервала
        cout << "[" << interval_start << " - " << interval_end << "]: "
            << string(pair.second * 20 / size, '*') << endl; //Масштабирует число звёздочек, чтобы гистограмма помещалась в консоли
    }
}

int main() {
    double* current_array = nullptr;
    int current_size = 0;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Generate uniform distribution array (a=0, b=N*1000)\n";
        cout << "2. Generate normal distribution array (µ=N*500, σ=N*250)\n";
        cout << "3. Calculate mean and standard deviation\n";
        cout << "4. Create histogram\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
        case 1: {
            cout << "Enter size (N): ";
            cin >> current_size;
            double a = 0;
            double b = current_size * 1000;
            current_array = GenUniformArray(current_size, a, b);
            //PrintArray(current_array, current_size);
            break;
        }
        case 2: {
            cout << "Enter size (N): ";
            cin >> current_size;
            double mean = current_size * 500;
            double stddev = current_size * 250;
            current_array = GenNormalArray(current_size, mean, stddev);
            //PrintArray(current_array, current_size);
            break;
        }
        case 3: {
            if (current_array == nullptr) {
                cout << "Generate an array first!\n";
                break;
            }
            double mean = CalculateMean(current_array, current_size);
            double stddev = CalculateStdDev(current_array, current_size, mean);
            cout << "Mean: " << mean << "\nStandard Deviation: " << stddev << endl;
            break;
        }
        case 4: {
            if (current_array == nullptr) {
                cout << "Generate an array first!\n";
                break;
            }
            CreateHistogram(current_array, current_size);
            break;
        }
        default:
            cout << "Invalid choice!\n";
        }
    }

    if (current_array != nullptr) {
        delete[] current_array;
    }
    return 0;
}