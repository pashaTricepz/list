#include <iostream>
#include <algorithm>
#include <list>
#include "MyList.h"
#include "MyList.cpp"
#include <ranges>


int main() {
	MyList<int> l;
	for (int i = 0; i < 10; ++i) {
		l.push_back(rand() % 10);
	}
	for (MyList<int>::iterator it = l.begin(); it != l.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << '\n';

	//std::sort(l.begin(), l.end());
	

	for (MyList<int>::iterator it = l.begin(); it != l.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << '\n';
	return 0;
}
