// CapstoneProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <iostream>
#include "Book.h"
#include "BookSerializer.h"

using namespace std;


void listBooks(vector<Book>& books);
void removeBook(int id, std::vector<Book>& books);
void addBook(std::vector<Book>& books);
void sortByTitle(std::vector<Book>& books);
void sortByAuthor(std::vector<Book>& books);
void bubbleSortByTitle(std::vector<Book>& books);
void bubbleSortByAuthor(std::vector<Book>& books);

vector<Book> books;

        int main()
        {

            int input;
            


            cout << "Hello welcome to the Library Management System" << endl;
            //Used to read "text" database
            BookSerializer bookSerializer("books.txt");
            bookSerializer.deserializeBooks(books);
            //Menu interface
            while (true) {
                cout << "Pick an action" << endl;
                cout << "1. List books" << endl;
                cout << "2. Delete book" << endl;
                cout << "3. Add book" << endl;
                cout << "4. Search for book" << endl;
                cout << "5. Exit the program" << endl;

                cin >> input;

                if (input == 5) {
                    bookSerializer.serializeBooks(books);
                    cout << "You have exited the program, goodbye!" << endl;
                    break;
                }

                switch (input) {
                case 1:
                    listBooks(books);
                    continue;
                case 2: {
                    int id;
                    cout << "Enter the book ID to delete: ";
                    cin >> id;
                    removeBook(id, books);
                    continue;
                }
                case 3:
                    addBook(books);
                    continue;
                case 4:
            
                    break;
                default:
                    cout << "Invalid input. Please try again." << endl;

                }

        
            }
            bookSerializer.serializeBooks(books);
            return 0;
        }


//Function that list the books in the database
void listBooks(vector<Book>& books) {
    int input;
    cout << "How would you like the books listed" << endl;
    cout << "1.By title" << endl;
    cout << "2.By author" << endl;
    cin >> input;
    cin.ignore();
    if (input == 1) {
        sortByTitle(books);
    }
    else if (input == 2) {
        sortByAuthor(books);

    }
}

//function to remove books
void removeBook(int id,vector<Book>& books) {
    try {
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].getId() == id) {
                books.erase(books.begin() + i);
                
            }
        }

        
    }
    catch (exception& e) {
       cout << "Exception occurred during book removal: " << e.what() << endl;
        
    }
}


void addBook(vector<Book>& books) {
    try {
        string genre, author, title;
        int id;

        cout << "Enter the book genre: ";
        getline(cin >> ws, genre);

        if (genre.empty()) {
            throw invalid_argument("Invalid input: genre cannot be empty");
        }

        cout << "Enter the book author: ";
        getline(cin >>ws, author);

        if (author.empty()) {
            throw invalid_argument("Invalid input: author cannot be empty");
        }

        cout << "Enter the book title: ";
        getline(cin >>ws, title);

        if (title.empty()) {
            throw invalid_argument("Invalid input: title cannot be empty");
        }

        cout << "Enter the book ID: ";
        cin >> id;

        if (cin.fail()) {
            throw invalid_argument("Invalid input: ID must be an integer");
        }

        books.emplace_back(genre, author, title, id);

        std::cout << "Book added successfully" << std::endl;
    }
    catch (exception e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
    }
}
// Function to sort books by title
void sortByTitle(std::vector<Book>& books) {
    bubbleSortByTitle(books);


    std::cout << "List of Books (sorted by title):" << std::endl;
    for (const Book& book : books) {
        std::cout << "Title: " << book.getTitle() << std::endl;
        std::cout << "Author: " << book.getAuthor() << std::endl;
        std::cout << "Genre: " << book.getGenre() << std::endl;
        std::cout << "ID: " << book.getId() << std::endl;
        std::cout << "-------------------\n";
    }
}

// Function to sort books by author
void sortByAuthor(std::vector<Book>& books) {
    bubbleSortByAuthor(books);

    std::cout << "List of Books (sorted by author):" << std::endl;
    for (const Book& book : books) {
        std::cout << "Author: " << book.getAuthor() << std::endl;
        std::cout << "Title: " << book.getTitle() << std::endl;
        std::cout << "Genre: " << book.getGenre() << std::endl;
        std::cout << "ID: " << book.getId() << std::endl;
        std::cout << "-------------------\n";
    }
}

// BubbleSort algorithm implementation for sorting by title
void bubbleSortByTitle(std::vector<Book>& books) {
    int n = books.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (books[j].getTitle() > books[j + 1].getTitle()) {
                std::swap(books[j], books[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
           
            break;
        }
    }
}

// BubbleSort algorithm implementation for sorting by author
void bubbleSortByAuthor(std::vector<Book>& books) {
    int n = books.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (books[j].getAuthor() > books[j + 1].getAuthor()) {
                std::swap(books[j], books[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
           
            break;
        }
    }
}

