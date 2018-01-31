# include "Meal.h"

class Manager {
	int numMeals;
	bool isAny;
	std::vector<std::vector<Meal>> meals;

	static const std::string DAYS;
	static const std::string TYPES;

	public:
		Manager(int n, bool any);
		void selectMeal(char day, char mealType);
		friend std::ostream &operator<<(std::ostream &os, const Manager &m);
}