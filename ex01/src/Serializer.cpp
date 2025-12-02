#include "../inc/Serializer.hpp"

// uintptr is a variable type which have always enough
// size to storage an pointer adress
// Reinterpret cast is made during compilation - compilator just prescripes code
uintptr_t Serializer::serialize(Data* ptr){

	uintptr_t ptr_res;
	ptr_res = reinterpret_cast<uintptr_t>(ptr);
	return ptr_res;
}
// reinterpret_cast - "brutally" reinterpet bits of one type
// as bits of another type

Data* Serializer::deserialize(uintptr_t raw){
	Data* res;
	res = reinterpret_cast<Data*>(raw);
	return res;
}