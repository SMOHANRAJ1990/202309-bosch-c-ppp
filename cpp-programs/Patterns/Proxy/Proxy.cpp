// Proxy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "book-search.h"
#include "authenticator.h"
#include "authenticator-proxy.h"
#include "cache-search.h"

void ShowBooks(SearchResult result)
{
	cout << "Search Result for " << result.query << endl;
	if (result.isSuccess())
	{
		for (int i = 0; i < result.books.size(); i++)
			cout << result.books[i]->title << "\t" << result.books[i]->author << endl;
	}
	else
	{
		cout << "Failed:" << result.error << endl;
	}

	cout << endl << endl;

}

void SearchAndPrint(IBookSearch* search, string query)
{
	auto result = search->search(query);
	ShowBooks(result);
}

IBookSearch* BuildSearch()
{
	return new AuthenticatedBookSearch;
}

IBookSearch* BuildSearch1()
{
	return new AuthenticatedSearch(
			new SimpleBookSearch()
	);
}


int main()
{
	IBookSearch* search = BuildSearch();

	Authenticator::instance()->authenticate("sanjay", "p@ss");

	SearchAndPrint(search, "Vivek");
	SearchAndPrint(search, "Archer");
	SearchAndPrint(search, "John"); //NOT FOUND




	Authenticator::instance()->logout();
	//Authenticator::instance()->authenticate("sanjay", "p@ss");

	SearchAndPrint(search, "Manas"); //new result
	SearchAndPrint(search, "John"); //cached result NOT FOUND
	SearchAndPrint(search, "Vivek"); //cached


	return 0;
}
