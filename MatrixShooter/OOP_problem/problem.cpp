class first_class {
public:
	int my_first_function(second_class* object);
};

class second_class {
public:

	int my_second_function(first_class* object) {
		return 0;
	}
};

int first_class::my_first_function(second_class* object) {
	return 0;
}