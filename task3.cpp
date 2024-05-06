#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Define a struct to represent book information
struct Book {
    string t;
    string a;
    string i;
    bool av;
};

// Library class to manage books
class L {
private:
    vector<Book> c;

public:
    // Function to add a book to the catalog
    void add() {
        Book n;
        cout << "Enter book title: ";
        getline(cin, n.t);
        cout << "Enter book author: ";
        getline(cin, n.a);
        cout << "Enter book ISBN: ";
        getline(cin, n.i);
        n.av = true; // Set book as available by default
        c.push_back(n);
        cout << "Book added successfully." << endl;
    }

    // Function to remove a book from the catalog by title
    void rem(const string& t) {
        auto it = find_if(c.begin(), c.end(), 
            [&t](const Book& b) { return b.t == t; });
        if (it != c.end()) {
            c.erase(it);
            cout << "Book removed successfully." << endl;
        } else {
            cout << "Book not found." << endl;
        }
    }

    // Function to check the availability of a book by title
    bool chk(const string& t) {
        auto it = find_if(c.begin(), c.end(), 
            [&t](const Book& b) { return b.t == t && b.av; });
        return it != c.end();
    }

    // Function to display the library's catalog
    void disp() {
        if (c.empty()) {
            cout << "The library catalog is empty." << endl;
            return;
        }
        cout << "Library Catalog:" << endl;
        for (const auto& b : c) {
            cout << "Title: " << b.t << endl;
            cout << "Author: " << b.a << endl;
            cout << "ISBN: " << b.i << endl;
            cout << "Available: " << (b.av ? "Yes" : "No") << endl;
            cout << endl;
        }
    }
};

int main() {
    L l;
    int ch;
    string t;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Check Book Availability\n";
        cout << "4. Display Catalog\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        cin.ignore(); // Clear input buffer

        switch (ch) {
            case 1:
                l.add();
                break;
            case 2:
                cout << "Enter the title of the book to remove: ";
                getline(cin, t);
                l.rem(t);
                break;
            case 3:
                cout << "Enter the title of the book to check availability: ";
                getline(cin, t);
                if (l.chk(t)) {
                    cout << "The book is available." << endl;
                } else {
                    cout << "The book is not available or not found." << endl;
                }
                break;
            case 4:
                l.disp();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (ch != 5);

    return 0;
}
