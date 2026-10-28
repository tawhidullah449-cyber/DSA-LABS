
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

// ---------- MyStack class ----------
template <typename T>
class MyStack : public AbstractStack<T> {
private:
    T* stArr;
    int capacity;
    int size;

public:
    MyStack() {
        capacity = 100;
        stArr = new T[capacity];
        size = 0;
    }

    MyStack(int _cap) {
        capacity = (_cap >= 1) ? _cap : 100;
        stArr = new T[capacity];
        size = 0;
    }

    MyStack(const MyStack&) = delete;
    MyStack& operator=(const MyStack&) = delete;

    // ---------- Virtual functions ----------
    bool IsEmpty() const override {
        return size == 0;
    }

    bool IsFull() const override {
        return size == capacity;
    }

    void Push(T v) override {
        if (!IsFull()) {
            stArr[size++] = v;
        }
        else {
            cout << "STACK IS FULL!" << endl;
        }
    }

    T Pop() override {
        if (IsEmpty()) {
            cout << "STACK IS EMPTY!" << endl;
            return T{};
        }

        return stArr[--size];
    }

    T Top() const override {
        if (IsEmpty()) {
            cout << "STACK IS EMPTY!" << endl;
            return T{};
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

// ---------- Text Editor ----------
class TextEditor {
private:
    char text[1000];
    int length;

    MyStack<char> undoStack;
    MyStack<char> redoStack;

public:
    TextEditor() : undoStack(1000), redoStack(1000) {
        length = 0;
        text[0] = '\0';
    }

    // ---------- Type a character ----------
    void TypeCharacter(char ch) {
        if (length >= 999) {
            cout << "TEXT IS FULL!" << endl;
            return;
        }

        if (undoStack.IsFull()) {
            cout << "UNDO HISTORY IS FULL!" << endl;
            return;
        }

        undoStack.Push(ch);
        length++;
        text[length - 1] = ch;
        text[length] = '\0';

        // A new action clears the redo history
        while (!redoStack.IsEmpty()) {
            redoStack.Pop();
        }

        cout << "Character added successfully." << endl;
    }

    // ---------- Delete last character ----------
    void DeleteCharacter() {
        if (length == 0) {
            cout << "TEXT IS EMPTY!" << endl;
            return;
        }

        if (undoStack.IsFull()) {
            cout << "UNDO HISTORY IS FULL!" << endl;
            return;
        }

        char ch = text[length - 1];

        // Store the deleted character as a negative action
        undoStack.Push(-ch);

        length--;
        text[length] = '\0';

        while (!redoStack.IsEmpty()) {
            redoStack.Pop();
        }

        cout << "Last character deleted." << endl;
    }

    // ---------- Undo ----------
    void Undo() {
        if (undoStack.IsEmpty()) {
            cout << "NOTHING TO UNDO!" << endl;
            return;
        }

        if (redoStack.IsFull()) {
            cout << "REDO HISTORY IS FULL!" << endl;
            return;
        }

        char action = undoStack.Pop();

        if (action >= 0) {
            // Undo typing: remove the last character
            if (length > 0) {
                length--;
                text[length] = '\0';
            }

            redoStack.Push(action);
        }
        else {
            // Undo deletion: restore the deleted character
            char ch = -action;

            if (length < 999) {
                text[length++] = ch;
                text[length] = '\0';
                redoStack.Push(action);
            }
            else {
                undoStack.Push(action);
                cout << "TEXT IS FULL!" << endl;
            }
        }

        cout << "Undo completed." << endl;
    }

    // ---------- Redo ----------
    void Redo() {
        if (redoStack.IsEmpty()) {
            cout << "NOTHING TO REDO!" << endl;
            return;
        }

        if (undoStack.IsFull()) {
            cout << "UNDO HISTORY IS FULL!" << endl;
            return;
        }

        char action = redoStack.Pop();

        if (action >= 0) {
            // Redo typing
            if (length < 999) {
                text[length++] = action;
                text[length] = '\0';
                undoStack.Push(action);
            }
            else {
                redoStack.Push(action);
                cout << "TEXT IS FULL!" << endl;
                return;
            }
        }
        else {
            // Redo deletion
            if (length > 0) {
                char ch = text[length - 1];
                length--;
                text[length] = '\0';
                undoStack.Push(-ch);
            }
        }

        cout << "Redo completed." << endl;
    }

    // ---------- Display current text ----------
    void DisplayText() const {
        cout << "Current text: " << text << endl;
    }
};

// ---------- Main ----------
int main() {
    TextEditor editor;
    int choice;
    char ch;

    do {
        cout << "\n===== TEXT EDITOR MENU =====" << endl;
        cout << "1. Type a character" << endl;
        cout << "2. Delete last character" << endl;
        cout << "3. Undo" << endl;
        cout << "4. Redo" << endl;
        cout << "5. Display current text" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter a character: ";
            cin >> ch;
            editor.TypeCharacter(ch);
            break;

        case 2:
            editor.DeleteCharacter();
            break;

        case 3:
            editor.Undo();
            break;

        case 4:
            editor.Redo();
            break;

        case 5:
            editor.DisplayText();
            break;

        case 6:
            cout << "Exiting text editor..." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
