#include <iostream>
#include "PriorityQueue.h"

using namespace std;


template <class ElementType>
void add(PriorityQueue<ElementType> &b, ElementType p)
{
	if (b.enqueue(p) == 1)
		cout << "Insertion successful" << endl;
}

template <class ElementType>
void red(PriorityQueue<ElementType> &b)
{
	try {
		b.dequeue();
	}
	catch (EmptyDataCollectionException &anException)
	{
		cout << "Removing unsuccesfull..." << anException.what() << endl;
	}
}

template <class ElementType>
void get(PriorityQueue<ElementType> &b)
{
	ElementType h;
	try {
		h = b.peek();
		cout << "Printing " <<  h << endl;
	}
	catch (EmptyDataCollectionException &anException)
	{
		cout << "Retrieving unsuccesfull..." << anException.what() << endl;
	}
}

template <class ElementType>
void print(PriorityQueue<ElementType> &b)
{
	b.printPriorityQueue();
}


int main()
{

	PriorityQueue<int> b1;
	for (int i = 0; i < 10; i++)
		add(b1, rand() % 10);
	print(b1);

	while(!b1.isEmpty())
	{
		get(b1);
		red(b1);
	}
	 
	b1.~PriorityQueue();
	print(b1);
	cout << endl;

	red(b1);
	get(b1);

	
	
	/*PriorityQueue<char> b1;
	for (int i = 65; i < 80; i++)
		add(b1, char(rand() % 26 + 65));
	print(b1);


	b1.~PriorityQueue();

	while(!b1.isEmpty())
		red(b1);
	red(b1);
	get(b1);*/

	
	


	system("pause");
	return 0;
}