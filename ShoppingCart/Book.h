#pragma once
#include<iostream>
#include <string>
using namespace std;

struct Book
{
	string title;
	double price;
	Book(string title, double price)
	{
		this->title = title;
		this->price = price;
	}
	Book() {}
};
