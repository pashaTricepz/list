#include <iostream>
#include "MyList.h"
#include "MyList.cpp"


int main() {
	MyList<int> l;;
	for (int i = 0; i < 10; ++i) {
		l.push_back(i + 1);
	}
	for (MyList<int>::iterator it = l.begin(); it != l.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << '\n';
	return 0;
}
