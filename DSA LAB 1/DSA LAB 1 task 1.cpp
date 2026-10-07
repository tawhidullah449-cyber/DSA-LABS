#include <iostream>

using namespace std;

template <typename T>
void bubblesort(T array[], int size) {

    for (int i = 0; i < size - 1; i++) {

        for (int j = 0; j < size - i - 1; j++) {

            if (array[j] > array[j + 1]) {

                T min = array[j];
                array[j] = array[j + 1];
                array[j + 1] = min;
            }
        }
    }
}

template <typename T>
void display(T array[], int size) {

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    cout << endl;
}

int main() {

    int array[] = { 5, 4, 3, 2 };

    int size = sizeof(array) / sizeof(array[0]);
    cout << "original array ;" << endl;
    display(array, size);


    cout << "sorted array :" << endl;
    bubblesort(array, size);

    


    display(array, size);

    return 0;
}
