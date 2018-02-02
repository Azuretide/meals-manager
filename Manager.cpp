#include <iostream>
#include <map>
#include <vector>
#include "Manager.h"

const std::string Manager::DAYS = "UMTWRFS";
const std::string Manager::TYPES = "BRLDN";

Manager::Manager(int n, bool any) : numMeals(n), isAny(any) {
	for (auto t : TYPES) {
		std::vector<Meal> mealDays;
		for (auto d : DAYS) {
			if ((d == 'S' || d == 'U') && (t == 'L' || t == 'B')) { 
				//No breakfast or lunch on weekends
				mealDays.push_back(Meal(FORBIDDEN));
			} else if (!(d == 'S' || d == 'U') && t == 'R') { 
				//No brunch on weekdays
				mealDays.push_back(Meal(FORBIDDEN));
			} else if ((d == 'F' || d == 'S') && t == 'N') {
				//No late night on Fri/Sat
				mealDays.push_back(Meal(FORBIDDEN));
			} else if (!isAny && t == 'L') {
				//No lunch for basic plans
				mealDays.push_back(Meal(FORBIDDEN));
			} else {
				mealDays.push_back(Meal(AVAILABLE));
			}
		}
		meals.push_back(mealDays);
	}
}

void Manager::selectMeal(char day, char mealType) {
	std::size_t dayIndex = DAYS.find(day);
	std::size_t typeIndex = TYPES.find(mealType);
	if (dayIndex == std::string::npos || typeIndex == std::string::npos) {
		std::cout << "Invalid command\n";
		return;
	}

	switch (meals[typeIndex][dayIndex].getStatus()) {
		case AVAILABLE:
			if (numMeals == 0) {
				std::cout << "You've run out of meals!\n";
				break;
			}
			meals[typeIndex][dayIndex].updateStatus(SELECTED);
			// Dinner Late night rule
			if (mealType == 'D' && !(day == 'F' || day == 'S')) {
				meals[TYPES.find('N')][dayIndex].updateStatus(FORBIDDEN);
			} else if (mealType == 'N') {
				meals[TYPES.find('D')][dayIndex].updateStatus(FORBIDDEN);
			}
			numMeals--;
			break;
		case SELECTED:
			meals[typeIndex][dayIndex].updateStatus(AVAILABLE);
			// Dinner Late night rule
			if (mealType == 'D' && !(day == 'F' || day == 'S')) {
				meals[TYPES.find('N')][dayIndex].updateStatus(AVAILABLE);
			} else if (mealType == 'N') {
				meals[TYPES.find('D')][dayIndex].updateStatus(AVAILABLE);
			}
			numMeals++;
			break;
		case FORBIDDEN:
			std::cout << "Selected meal can't be scheduled for you meal plan.\n";
			break;
	}
}

std::ostream &operator<<(std::ostream &os, const Manager &M) {
	os << " " << M.DAYS << "\n";
	for (int i=0; i < M.meals.size(); i++) {
		os << M.TYPES[i];
		for (int j=0; j < M.meals[0].size(); j++) {
			os << M.meals[i][j];
		}
		os << "\n";
	}
	os << "You can plan " << M.numMeals << " more meals this week.\n";

	return os;
}