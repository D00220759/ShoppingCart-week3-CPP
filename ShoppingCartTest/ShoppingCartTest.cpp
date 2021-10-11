#include "pch.h"
#include "CppUnitTest.h"
#include "../ShoppingCart/ShoppingCart.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ShoppingCartTest
{
	TEST_CLASS(ShoppingCartTest)
	{
	public:
		
		TEST_METHOD(TestAddBook)
		{
			Book* b = new Book();
			ShoppingCart cart;
			b->title = "Harry Potter";
			b->price = 12.99;
			Assert::IsTrue(cart.addBook(b));
		}

		TEST_METHOD(TestAddNoBook)
		{
			ShoppingCart cart;
			Assert::IsTrue(cart.addBook(nullptr));
			Assert::AreEqual(0, cart.size());
		}

		TEST_METHOD(testAddAllWithBooksList)
		{
			ShoppingCart cart;
			list<Book*> books;
			books.push_back(new Book("book 1", 9.99));
			books.push_back(new Book("book 2", 9.99));
			

			Assert::AreEqual(2, cart.addAll(books));
			Assert::AreEqual(2, cart.size());
		}

		TEST_METHOD(testAddAllnullptrInList)
		{
			ShoppingCart cart;
			list<Book*> books;
			books.push_back(new Book("book 1", 9.99));
			books.push_back(nullptr);
			books.push_back(new Book("book 2", 9.99));
			Assert::AreEqual(2, cart.addAll(books));
			Assert::AreEqual(2, cart.size());
		}

		TEST_METHOD(testAddAllEmptyList)
		{
			ShoppingCart cart;
			list<Book*> books;

			Assert::AreEqual(0, cart.addAll(books));
			Assert::AreEqual(0, cart.size());
		}

		TEST_METHOD(testREmovenull)
		{
			ShoppingCart cart;
			list<Book*> books;
			Book* bk(new Book("book 1", 9.99));
			books.push_back(bk);
			books.push_back(nullptr);
			books.push_back(new Book("book 2", 9.99));
			Assert::AreEqual(2, cart.addAll(books));
			Assert::IsFalse(cart.removeBook(nullptr));
			Assert::AreEqual(2, cart.size());
		}

		TEST_METHOD(testRemoveIsValid)
		{
			ShoppingCart cart;
			list<Book*> books;
			Book* bk(new Book("book 1", 9.99));
			books.push_back(bk);
			books.push_back(nullptr);
			books.push_back(new Book("book 2", 9.99));
			Assert::AreEqual(2, cart.addAll(books));
			Assert::IsTrue(cart.removeBook(nullptr));
			Assert::AreEqual(1, cart.size());
		}

		TEST_METHOD(testRemoveIsValid)
		{
			ShoppingCart cart;
			list<Book*> books;
			Book* bk(new Book("book 1", 9.99));
			books.push_back(new Book("book new", 17.99));
			books.push_back(new Book("book 2", 9.99));
			Assert::AreEqual(2, cart.addAll(books));
			Assert::IsFalse(cart.removeBook(nullptr));
			Assert::AreEqual(1, cart.size());
		}
	};
}
