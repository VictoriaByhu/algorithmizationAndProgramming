#pragma once
#include <iostream>
#include <string>


class Book
{
private:
	char title[50];
	char author[50];
	int yearOfIssue;
	double price;
	int numberOfPages;
	char publisher[50];
	char city[50];
	void calculatePrice();
	
public:
	Book();
	void input();
	void output() const;
	int getPages() const { return numberOfPages; }
	double getPrice() const { return price; }
	friend int countByPublisher(Book books[], int size, const std::string& pub);
	friend void printBibliography(const Book& b);
	friend class Library;
};

class Library {
private:
	static const int MAX_BOOKS = 10;
	Book books[MAX_BOOKS];
	std::string genre;
	int size;

public:
	Library(const std::string& genreName);
	void addBook(const Book& b);
	void showAllBooks(const Book& b) const;
};


