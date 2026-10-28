
#include <iostream>
using namespace std;

// ---------- Abstract class ----------
template <typename T>
class AbstractStack {
public:
    virtual void Push(T value) = 0;
    virtual T Pop() = 0;
    virtual T Top() const = 0;
    virtual bool IsEmpty() const = 0;
    virtual bool IsFull() const = 0;
    virtual ~AbstractStack() {}
};

// ---------- MyCarStack class ----------
template <typename T>
class MyCarStack : public AbstractStack<T> {
private:
    T* stArr;
    int capacity;
    int size;

public:
    MyCarStack() {
        capacity = 8;
        stArr = new T[capacity];
        size = 0;
    }

    MyCarStack(int _cap) {
        capacity = (_cap >= 1) ? _cap : 8;
        stArr = new T[capacity];
        size = 0;
    }

    MyCarStack(const MyCarStack&) = delete;
    MyCarStack& operator=(const MyCarStack&) = delete;

    // ---------- Basic stack operations ----------
    bool IsEmpty() const override {
        return size == 0;
    }

    bool IsFull() const override {
        return size == capacity;
    }

    void Push(T v) override {
        if (!IsFull()) {
            stArr[size++] = v;
            cout << "Car " << v << " parked successfully." << endl;
        }
        else {
            cout << "PARKING LOT IS FULL!" << endl;
        }
    }

    T Pop() override {
        if (IsEmpty()) {
            cout << "PARKING LOT IS EMPTY!" << endl;
            return T{};
        }

        return stArr[--size];
    }

    T Top() const override {
        if (IsEmpty()) {
            cout << "PARKING LOT IS EMPTY!" << endl;
            return T{};
        }

        return stArr[size - 1];
    }

    // ---------- Display parked cars ----------
    void Display() const {
        if (IsEmpty()) {
            cout << "No cars are parked." << endl;
            return;
        }

        cout << "Parked cars (top -> bottom): ";

        for (int i = size - 1; i >= 0; i--) {
            cout << stArr[i] << " ";

        }

        cout << endl;
    }

    // ---------- Total cars ----------
    int TotalCars() const {
        return size;
    }

    // ---------- Search for a car ----------
    bool Search(T carNo) const {
        for (int i = 0; i < size; i++) {
            if (stArr[i] == carNo) {
                return true;
            }
        }

        return false;
    }

    // ---------- Remove a car by number ----------
    void RemoveCar(T carNo) {
        if (IsEmpty()) {
            cout << "PARKING LOT IS EMPTY!" << endl;
            return;
        }

        // Temporary stack holds cars above the requested car
        MyCarStack<T> temp(capacity);

        bool found = false;

        while (!IsEmpty()) {
            T currentCar = Pop();

            if (currentCar == carNo) {
                found = true;
                cout << "Car " << carNo << " removed successfully."
                    << endl;
                break;
            }

            temp.Push(currentCar);
        }

        // Restore the temporarily moved cars
        while (!temp.IsEmpty()) {
            Push(temp.Pop());
        }

        if (!found) {
            cout << "Car " << carNo << " was not found in the parking lot."
                << endl;
        }
    }

    // ---------- Destructor ----------
    ~MyCarStack() {
        delete[] stArr;
        stArr = nullptr;
        capacity = 0;
        size = 0;
    }
};

// ---------- Main ----------
int main() {
    MyCarStack<int> parking(8);

    int choice;
    int carNo;

    do {
        cout << "\n===== PARKING LOT MENU =====" << endl;
        cout << "1. Park a new car" << endl;
        cout << "2. Remove a car by car number" << endl;
        cout << "3. View parked cars" << endl;
        cout << "4. Show total cars parked" << endl;
        cout << "5. Show car at the top" << endl;
        cout << "6. Search for a car" << endl;
        cout << "7. Check if parking lot is empty" << endl;
        cout << "8. Check if parking lot is full" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter car number: ";
            cin >> carNo;

            if (parking.Search(carNo)) {
                cout << "This car is already parked!" << endl;
            }
            else {
                parking.Push(carNo);
            }
            break;

        case 2:
            cout << "Enter car number to remove: ";
            cin >> carNo;
            parking.RemoveCar(carNo);
            break;

        case 3:
            parking.Display();
            break;

        case 4:
            cout << "Total cars parked: "
                << parking.TotalCars() << "/8" << endl;
            break;

        case 5:
            if (!parking.IsEmpty()) {
                cout << "Car at the top: "
                    << parking.Top() << endl;
            }
            else {
                cout << "PARKING LOT IS EMPTY!" << endl;
            }
            break;

        case 6:
            cout << "Enter car number to search: ";
            cin >> carNo;

            if (parking.Search(carNo)) {
                cout << "Car " << carNo
                    << " is present in the parking lot." << endl;
            }
            else {
                cout << "Car " << carNo
                    << " is not present in the parking lot." << endl;
            }
            break;

        case 7:
            cout << (parking.IsEmpty()
                ? "Parking lot is empty."
                : "Parking lot is not empty.") << endl;
            break;

        case 8:
            cout << (parking.IsFull()
                ? "Parking lot is full."
                : "Parking lot is not full.") << endl;
            break;

        case 9:
            cout << "Exiting parking lot system..." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 9);

    return 0;
}
