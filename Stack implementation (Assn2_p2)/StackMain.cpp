#include "Stack.h"
#include <iostream>
using namespace std;

int main()
{
	Stack s;

	for (int i = 0; i < 5; i++)
	{
		s.push(i);
		cout << s.peek() << endl;
	}
	cout << endl << endl;
	cout << endl << endl;
	if (s.isEmpty())
		cout << "Empty" << endl;
	else
		cout << "Not Empty" << endl;

	


	system("pause");
	return 0;
}