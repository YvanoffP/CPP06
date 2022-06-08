#include "Data.hpp"

int main ( void )
{
	Data data;

	data.setContent("no u");
	std::cout << "----------- CLASS DATA -----------" << std::endl;
	std::cout << "Block Address : " << &data << std::endl;
	std::cout << "Content : " << data.getContent() << std::endl;

	uintptr_t intptr = serialize(&data);
	std::cout << "----------- SERIALIZE ------------" << std::endl;
	std::cout << "Value uintptr : " << intptr << std::endl;

	Data *dataptr = deserialize(intptr);
	std::cout << "----------- DESERIALIZE ----------" << std::endl;
	std::cout << "New Block Address : " << dataptr << std::endl;
	std::cout << "New Block Content : " << dataptr->getContent() << std::endl;


	return (0);
}
