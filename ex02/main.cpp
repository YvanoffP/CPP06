#include "Base.hpp"

int main ( void ) {
	Base *ptr;

	ptr = generate();
	identify(ptr);
	identify(*ptr);
    delete ptr;

	ptr = generate();
	identify(ptr);
	identify(*ptr);
    delete ptr;

	ptr = generate();
	identify(ptr);
	identify(*ptr);
    delete ptr;

	return (0);
}
