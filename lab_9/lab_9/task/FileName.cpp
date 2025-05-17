#include <iostream>
#include "Book.h"
using namespace std;

int main() {
	const int SIZE = 3;
	Book books[SIZE];

	for (int i = 0; i < SIZE; i++) {
		cout << "Book " << i + 1 << ":\n";
		books[i].input();
	}

	cout << "-------------------------\n";

	cout << "\nList of your books:\n";
	for (int i = 0; i < SIZE; i++) {
		cout << "Book " << i + 1 << ":\n";
		books[i].output();
	}

	int totalPages = 0;
	double maxPrice = books[0].getPrice();
	double minPrice = books[0].getPrice();

	for (int i = 0; i < SIZE; i++) {
		totalPages += books[i].getPages();
		if (books[i].getPrice() > maxPrice) {
			maxPrice = books[i].getPrice();
		}
		if (books[i].getPrice() < minPrice) {
			minPrice = books[i].getPrice();
		}
	}

	cout << "-------------------------\n";

	cout << "\nAverage number of pages: " << (double)totalPages / SIZE << endl;
	cout << "Maximum price: " << maxPrice << endl;
	cout << "Minimum price: " << minPrice << endl;


	string searchPublisher;
	cout << "\nEnter publisher to count books: ";
	getline(cin >> ws, searchPublisher);
	int count = countByPublisher(books, SIZE, searchPublisher);
	cout << "Number of books by publisher " << searchPublisher << ": " << count << endl;

	cout << "\nBibliography:\n";
	for (int i = 0; i < SIZE; i++) {
		printBibliography(books[i]);
	}

	Library myLibrary("AnyGenre");
	for (int i = 0; i < SIZE; i++) {
		myLibrary.showAllBooks(books[i]);
	}

	return 0;
}