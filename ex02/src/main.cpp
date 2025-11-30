#include "../inc/functions.hpp"
#include <cstdlib>


int main(void){
	srand(time(NULL));

	Base * base1 = generate();
	Base * base2 = generate();
	Base * base3 = generate();


	std::cout << "Base1 pointer: ";
	identify(base1);
	std::cout << "Base2 pointer: ";
	identify(base2);
	std::cout << "Base3 pointer: ";
	identify(base3);
	std::cout << "Base1 reference: ";
	identify(*base1);
	std::cout << "Base2 reference: ";
	identify(*base2);
	std::cout << "Base3 reference: ";
	identify(*base3);

	delete base1;
	delete base2;
	delete base3;
}

