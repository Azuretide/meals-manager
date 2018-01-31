#include <iostream>
#include <map>
#include <vector>
#include "Meal.h"


int main() {
	std::string str = "abcde";
	for (char& c : str) {
		std::cout << c;
	}

	return 0;
}