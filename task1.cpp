#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    bool available;
};

void displayBooks(Book books[], int n) {
    cout << "\nAll Books:\n";
    for (int i = 0; i < n; i++) {
        cout << "Title: " << books[i].title
             << ", Author: " << books[i].author
             << ", ISBN: " << books[i].isbn
             << ", Status: " << (books[i].available ? "Available" : "Borrowed")
             << endl;
    }
}

int searchBook(Book books[], int n, string isbn) {
    for (int i = 0; i < n; i++) {
        if (books[i].isbn == isbn)
            return i;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter number of books: ";
    cin >> n;

    Book books[n];

    for (int i = 0; i < n; i++) {
        cin.ignore();
        cout << "\nEnter details for book " << i + 1 << endl;
        cout << "Title: ";
        getline(cin, books[i].title);
        cout << "Author: ";
        getline(cin, books[i].author);
        cout << "ISBN: ";
        getline(cin, books[i].isbn);
        books[i].available = true;
    }

    int choice;
    do {
        cout << "\n--- Library Menu ---\n";
        cout << "1. View all books\n";
        cout << "2. Borrow a book\n";
        cout << "3. Return a book\n";
        cout << "4. Search book by ISBN\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            displayBooks(books, n);
        }
        else if (choice == 2) {
            string isbn;
            cin.ignore();
            cout << "Enter ISBN to borrow: ";
            getline(cin, isbn);
            int index = searchBook(books, n, isbn);
            if (index != -1 && books[index].available) {
                books[index].available = false;
                cout << "Book borrowed successfully.\n";
            } else {
                cout << "Book not available or not found.\n";
            }
        }
        else if (choice == 3) {
            string isbn;
            cin.ignore();
            cout << "Enter ISBN to return: ";
            getline(cin, isbn);
            int index = searchBook(books, n, isbn);
            if (index != -1 && !books[index].available) {
                books[index].available = true;
                cout << "Book returned successfully.\n";
            } else {
                cout << "Invalid return request.\n";
            }
        }
        else if (choice == 4) {
            string isbn;
            cin.ignore();
            cout << "Enter ISBN to search: ";
            getline(cin, isbn);
            int index = searchBook(books, n, isbn);
            if (index != -1) {
                cout << "Title: " << books[index].title
                     << ", Author: " << books[index].author
                     << ", Status: " << (books[index].available ? "Available" : "Borrowed")
                     << endl;
            } else {
                cout << "Book not found.\n";
            }
        }
    } while (choice != 0);

    return 0;
}
