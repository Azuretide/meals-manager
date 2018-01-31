enum MStatus {
	AVAILABLE,
	SELECTED,
	FORBIDDEN
};

class Meal {
	MStatus status;

	public:
		Meal(MStatus s) : status(s) {}
		void updateStatus(MStatus s) { status = s;}
		friend std::ostream &operator<<(std::ostream &os, const Meal &m);
};