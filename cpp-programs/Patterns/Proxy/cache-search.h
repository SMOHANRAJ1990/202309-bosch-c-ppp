#pragma once
#include <map>
#include <string>
#include <iostream>
#include "book-search.h"
using namespace std;

class CachedSearch:public IBookSearch
{
	map<string, SearchResult> cache;
	IBookSearch* target;
public:

	CachedSearch(IBookSearch * target)
	{
		this->target = target;
		
	}

	SearchResult search(string query)
	{
		
		auto found = cache.find(query)!=cache.end();
		


		if (found)
		{
			cout << "Returning cached result" << endl;
			return cache[query];
		}
		else
		{
			//go to the real target
			SearchResult result=target->search(query);

			//now cache it for future
			cache[query] = result;
			return result;
		}

			
	}
	
};
