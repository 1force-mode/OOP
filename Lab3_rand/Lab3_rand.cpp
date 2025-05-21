#include <iostream>
#include <random>  
#include <cmath> 
#include <map> 
#include <iomanip>



using namespace std;

//Генерация массива с равномерным распределением
double* GenUniformArray(int size, double a, double b) {
   
    random_device rd;  
    mt19937 gen(rd()); 
    uniform_real_distribution<> dis(a, b); 

    double* array = new double[size];
    for (int i = 0; i < size; i++) {
        array[i] = dis(gen);
    }
    return array;
}

//Генерация массива с нормальным распределением
double* GenNormalArray(int size, double mean, double stddev) {
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<> dis(mean, stddev); 
    
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
void CreateHistogram(double* array, int size) {
    double min_val = array[0];
    double max_val = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min_val) min_val = array[i];
        if (array[i] > max_val) max_val = array[i];
    }
    

    int num_bins = 1 + 3.322 * log10(size); 
    double bin_width = (max_val - min_val) / num_bins; 

    map<int, int> histogram; //Создание гистограммы
    for (int i = 0; i < size; i++) {
        int bin = (array[i] - min_val) / bin_width;
        histogram[bin]++; 
    }

    cout << "\n=== Histogram ===\n";
    //Вывод гистограммы
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
        cout << "1. Generate uniform distribution array (a=0, b=N*10)\n";
        cout << "2. Generate normal distribution array (µ=N*5, σ=N*2.5)\n";
        cout << "3. Calculate mean and standard deviation\n";
        cout << "4. Create histogram\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
        case 1: {
            cout << "Enter size (N): ";
            cin >> current_size; //В программе вы вводите свой номер варианта
            double a = 0;
            double b = current_size * 10;
            current_array = GenUniformArray(current_size, a, b);
            //PrintArray(current_array, current_size);
            break;
        }
        case 2: {
            cout << "Enter size (N): ";
            cin >> current_size; //В программе вы вводите свой номер варианта
            double mean = current_size * 5;
            double stddev = current_size * 2.5;
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
