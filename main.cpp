#include <iostream>
#include <map>
#include <vector>
#include <string>
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

	std::cout << "Welcome to Meals Manager! Enter \"help\" for command details.\n";
	std::string doc = "<day><meal> Schedules the entered meal or unschedules if"
	 "meal is already selected. Enter day and meal as 1 character abbrevations "
	 "as shown in the interface.\n"
	 "q Exits the program.\n help Displays this help message.\n";
	while (true) {
		std::cout << std::endl << core;

		std::string command;
		std::cin >> command;
		for (auto & c: command) c = toupper(c);
		if (command == "Q") {
			break;
		} else if (command == "HELP") {
			std::cout << doc;
		} else if (command.length() == 2) {
			core.selectMeal(command[0], command[1]);
		} else {
			std::cout << "Invalid command\n";
		}
	}

	return 0;
}