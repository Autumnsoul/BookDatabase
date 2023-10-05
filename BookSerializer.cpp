    #include "BookSerializer.h"
    #include <sstream>
    #include <fstream>
    #include <iostream>
    #include <stdexcept>

    using namespace std;

    // Responsible for serializing books from a text file
    BookSerializer::BookSerializer(const string& filename) : filename(filename) {}

    bool BookSerializer::serializeBooks(const vector<Book>& books) {
        try {
            ofstream file(filename);
            if (!file.is_open()) {
                throw runtime_error("Failed to open file for writing");
            }

            for (const Book& book : books) {
                file << book.getGenre() << "," << book.getAuthor() << "," << book.getTitle() << "," << book.getId() << endl;
            }

            cout << "Books serialized" << endl;
            return true;
        }
        catch (const exception& e) {
            cout << "Serialization error: " << e.what() << endl;
            return false;
        }
    }



    bool BookSerializer::deserializeBooks(vector<Book>& books) {
        try {
            ifstream file(filename);
            if (!file.is_open()) {
                throw runtime_error("Failed to open file for reading");
            }

            books.clear();
            string line;
            while (getline(file, line)) {
                stringstream ss(line);
                string genre, author, title;
                int id;

                if (getline(ss, genre, ',') &&
                    getline(ss, author, ',') &&
                    getline(ss, title, ',') &&
                    (ss >> id)) {
                    books.emplace_back(genre, author, title, id);
                }
                else {
                    throw runtime_error("Failed to load data");
                }
            }

            cout << "Books deserialized" << endl;
            return true;
        }
        catch (const exception& e) {
            cout << "Deserialization error: " << e.what() << endl;
            return false;
        }
    }
