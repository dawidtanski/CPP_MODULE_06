#include "../inc/Data.hpp"
#include "../inc/Serializer.hpp"

int main(void){

	Data data1;
	data1.name = "David";
	data1.age = 29;


	Data* ptr = &data1;
	Data* ptr2;

	uintptr_t ptr_adress_0;


	ptr_adress_0 = Serializer::serialize(ptr);
	ptr2 = Serializer::deserialize(ptr_adress_0);

	std::cout << "Original ptr: " << ptr << std::endl;
	std::cout << "Deserialized ptr: " << ptr2 <<std::endl;


	return 0;
}