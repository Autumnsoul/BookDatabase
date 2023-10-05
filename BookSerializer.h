#pragma once
#ifndef BOOKSERIALIZER_H
#define BOOKSERIALIZER_H

#include <string>
#include <vector>
#include "Book.h"

class BookSerializer {
private:
    std::vector<Book> books;
    std::string filename;

public:
    BookSerializer(const std::string& filename);
   

    bool serializeBooks(const std::vector<Book>& books);
    
    bool deserializeBooks(std::vector<Book>& books);
};

#endif  // BOOKSERIALIZER_H
