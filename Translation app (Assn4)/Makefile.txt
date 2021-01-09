all: translate

translate: TransApp.o BST.h BSTNode.h ElementDoesNotExistInBSTException.o ElementAlreadyExistsInBSTException.o
	g++ -Wall -o translate TransApp.o ElementDoesNotExistInBSTException.o ElementAlreadyExistsInBSTException.o

TransApp.o: TransApp.cpp
	g++ -c -std=c++98 TransApp.cpp

ElementDoesNotExistInBSTException.o: ElementDoesNotExistInBSTException.cpp ElementDoesNotExistInBSTException.h
	g++ -c ElementDoesNotExistInBSTException.cpp

ElementAlreadyExistsInBSTException.o: ElementAlreadyExistsInBSTException.cpp ElementAlreadyExistsInBSTException.h
	g++ -c ElementAlreadyExistsInBSTException.cpp

clean:
	rm -f translate *.o