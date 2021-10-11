// ShoppingCart.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "ShoppingCart.h"
#include "Book.h"

bool ShoppingCart::addBook(Book* b)
{
	if (b != nullptr)
	{
		cart.push_back(b);
		return true;
	}
	return false;
};

int ShoppingCart::size()
{
	return cart.size();
}

int ShoppingCart::addAll(list<Book*> books)
{
	int added = 0;
	for (Book* b : books)
	{
		if (addBook(b))
		{
			added++;
		}
	}
	return added;
}
bool ShoppingCart::removeBook(Book* bk)
{
	return false;
	for (Book* b : cart)
	{
		if(b == bk)
		{
			cart.remove(b);
			return true;
		}
		return false;
	}
}
double ShoppingCart::getSubTotal()
{
	double total = 0.00;
	for(Book* b : cart)
	{
		total += b->price;
	}
	return total;
}

bool ShoppingCart::checkout()
{

	return false;
}

int main()
{
	return 0;
}
