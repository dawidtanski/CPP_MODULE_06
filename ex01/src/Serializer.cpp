#include "../inc/Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr){

	uintptr_t ptr_res;
	ptr_res = reinterpret_cast<uintptr_t>(ptr);
	return ptr_res;
}

Data* Serializer::deserialize(uintptr_t raw){
	Data* res;
	res = reinterpret_cast<Data*>(raw);
	return res;
}