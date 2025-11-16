#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    bool availability;
    string dateAdd;

public:
    // Constructor
    Book() {
        title = "";
        author = "";
        ISBN = "";
        availability = true;
        dateAdd = "";
    }

    // Method to set book details
    void setBookDetails(string t, string a, string isbn, string date) {
        title = t;
        author = a;
        ISBN = isbn;
        dateAdd = date;
        availability = true;
    }

    // Method to display book details
    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Date Added: " << dateAdd << endl;
        cout << "Availability: " << (availability ? "Available" : "Borrowed") << endl;
        cout << "----------------------------------------" << endl;
    }

    // Method to borrow a book
    bool borrowBook() {
        if (availability) {
            availability = false;
            cout << "Book borrowed successfully!" << endl;
            return true;
        } else {
            cout << "Error: Book is already borrowed." << endl;
            return false;
        }
    }

    // Method to return a book
    void returnBook() {
        if (!availability) {
            availability = true;
            cout << "Book returned successfully!" << endl;
        } else {
            cout << "Error: Book was not borrowed." << endl;
        }
    }

    // Getter for ISBN (needed for searching)
    string getISBN() {
        return ISBN;
    }

    // Static method to sort book data by ISBN
    static void sortBookData(Book books[], int size) {
        // Using bubble sort for simplicity
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (books[j].ISBN > books[j + 1].ISBN) {
                    // Swap books
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
        cout << "Books sorted by ISBN." << endl;
    }
};

// Function to find a book by ISBN
int findBookByISBN(Book books[], int size, string isbn) {
    for (int i = 0; i < size; i++) {
        if (books[i].getISBN() == isbn) {
            return i;
        }
    }
    return -1; // Not found
}

// Function to display all books
void displayAllBooks(Book books[], int size) {
    cout << "\n========== LIBRARY BOOK COLLECTION ==========" << endl;
    for (int i = 0; i < size; i++) {
        cout << "\nBook " << (i + 1) << ":" << endl;
        books[i].displayBookDetails();
    }
}

// Function to display menu
void displayMenu() {
    cout << "\n========== LIBRARY MANAGEMENT MENU ==========" << endl;
    cout << "1. Display all books" << endl;
    cout << "2. Borrow a book" << endl;
    cout << "3. Return a book" << endl;
    cout << "0. Exit" << endl;
    cout << "=============================================" << endl;
    cout << "Enter your choice: ";
}

int main() {
    const int LIBRARY_SIZE = 5;
    Book library[LIBRARY_SIZE];

    // Initialize 5 books
    library[0].setBookDetails("Harry Potter and the Philosopher's Stone", "J.K. Rowling", "12345", "2024-01-15");
    library[1].setBookDetails("The Hobbit", "J.R.R. Tolkien", "23456", "2024-02-20");
    library[2].setBookDetails("1984", "George Orwell", "34567", "2024-03-10");
    library[3].setBookDetails("To Kill a Mockingbird", "Harper Lee", "45678", "2024-04-05");
    library[4].setBookDetails("The Great Gatsby", "F. Scott Fitzgerald", "56789", "2024-05-12");

    // Sort books by ISBN
    Book::sortBookData(library, LIBRARY_SIZE);

    // Display all books initially
    displayAllBooks(library, LIBRARY_SIZE);

    // Main application loop
    int choice;
    string inputISBN;
    
    while (true) {
        displayMenu();
        cin >> choice;

        // Check for exit condition
        if (choice == 0) {
            cout << "\nThank you for using the Library System. Goodbye!" << endl;
            break;
        }

        switch (choice) {
            case 1:
                // Display all books
                displayAllBooks(library, LIBRARY_SIZE);
                break;

            case 2:
                // Borrow a book
                cout << "\nEnter ISBN of the book to borrow: ";
                cin >> inputISBN;

                {
                    int bookIndex = findBookByISBN(library, LIBRARY_SIZE, inputISBN);

                    if (bookIndex == -1) {
                        cout << "Error: Book with ISBN '" << inputISBN << "' not found." << endl;
                    } else {
                        cout << "\nBook found:" << endl;
                        library[bookIndex].displayBookDetails();
                        cout << "\nAttempting to borrow..." << endl;
                        library[bookIndex].borrowBook();
                    }
                }
                break;

            case 3:
                // Return a book
                cout << "\nEnter ISBN of the book to return: ";
                cin >> inputISBN;

                {
                    int bookIndex = findBookByISBN(library, LIBRARY_SIZE, inputISBN);

                    if (bookIndex == -1) {
                        cout << "Error: Book with ISBN '" << inputISBN << "' not found." << endl;
                    } else {
                        cout << "\nBook found:" << endl;
                        library[bookIndex].displayBookDetails();
                        cout << "\nAttempting to return..." << endl;
                        library[bookIndex].returnBook();
                    }
                }
                break;

            default:
                cout << "Error: Invalid choice. Please select 0-3." << endl;
                break;
        }
    }

    return 0;
}
