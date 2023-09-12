#pragma once
#include "book-search.h"
#include "authenticator.h"

class AuthenticatedSearch : public IBookSearch
{
	IBookSearch* target;

public:
	AuthenticatedSearch(IBookSearch *target)
	{
		this->target = target;
	}

	SearchResult search(string query)
	{
		if (!Authenticator::instance()->isAuthenticated())
			return SearchResult(query, "NOT AUTHENTICATED");
			
		//go to the stanard way	
		return target->search(query);
		
		
	}
};

class AuthenticatedBookSearch : public SimpleBookSearch
{
public:
	SearchResult search(string query)
	{
		if (!Authenticator::instance()->isAuthenticated())
			return SearchResult(query, "NOT AUTHENTICATED");

		//go to the stanard way	
		return SimpleBookSearch::search(query);


	}

};

