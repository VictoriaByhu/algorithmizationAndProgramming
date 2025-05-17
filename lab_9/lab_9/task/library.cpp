#include "Library.h"
#include <iostream>
using namespace std;

Library::Library(const std::string& genreName) {
    genre = genreName;
    size = 0;
}

void Library::addBook(const Book& b) {
    if (size < MAX_BOOKS) {
        books[size++] = b;
		cout << "Enter genre of book " << size << ": \n" ;
    }
    else {
        cout << "Library is full!\n";
    }
}

void Library::showAllBooks() const {
    cout << "Library genre: " << genre << "\n";
    cout << "Books in the library:\n";
    for (int i = 0; i < size; ++i) {
      cout << "---------------------\n";
        cout << "Title: " << books[i].title << "\n";
        cout << "Author: " << books[i].author << "\n";
        cout << "Year: " << books[i].yearOfIssue << "\n";
        cout << "Pages: " << books[i].numberOfPages << "\n";
        cout << "Price: " << books[i].price << "\n";
        cout << "Publisher: " << books[i].publisher << "\n";
        cout << "City: " << books[i].city << "\n";
    }
}

