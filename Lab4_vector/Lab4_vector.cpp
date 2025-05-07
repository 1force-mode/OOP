#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
class TrainStack {
private:
    vector<T> data;

public:
    void push(const T& value) {
        data.push_back(value);
    }

    void pop() {
        if (!empty()) {
            data.pop_back();
        }
    }

    T& top() {
        return data.back();
    }

    const T& top() const {
        return data.back();
    }

    bool empty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }
};

class Train {
public:
    enum WagonType {
        Wood,
        Steel
    };

private:
    TrainStack<WagonType> wagons;

public:
    void createTrain(int wagonCount) {
        while (!wagons.empty()) {
            wagons.pop();
        }

        for (int i = 0; i < wagonCount; i++) {
            int type;
            cout << "Enter wagon type " << i + 1 << " (0 - wood, 1 - steel): ";
            cin >> type;
            wagons.push(static_cast<WagonType>(type));
        }
    }

    void sortTrains() {
        TrainStack<WagonType> woodTrain, steelTrain;

        // Распределяем вагоны по типам
        while (!wagons.empty()) {
            WagonType wagon = wagons.top();
            wagons.pop();

            if (wagon == Wood) {
                woodTrain.push(wagon);
            }
            else {
                steelTrain.push(wagon);
            }
        }

        // Выводим результаты
        printTrain("Wood train", woodTrain);
        printTrain("Steel train", steelTrain);
    }

    void printTrain(const string& title, const TrainStack<WagonType>& train) const {
        cout << "\n" << title << " (" << train.size() << " wagons):";

        // Для вывода в правильном порядке используем временный вектор
        vector<WagonType> temp;
        TrainStack<WagonType> copy = train;

        while (!copy.empty()) {
            temp.push_back(copy.top());
            copy.pop();
        }

        for (auto it = temp.rbegin(); it != temp.rend(); ++it) {
            cout << " - " << (*it == Wood ? "Wood" : "Steel");
        }
        cout << endl;
    }

    void printOriginalTrain() const {
        printTrain("Original train", wagons);
    }
};

int main() {
    Train train;
    int wagonNum;

    cout << "Enter the number of wagons: ";
    cin >> wagonNum;

    train.createTrain(wagonNum);
    train.printOriginalTrain();
    train.sortTrains();

    return 0;
}