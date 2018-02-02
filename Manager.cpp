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

std::ostream &operator<<(std::ostream &os, const Manager &M) {
	os << " " << M.DAYS << "\n";
	for (int i=0; i < M.meals.size(); i++) {
		os << M.TYPES[i];
		for (int j=0; j < M.meals[0].size(); j++) {
			os << M.meals[i][j];
		}
		os << "\n";
	}
	os << "You can plan " << M.numMeals << " more meals this week.";

	return os;
}