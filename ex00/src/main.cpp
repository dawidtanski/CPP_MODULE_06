#include "../inc/ScalarConverter.h"

int main(int argc, char *argv[]){
	if (argc != 2)
		std::cerr << "Wrong number of arguments! Program need 1 argument to work." << std::endl;
	else{
		ScalarConverter::convert(argv[1]);
	}
}