#include "../inc/functions.hpp"
#include <cstdlib>
#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include <exception>

Base* generate(void){
	int randNum = rand() % 3;
	switch(randNum){
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}

// Dynamic cast is type of casting where type of objecy is checked in runtime

// In case of succesfull casting dynamic_cast returns an object, if it fails it returns NULL
void identify(Base *p){
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

// In contrast to pointer, reference cannot be null, 
// so we have to handle every of unsuccesfull casting attempt
void identify(Base& p){
	try{
		// void in case of "unused value" compilation error
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	} catch (std::exception&){}
	try{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	} catch (std::exception&){}
	try{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	} catch (std::exception&){}
}