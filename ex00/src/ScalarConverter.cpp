#include "../inc/ScalarConverter.h"

bool	isStringANum(std::string str){
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

void	ScalarConverter::convert(const std::string &num){
	int numlen = num.size();
	std::cout << std::fixed << std::setprecision(1);

	if (numlen == 1 && std::isalpha((num[0]))){
			std::cerr << "Given argument is not a number" << std::endl;
			return ;
		}

	if (isStringANum(num)){
		if (atoi(num.c_str()) == 0){
			std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: " << atoi(num.c_str()) << std::endl;
			std::cout << "float: " << static_cast<float>(atof(num.c_str())) << "f" << std::endl;
			std::cout << "double: " << atof(num.c_str()) << std::endl;
		} else {
			std::cout << "char: *" << std::endl;
			std::cout << "int: " << atoi(num.c_str()) << std::endl;
			std::cout << "float: " << static_cast<float>(atof(num.c_str())) << "f" << std::endl;
			std::cout << "double: " << atof(num.c_str()) << std::endl;
		}
		return ;
	}
	if ( numlen && num[numlen - 1] == 'f'){
		std::string num_str = num;
		num_str.erase(numlen - 1);
		std::cout << num_str;
		if (!isStringANum(num_str)){
			std::cerr << "Given argument is not a number" << std::endl;
			return ;
		}

		std::cout << "char: *" << std::endl;
		std::cout << "int: " << atoi(num_str.c_str()) << std::endl;
		std::cout << "float: " << static_cast<float>(atof(num_str.c_str())) << "f" << std::endl;
		std::cout << "double: " << atof(num_str.c_str()) << std::endl;
		return;
	}

	if (num == "nan" || num == "nanf"){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}
	if (num == "+inf" || num == "-inf" || num == "+inff" || num == "-inff"){
		float iPos =  std::numeric_limits<double>::infinity();
		float iNeg = -std::numeric_limits<double>::infinity();

		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (num == "+inf" || num == "+inff"){
			std::cout << "float: " << static_cast<float>(iPos) << "f" << std::endl;
			std::cout << "double: " << iPos << std::endl;

		}
		else{
			std::cout << "float: " << static_cast<float>(iNeg) << "f" << std::endl;
			std::cout << "double: " << iNeg << std::endl;
		}
		return;
	}
	if (!isStringANum(num)){
			std::cerr << "Given argument is not a number" << std::endl;
			return ;
		}
}