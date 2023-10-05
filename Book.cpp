#include "Book.h"

// Default constructor
Book::Book() {

    genre = "";
    author = "";
    title = "";
    id = 0;
}

// Parameterized constructor
Book::Book(const std::string& genre, const std::string& author, const std::string& title, int id) {
    this->genre = genre;
    this->author = author;
    this->title = title;
    this->id = id;
}

// Getters
std::string Book::getGenre() const {
    return genre;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getTitle() const {
    return title;
}

int Book::getId() const {
    return id;
}

// Setters
void Book::setGenre(const std::string& genre) {
    this->genre = genre;
}

void Book::setAuthor(const std::string& author) {
    this->author = author;
}

void Book::setTitle(const std::string& title) {
    this->title = title;
}

void Book::setId(int id) {
    this->id = id;
}
