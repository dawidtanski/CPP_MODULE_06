#include "../inc/ScalarConverter.h"

void	ScalarConverter::convert(const std::string &num){
	if (atoi(num.c_str()) == 0)
	{
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << atoi(num.c_str()) << std::endl;
		std::cout << "float: " << static_cast<float>(atof(num.c_str())) << "f" << std::endl;
		std::cout << "double: " << atof(num.c_str()) << std::endl;
	}
}