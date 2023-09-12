#pragma once
#include <vector>
#include <string>
#include "books.h"

using namespace std;

class SearchResult
{
public:
	vector<Book*> books;
	string error = "";
	string query = "";

	SearchResult(string query="", string error = "")
	{
		
		this->error = error;
		this->query = query;
	}

	bool isSuccess() { return error == ""; }

};


class IBookSearch
{
public:
	virtual SearchResult search(string query) = 0;

};

#define contains(outer,inner) (((int)outer.find(inner))>=0)

class SimpleBookSearch :public IBookSearch
{
public:
	SearchResult search(string query)
	{
		SearchResult result(query);
		auto _books = BooksDb::instance()->GetAllBooks();

		for (int i = 0; i < _books.size(); i++)
		{
			Book * book = _books[i];
			
			
			if (contains(book->title,query) || contains(book->author,query))
				result.books.push_back(book);
		}

		if (result.books.size() == 0)
			result.error = "NOT FOUND";

		return result;
	}
};