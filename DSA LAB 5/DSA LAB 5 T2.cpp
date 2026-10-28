
#include <iostream>
using namespace std;

// Abstract class
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

// ---------- MyStack class ----------
template <typename T>
class MyStack : public AbstractStack<T> {
private:
    T* stArr;
    T* minArr;       // Stores minimum values
    int capacity;
    int size;
    int minSize;     // Number of elements in minArr

public:
    MyStack() {
        capacity = 10;
        stArr = new T[capacity];
        minArr = new T[capacity];
        size = 0;
        minSize = 0;
    }

    MyStack(int _cap) {
        capacity = (_cap >= 1) ? _cap : 10;
        stArr = new T[capacity];
        minArr = new T[capacity];
        size = 0;
        minSize = 0;
    }

    MyStack(const MyStack&) = delete;
    MyStack& operator=(const MyStack&) = delete;

    // ---------- Basic stack operations ----------
    bool IsEmpty() const override {
        return size == 0;
    }

    bool IsFull() const override {
        return size == capacity;
    }

    void Push(T v) override {
        if (IsFull()) {
            cout << "STACK IS FULL!" << endl;
            return;
        }

        stArr[size++] = v;

        // Store v if it is the current minimum or a new minimum
        if (minSize == 0 || v <= minArr[minSize - 1]) {
            minArr[minSize++] = v;
        }
    }

    T Pop() override {
        if (IsEmpty()) {
            cout << "STACK IS EMPTY!" << endl;
            return T{};
        }

        T value = stArr[--size];

        // Remove from minArr if the popped value is the minimum
        if (value == minArr[minSize - 1]) {
            minSize--;
        }

        return value;
    }

    T Top() const override {
        if (IsEmpty()) {
            cout << "STACK IS EMPTY!" << endl;
            return T{};
        }

        return stArr[size - 1];
    }

    // ---------- Get minimum in O(1) ----------
    T GetMin() const {
        if (IsEmpty()) {
            cout << "STACK IS EMPTY! No minimum element." << endl;
            return T{};
        }

        return minArr[minSize - 1];
    }

    // ---------- Display from top to bottom ----------
    void Display() const {
        cout << "Stack (top->bottom): [";

        for (int i = size - 1; i >= 0; i--) {
            cout << stArr[i];

            if (i > 0)
                cout << ", ";
        }

        cout << "]" << endl;
    }

    // ---------- Destructor ----------
    ~MyStack() {
        delete[] stArr;
        delete[] minArr;
    }
};

// ---------- Main ----------
int main() {
    MyStack<int> s(10);
    int choice;
    int value;

    do {
        cout << "\n===== STACK MENU =====" << endl;
        cout << "1. Push element" << endl;
        cout << "2. Pop element" << endl;
        cout << "3. Show top element" << endl;
        cout << "4. Check if stack is empty" << endl;
        cout << "5. Check if stack is full" << endl;
        cout << "6. Display stack elements" << endl;
        cout << "7. Show minimum element" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.Push(value);
            break;

        case 2:
            if (!s.IsEmpty())
                cout << "Popped: " << s.Pop() << endl;
            else
                cout << "STACK IS EMPTY!" << endl;
            break;

        case 3:
            if (!s.IsEmpty())
                cout << "Top element: " << s.Top() << endl;
            else
                cout << "STACK IS EMPTY!" << endl;
            break;

        case 4:
            cout << (s.IsEmpty() ? "Stack is empty." :
                "Stack is not empty.") << endl;
            break;

        case 5:
            cout << (s.IsFull() ? "Stack is full." :
                "Stack is not full.") << endl;
            break;

        case 6:
            s.Display();
            break;

        case 7:
            if (!s.IsEmpty())
                cout << "Minimum element: " << s.GetMin() << endl;
            else
                cout << "STACK IS EMPTY! No minimum element." << endl;
            break;

        case 8:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 8);

    return 0;
}
