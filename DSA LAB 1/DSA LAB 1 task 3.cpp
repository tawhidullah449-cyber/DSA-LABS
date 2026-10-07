#include <iostream>
using namespace std;

template <typename T>
int binarysearch(T array[], int size, T key) {

    int low = 0;
    int high = size - 1;

    while (low <= high) {

        int mid = (low + high) / 2;

        if (array[mid] == key) {
            return mid;
        }
        else if (array[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
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

    int result = binarysearch(array, size, key);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    }
    else {
        cout << "Element not found" << endl;
    }

    return 0;
}
