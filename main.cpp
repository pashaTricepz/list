#include <iostream>
#include "MyList.h"
#include "MyList.cpp"

int main() {
	MyList<int> l;
	srand(time(0)); 
	for (int i = 1; i <= 20; i++) {
		l.push_back(i);
	}
	std::cout << "My list: ";
	for (MyList<int>::iterator it = l.begin(); it != l.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << '\n';


	getchar();
	return 0;
}
