#include <iostream>
#include <string>
using namespace std;


// Abstract Class
class LibraryItem {

public:

    virtual void display() = 0;

};


// Book Class
class Book : public LibraryItem {

private:

    string title;
    string author;
    int pages;

public:

    // Default Constructor
    Book() {

        title = "";
        author = "";
        pages = 0;
    }

    // Parameterized Constructor
    Book(string t, string a, int p) {

        title = t;
        author = a;
        pages = p;
    }

    string getTitle() {

        return title;
    }

    int getPages() {

        return pages;
    }

    void display() override {

        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }
};


// Newspaper Class
class Newspaper : public LibraryItem {

private:

    string name;
    string date;
    string edition;

public:

    // Default Constructor
    Newspaper() {

        name = "";
        date = "";
        edition = "";
    }

    // Parameterized Constructor
    Newspaper(string n, string d, string e) {

        name = n;
        date = d;
        edition = e;
    }

    string getName() {

        return name;
    }

    string getEdition() {

        return edition;
    }

    void display() override {

        cout << "Newspaper Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }
};


// Bubble Sort
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


// Linear Search
template <typename T>
int linearSearch(T array[], int size, T key) {

    for (int i = 0; i < size; i++) {

        if (array[i] == key) {

            return i;
        }
    }

    return -1;
}


// Library Class
class Library {

private:

    Book books[100];

    Newspaper newspapers[100];

    int bookCount;

    int newspaperCount;


public:

    // Default Constructor
    Library() {

        bookCount = 0;

        newspaperCount = 0;
    }


    void addBook(Book book) {

        books[bookCount] = book;

        bookCount++;
    }


    void addNewspaper(Newspaper newspaper) {

        newspapers[newspaperCount] = newspaper;

        newspaperCount++;
    }


    void displayCollection() {

        cout << "\nBooks:\n";

        for (int i = 0; i < bookCount; i++) {

            books[i].display();

            cout << endl;
        }


        cout << "Newspapers:\n";

        for (int i = 0; i < newspaperCount; i++) {

            newspapers[i].display();

            cout << endl;
        }
    }


    void sortBooksByPages() {

        for (int i = 0; i < bookCount - 1; i++) {

            for (int j = 0; j < bookCount - i - 1; j++) {

                if (books[j].getPages() >
                    books[j + 1].getPages()) {

                    Book temp = books[j];

                    books[j] = books[j + 1];

                    books[j + 1] = temp;
                }
            }
        }
    }


    void sortNewspapersByEdition() {

        for (int i = 0; i < newspaperCount - 1; i++) {

            for (int j = 0; j < newspaperCount - i - 1; j++) {

                if (newspapers[j].getEdition() >
                    newspapers[j + 1].getEdition()) {

                    Newspaper temp = newspapers[j];

                    newspapers[j] = newspapers[j + 1];

                    newspapers[j + 1] = temp;
                }
            }
        }
    }


    Book* searchBookByTitle(string title) {

        for (int i = 0; i < bookCount; i++) {

            if (books[i].getTitle() == title) {

                return &books[i];
            }
        }

        return nullptr;
    }


    Newspaper* searchNewspaperByName(string name) {

        for (int i = 0; i < newspaperCount; i++) {

            if (newspapers[i].getName() == name) {

                return &newspapers[i];
            }
        }

        return nullptr;
    }
};


int main() {

    // Create book objects

    Book book1(
        "The Catcher in the Rye",
        "J.D. Salinger",
        277
    );

    Book book2(
        "To Kill a Mockingbird",
        "Harper Lee",
        324
    );


    // Create newspaper objects

    Newspaper newspaper1(
        "Washington Post",
        "2024-10-13",
        "Morning Edition"
    );

    Newspaper newspaper2(
        "The Times",
        "2024-10-12",
        "Weekend Edition"
    );


    // Create library object

    Library library;


    // Add books and newspapers

    library.addBook(book1);

    library.addBook(book2);

    library.addNewspaper(newspaper1);

    library.addNewspaper(newspaper2);


    // Display collection

    cout << "Before Sorting:\n";

    library.displayCollection();


    // Sort

    library.sortBooksByPages();

    library.sortNewspapersByEdition();


    cout << "\nAfter Sorting:\n";

    library.displayCollection();


    // Search Book

    Book* foundBook =
        library.searchBookByTitle(
            "The Catcher in the Rye"
        );


    if (foundBook) {

        cout << "\nFound Book:\n";

        foundBook->display();
    }
    else {

        cout << "\nBook not found.\n";
    }


    // Search Newspaper

    Newspaper* foundNewspaper =
        library.searchNewspaperByName("The Times");


    if (foundNewspaper) {

        cout << "\nFound Newspaper:\n";

        foundNewspaper->display();
    }
    else {

        cout << "\nNewspaper not found.\n";
    }


    return 0;
}