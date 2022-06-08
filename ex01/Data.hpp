#ifndef DATA_H
# define DATA_H

# include <iostream>
# include <string>
# include <stdint.h>

class Data {

	public:
		Data ( void );
		Data ( const Data &copy );
		virtual ~Data ( void );

		Data &operator=( const Data &right );

		std::string getContent ( void ) const;
		void setContent ( const std::string content );

	private:
		std::string _content;
};

uintptr_t serialize ( Data *ptr );
Data *deserialize ( uintptr_t raw );

#endif
