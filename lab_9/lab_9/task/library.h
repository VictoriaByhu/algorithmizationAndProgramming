#pragma once
#include "Book.h"
#include <string>

class Library {
private:
    static const int MAX_BOOKS = 10;
    Book books[MAX_BOOKS];
    std::string genre;
    int size;

public:
    Library(const std::string& genreName);   
    void addBook(const Book& b);            
    void showAllBooks() const;
};
