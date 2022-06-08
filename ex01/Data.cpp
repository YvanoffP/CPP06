#include "Data.hpp"

Data::Data ( void ): _content() {}

Data::Data ( const Data &copy ): _content(copy.getContent()) {}

Data::~Data ( void ) {}

Data &Data::operator = ( const Data &right )
{
	(void)right;
	return (*this);
}

std::string Data::getContent ( void ) const
{
	return (this->_content);
}

void Data::setContent ( const std::string content )
{
	this->_content = content;
}

Data *deserialize ( uintptr_t raw )
{
	Data *ret = reinterpret_cast<Data *>(raw);
	return (ret);
}

uintptr_t serialize ( Data *ptr )
{
	uintptr_t ret = reinterpret_cast<uintptr_t>(ptr);
	return (ret);
}
