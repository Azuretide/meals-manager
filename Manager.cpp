#include <map>
#include <vector>
#include "Meal.h"
#include "Manager.h"


const std::string Manager::DAYS = "UMTWRFS";
const std::string Manager::TYPES = "BRLDN";

Manager::Manager(int n, bool any) : numMeals(n), isAny(any) {
	for (char& d : DAYS) {
		for (char& t : TYPES) {
			meals[d][t] = Meal(AVAILABLE);
		}
	}
}

std::ostream &operator<<(std::ostream &os, const Manager &m) {
	
}