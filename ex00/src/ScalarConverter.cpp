#include "../inc/ScalarConverter.h"

bool isCharLiteral(const std::string &str) {
	return (str.size() == 3 && str[0] == '\'' && str[2] == '\'');
}

bool isStringANum(std::string str){
	int len = str.size();
	int	i = 0;
	int dotFlag = 0;

	if (len == 0 || str[i] == '.')
		return false;
	if (std::isdigit(str[i]) || str[i] == '-' || str[i] == '+')
		i++;
	while (i < len){
		if (!(std::isprint(str[i])))
			return false;
		if (!std::isdigit(str[i]) && !(str[i] == '.' && dotFlag == 0))
			return false;
		if (str[i] == '.'){
			if (dotFlag == 1)
				return false;
			dotFlag = 1;
		}
		i++;
	}
	if (str[len - 1] == '.')
		return false;
	return true;
}

void printChar(double value) {
	if (value < 0 || value > 127 || value != static_cast<int>(value))
		std::cout << "char: impossible" << std::endl;
	else if (value < 32 || value > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void printInt(double value) {
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()
		|| value != value) // NaN check
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void	ScalarConverter::convert(const std::string &num){
	int numlen = num.size();
	std::cout << std::fixed << std::setprecision(1);

	// Handle char literal like 'a'
	if (isCharLiteral(num)) {
		char c = num[1];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
		return;
	}

	// Handle single printable char (without quotes)
	if (numlen == 1 && std::isprint(num[0]) && !std::isdigit(num[0])) {
		char c = num[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
		return;
	}

	// Handle nan/nanf
	if (num == "nan" || num == "nanf"){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}

	// Handle inf
	if (num == "+inf" || num == "-inf" || num == "+inff" || num == "-inff" ||
		num == "inf" || num == "inff"){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (num[0] == '-'){
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		} else {
			std::cout << "float: inff" << std::endl;
			std::cout << "double: inf" << std::endl;
		}
		return;
	}

	// Handle float literal (ends with 'f')
	std::string num_str = num;
	if (numlen > 1 && num[numlen - 1] == 'f'){
		num_str = num.substr(0, numlen - 1);
	}

	if (!isStringANum(num_str)){
		std::cerr << "Given argument is not a valid literal" << std::endl;
		return;
	}

	double value = atof(num_str.c_str());

	printChar(value);
	printInt(value);
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << value << std::endl;
}