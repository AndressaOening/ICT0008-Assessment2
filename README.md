# Book Management System

A simple C++ console application for managing the borrowing of books in a library, designed as part of an ICT0008 assessment project.

## Features

- Store and display book information (title, author, ISBN, acquisition date, availability)
- Borrow books by ISBN (with availability/status check)
- Automatic sorting of the library by ISBN
- User-friendly prompts and error messages
- Easily extensible – foundation for future tasks such as adding hardcopy or e-book management

## Folder Structure

```library-system/
├── docs/
├── src/
│ └── main.cpp
├── README.md
```

## Getting Started

### Prerequisites

- C++17 compliant compiler (GCC, Clang, MSVC)
- Git (recommended for source control)
- (Optional) Microsoft Visual Studio or any C++ IDE

### Building and Running

#### Using Command Line

1. Open your terminal and navigate to your project folder.
2. Compile:

```
g++ -std=c++17 -o library_system ./src/main.cpp
```

3. Run:

```
./library_system
```

#### Using Visual Studio

1. Open Visual Studio.
2. Create a new **Console App** project.
3. Copy the `main.cpp` file from the `src` folder into your project.
4. Press `Ctrl + F5` to build and run.

### Using GitHub

To clone the project:

```bash
git clone https://github.com/AndressaOening/ICT0008-Assessment2.git
```

## Usage

When you run the application:
- The library starts with 5 books.
- Books are sorted by ISBN.
- The program displays all books and waits for user input (ISBN).
- Enter the ISBN of the book you wish to borrow.
- If the book is available, it will be marked as borrowed.
- If it is already borrowed or does not exist, an error message is displayed.
- Enter `0` at any time to exit the program.

## Example Output

```
Books sorted by ISBN.

========== LIBRARY BOOK COLLECTION ==========

Book 1:
Title: Harry Potter and the Philosopher's Stone
Author: J.K. Rowling
ISBN: 12345
Date Added: 2024-01-15
Availability: Available
----------------------------------------

Book 2:
Title: The Hobbit
Author: J.R.R. Tolkien
ISBN: 23456
Date Added: 2024-02-20
Availability: Available
----------------------------------------

Book 3:
Title: 1984
Author: George Orwell
ISBN: 34567
Date Added: 2024-03-10
Availability: Available
----------------------------------------

Book 4:
Title: To Kill a Mockingbird
Author: Harper Lee
ISBN: 45678
Date Added: 2024-04-05
Availability: Available
----------------------------------------

Book 5:
Title: The Great Gatsby
Author: F. Scott Fitzgerald
ISBN: 56789
Date Added: 2024-05-12
Availability: Available
----------------------------------------

========== LIBRARY MANAGEMENT MENU ==========
1. Display all books
2. Borrow a book
3. Return a book
0. Exit
=============================================
Enter your choice: 0

Thank you for using the Library System. Goodbye!
```

## Source Control

- Changes are tracked using [Git](https://git-scm.com/) and optionally [GitHub](https://github.com/).
- Commit messages log every project milestone, including setup, feature additions, and bug fixes.
- Refer to the commit history for evidence of check-in/check-out during development.

## Author

This project was developed as part of an assessment for an IT course.