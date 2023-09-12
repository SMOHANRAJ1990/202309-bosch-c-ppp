#pragma once
#include <string>
#include <vector>
using namespace std;

class Book
{
public:
	string title;
	string author;

	Book(string title, string author)
	{
		this->title = title;
		this->author = author;
	}
};

class BooksDb
{
	vector<Book*> books;

	BooksDb() {
		Book* _books[] = {
			new Book("The Accursed God","Vivek Dutta Mishra"),
			new Book("Manas","Vivek Dutta Mishra"),
			new Book("Rashmirathi","Ramdhari Singh Dinkar"),
			new Book("The Sons of Fortune","Jeffrey Archer"),
			new Book("Kane and Abel","Jeffrey Archer"),
			NULL
		};

		for (int i = 0; _books[i]; i++)
			books.push_back(_books[i]);
		
	}
public:
	static BooksDb* instance() {
		static BooksDb* _instance = new BooksDb();
		return _instance;
	}
	
	vector<Book*> GetAllBooks() { return books; }
};

