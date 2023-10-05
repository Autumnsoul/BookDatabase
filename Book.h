#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string genre;
    std::string author;
    std::string title;
    int id;

public:
    // Constructors
    Book();
    Book(const std::string& genre, const std::string& author, const std::string& title, int id);

    // Getter methods
    std::string getGenre() const;
    std::string getAuthor() const;
    std::string getTitle() const;
    int getId() const;

    // Setter methods
    void setGenre(const std::string& genre);
    void setAuthor(const std::string& author);
    void setTitle(const std::string& title);
    void setId(int id);
};

#endif  // BOOK_H


#pragma once
