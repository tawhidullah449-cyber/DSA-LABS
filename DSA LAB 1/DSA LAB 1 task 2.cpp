#include <iostream>
using namespace std;

template <typename T>
int linearSearch(T array[], int size, T key) {

    for (int i = 0; i < size; i++) {

        if (array[i] == key) {
            return i;
        }
    }

    return -1;
}

template <typename T>
void display(T array[], int size) {

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    cout << endl;
}

int main() {

    int array[] = { 7, 67, 99, 100, 200 };

    int size = sizeof(array) / sizeof(array[0]);

    display(array, size);

    int key;

    cout << "Enter key you want to search: ";
    cin >> key;

    int result = linearSearch(array, size, key);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    }
    else {
        cout << "Element not found" << endl;
    }

    return 0;
}
