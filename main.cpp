#include <iostream>
#include <map>
#include <vector>
#include "Manager.h"


int main() {
	int choice;
	std::cout << "Select your meal plan: \n1.Basic 10\n2.Any 10\n3.Basic 12\n"
	<< "4.Any 12\n5.Basic 14\n6. Any 14\n7. Full 19\n";
	std::cin >> choice;

	std::map<int,std::string> cMapping = {
		{1, "Basic 10"},
		{2, "Any 10"},
		{3, "Basic 12"},
		{4, "Any 12"},
		{5, "Basic 14"},
		{6, "Any 14"},
		{7, "Full 19"}
	};

	std::string any;
	std::string numMeals;
	std::string::size_type pos = cMapping[choice].find(' ');
	any = cMapping[choice].substr(0, pos);
	numMeals = cMapping[choice].substr(pos+1);
	
	Manager core = Manager(stoi(numMeals), any != "Basic");
	std::cout << core;

	return 0;
}