#pragma once
#include <list>
#include "Book.h"
class ShoppingCart
{
	list<Book*> cart;

public :
	bool addBook(Book* b);
	int size();
	int addAll(list<Book*> books);
	bool removeBook(Book* bk);
	double getSubTotal();
	
};