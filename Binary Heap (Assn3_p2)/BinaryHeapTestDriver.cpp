#include "BinaryHeap.h"
#include <iostream>

using namespace std;

template <class ElementType>
void add(BinaryHeap<ElementType> &b, ElementType p)
{
	if (b.insert(p) == 1)
		cout << "Insertion successful" << endl;
}

template <class ElementType>
void red(BinaryHeap<ElementType> &b)
{
	try {
		b.remove();
	}
	catch (EmptyDataCollectionException &anException)
	{
		cout << "Removing unsuccesfull..." << anException.what() << endl;
	}
}

template <class ElementType>
void get(BinaryHeap<ElementType> &b)
{
	ElementType h;
	try {
		h = b.retrieve();
		cout << "Printing " <<  h << endl;
	}
	catch (EmptyDataCollectionException &anException)
	{
		cout << "Retrieving unsuccesfull..." << anException.what() << endl;
	}
}

template <class ElementType>
void print(BinaryHeap<ElementType> &b)
{
	b.printBinaryHeap();
}


int main()
{

	/*BinaryHeap<int> b1;
	for (int i = 65; i < 80; i++)
		add(b1, rand() % 26 + 65);
	print(b1);


	b1.~BinaryHeap();

	while(!b1.isEmpty())
		red(b1);
	red(b1);
	get(b1);*/

	
	
	BinaryHeap<char> b1;
	for (int i = 65; i < 80; i++)
		add(b1, char(rand() % 26 + 65));
	print(b1);


	b1.~BinaryHeap();

	while(!b1.isEmpty())
		red(b1);
	red(b1);
	get(b1);

	
	


	system("pause");
	return 0;
}