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
			List<Book*> books;
			books.push_back(new Book("book 1", 9.99));
			books.push_back(new Book("book 2", 9.99, ));
			books.push_back(nullptr);

			Assert::AreEqual(2, cart.addAll(books));
			Assert::AreEqual(2, cart.size());
		}
	};
}
