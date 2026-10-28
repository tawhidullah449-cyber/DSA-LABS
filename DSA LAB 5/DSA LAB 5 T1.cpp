#include <iostream>
using namespace std;



// Abstract class 

template <typename T> 
class AbstractStack {
public:
    virtual void Push(T value) = 0; virtual T Pop() = 0;
    virtual T Top() const = 0;
    virtual bool IsEmpty() const = 0; virtual bool IsFull() const = 0; virtual ~AbstractStack() {}
};





// ---------- MYStack class ----------

template <typename T>
class MyStack : public AbstractStack <T>
{
private:
    T* stArr;
    int capacity;
    int size;

public:
    MyStack() {
        capacity = 10;
        stArr = new T[capacity];
        size = 0;
    }
    MyStack(int _cap) {
        capacity = (_cap >= 1) ? _cap : 10;
        stArr = new T[capacity];
        size = 0;
    }
    MyStack(const MyStack&) = delete;
    MyStack& operator=(const MyStack&) = delete;

    // -------------VIRTUAL FUNCTION OVERRIDE--------------
    bool IsEmpty()  const override { return size == 0; }
    bool IsFull()  const override { return size == capacity; }

    void Push(T v) override {
        if (!IsFull()) stArr[size++] = v;
        else cout << "STACK IS FULL!" << endl;
    }
    T Pop() override {
        if (IsEmpty()) {
            cout << "STACK IS EMPTY!" << endl;
            return -1;
        }
        return stArr[--size];
    }
    T Top() const override {
        if (IsEmpty()) {
            cout << "STACK IS EMPTY!" << endl;
            return -1;
        }
        return stArr[size - 1];
    }
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
        stArr = nullptr;
        capacity = 0;
        size = 0;
    }
};

// ---------- REVERSE--------------
void reverseArray(const char* in, char* out) {
    int len = 0;
    while (in[len] != '\0') len++;               // manual length

    MyStack <char> st (len > 0 ? len : 1);
    for (int i = 0; i < len; i++) st.Push(in[i]);

    int i = 0;
    while (!st.IsEmpty()) out[i++] = (char)st.Pop();
    out[i] = '\0';                               
}

// --------MAIN----------------
int main() {
    cout << "=== Basic operations (capacity 3) ===" << endl;
    MyStack <int> s(3);
    s.Push(10);
    s.Push(20);
    s.Push(30);
    s.Push(40);                                  // overflow
    s.Display();
    cout << "Top = " << s.Top() << endl;
    cout << "Pop = " << s.Pop() << endl;
    cout << "Pop = " << s.Pop() << endl;
    s.Display();
    cout << "Pop = " << s.Pop() << endl;
    cout << "Pop = " << s.Pop() << endl;         // underflow

    cout << "\n=== Application: reverse character array ===" << endl;
    char input[] = "CAT";
    char result[20];
    reverseArray(input, result);
    cout << input << " -> " << result << endl;
    return 0;
}
