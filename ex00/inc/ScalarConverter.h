#pragma once
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <string>

class ScalarConverter{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		ScalarConverter &operator=(const ScalarConverter &);
		~ScalarConverter();
	public:
		static void convert(const std::string &num);
};