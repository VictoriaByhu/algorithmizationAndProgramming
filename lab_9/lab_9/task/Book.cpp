#include <iostream>
#include "Book.h"
using namespace std;
void Book::calculatePrice()
{
	double pageCost;
	if (numberOfPages < 100) pageCost = 1.0;
	if (numberOfPages > 300) pageCost = 0.8;
	else pageCost = 0.9;
	price = (numberOfPages * pageCost) + 25;
}
Book::Book()
{
	char title[50] = " ";
	char author[50] = "Yatsko O.";
    yearOfIssue = 2023;
    numberOfPages = 0;
    price = 0.0;
}

void Book::input()
{
    cout << "Enter book title: ";
	cin.ignore();
	cin.getline(title, 50);
	cout << "Enter author's name: ";
	cin.getline(author, 50);
	cout << "Enter year of issue: ";
	cin >> yearOfIssue;
	cout << "Enter number of pages: ";
	cin >> numberOfPages;
	cout << "Enter publisher: ";
	cin.ignore();
	cin.getline(publisher, 50);
	cout << "Enter city: ";
	cin.getline(city, 50);
	calculatePrice();
}

void Book::output() const
{
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "Year of issue: " << yearOfIssue << endl;
	cout << "Number of pages: " << numberOfPages << endl;
	cout << "Price: " << price << endl;
}

int countByPublisher(Book books[], int size, const std::string& pub)
{
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (pub == books[i].publisher)
			count++;
	}
	return count;
}

void printBibliography(const Book& b)
{
	cout << b.author << ". " << b.title << ". ";
	cout << b.city << " : " << b.publisher << ". ";
	cout << b.yearOfIssue << ". " << b.numberOfPages << " c.\n";
}

Library::Library(const std::string& genreName) {
	genre = genreName;

}

void Library::addBook(const Book& b) {
	if (size < MAX_BOOKS) {
		books[size++] = b;
		cout << "Enter genre of book " << size << ": \n";
	}
	else {
		cout << "Library is full!\n";
	}
}

void Library::showAllBooks(const Book& books) const {

	cout << "Title: " << books.title << "\n";
	cout << "Author: " << books.author << "\n";
	cout << "Year: " << books.yearOfIssue << "\n";
	cout << "Pages: " << books.numberOfPages << "\n";
	cout << "Price: " << books.price << "\n";
	cout << "Publisher: " << books.publisher << "\n";
	cout << "City: " << books.city << "\n";

}

