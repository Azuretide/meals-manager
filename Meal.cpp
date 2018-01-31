#include <iostream>
#include <string>
#include "Meal.h"

std::ostream &operator<<(std::ostream &os, const Meal &m) {
	switch (m.status) {
		case AVAILABLE:
			os << "-";
			break;
		case SELECTED:
			os << "y";
			break;
		case FORBIDDEN:
			os << "X";
			break;
	}
	return os;
}