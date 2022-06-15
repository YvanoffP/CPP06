#include <cmath>
#include <string>
#include "utils.hpp"
#include "TypeTreater.hpp"

/*==============================================================*
 *                      Constructors/Destructors                *
 *==============================================================*/

TypeTreater::TypeTreater( void )
{
    if (TypeTreater::verbose)
        std::cout << "Default constructor for TypeTreater called" << std::endl;
    return ;
}

TypeTreater::TypeTreater( char *arg )
{
    this->argAnalyse(arg);
    if (TypeTreater::verbose)
    {
        std::cout << "Char* constructor for TypeTreater called" << std::endl;
    }
	return;
}

TypeTreater::TypeTreater( const TypeTreater &src )
{
    if (TypeTreater::verbose)
    {
		std::cout << "Copy constructor for TypeTreater called" << std::endl;
    }
	*this = src;
	return;
}

TypeTreater::~TypeTreater( void )
{
	if (TypeTreater::verbose)
    {
		std::cout << "Destructor for TypeTreater called" << std::endl;
    }
	return;
}

/*==============================================================*
 *                      Operator Overload                       *
 *==============================================================*/

TypeTreater &	TypeTreater::operator=( TypeTreater const & rhs )
{
	if (TypeTreater::verbose)
		std::cout << "Assignement operator for TypeTreater called" << std::endl;
	this->_currentType = rhs._currentType;
	this->_charValue = rhs._charValue;
	this->_intValue = rhs._intValue;
	this->_floatValue = rhs._floatValue;
	this->_doubleValue = rhs._doubleValue;
	return *this;
}

/*==============================================================*
 *                      Functions                               *
 *==============================================================*/

void	TypeTreater::resetValues( void )
{
	this->_currentType = TypeTreater::noType;
	this->_charValue = 0;
	this->_intValue = 0;
	this->_floatValue = 0;
	this->_doubleValue = 0;
}

void	TypeTreater::argAnalyse( char *arg )
{
	if (arg[0] == 0)
		throw TypeTreater::EmptyArg();
	if (!this->getType(arg))
		throw TypeTreater::CannotAnalyse();
	this->setVariable(arg);
}

void	TypeTreater::setVariable( char *arg )
{
	if (this->_currentType == TypeTreater::charType)
	{
		if (TypeTreater::verbose)
			std::cout << "Selected char type" << std::endl;
		this->_charValue = arg[0];
	}
	else if (this->_currentType == TypeTreater::intType)
	{
		if (TypeTreater::verbose)
			std::cout << "Selected int type" << std::endl;
		this->_intValue = atoi(arg);
	}
	else if (this->_currentType == TypeTreater::floatType)
	{
		if (TypeTreater::verbose)
			std::cout << "Selected float type" << std::endl;
		this->_floatValue = atof(arg);
	}
	else if (this->_currentType == TypeTreater::doubleType)
	{
		if (TypeTreater::verbose)
			std::cout << "Selected double type" << std::endl;
		this->_doubleValue = atof(arg);
	}
}

int		TypeTreater::handleSpecialCases( char *arg ) const
{
	const std::string	special_doubles[] =
	{
		"inf", "+inf", "-inf", "nan"
	};
	const std::string	special_floats[] =
	{
		"inff", "+inff", "-inff", "nanf"
	};
	for (int i = 0; i < 4; i++)
	{
		if (special_doubles[i] == arg)
			return TypeTreater::doubleType;
		else if (special_floats[i] == arg)
			return TypeTreater::floatType;
	}
	return TypeTreater::noType;
}

int		TypeTreater::handleNumericValues( char *arg ) const
{
	int	i = 0;
	int	dotCount = 0;
	if (arg[0] == '-' && arg[1])
		i++;
	if (arg[i] == '.' && (arg[i + 1] == 'f' || arg[i + 1] == 0))
		return (TypeTreater::noType);
	while (arg[i] == '.' || ft_isdigit(arg[i]))
	{
		if (arg[i] == '.')
			dotCount++;
		if (dotCount > 1)
			return TypeTreater::noType;
		i++;
	}
	if (!arg[i])
	{
		if (dotCount == 1)
			return TypeTreater::doubleType;
		return TypeTreater::intType;
	}
	else if (arg[i] == 'f' && !arg[i + 1] && dotCount == 1)
		return TypeTreater::floatType;
	return TypeTreater::noType;
}

void	TypeTreater::printChar( void )
{
	if (this->_currentType == TypeTreater::intType)
	{
		if (this->canConvertToChar(this->_intValue))
			std::cout << "char: " << static_cast<char>(this->_intValue)
				<< std::endl;
	}
	else if (this->_currentType == TypeTreater::floatType)
	{
		if (this->canConvertToChar(this->_floatValue))
			std::cout << "char: " << static_cast<char>(this->_floatValue)
				<< std::endl;
	}
	else if (this->_currentType == TypeTreater::doubleType)
	{
		if (this->canConvertToChar(this->_doubleValue))
			std::cout << "char: " << static_cast<char>(this->_doubleValue)
				<< std::endl;
	}
	else
		std::cout << "char: " << this->_charValue << std::endl;
}

bool	TypeTreater::canConvertToChar( double number )
{
	if (number - static_cast<int>(number) != 0 || number > 127 || number < 0)
		std::cout << "char: impossible" << std::endl;
	else if (number <= 31 || number == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		return true;
	return false;
}

void	TypeTreater::printInt( void )
{
	if (this->_currentType == TypeTreater::charType)
		std::cout << "int: " << static_cast<int>(this->_charValue)
			<< std::endl;
	else if (this->_currentType == TypeTreater::intType)
		std::cout << "int: " << this->_intValue << std::endl;
	else if (this->_currentType == TypeTreater::floatType)
	{
		if (canConvertToInt(this->_floatValue))
			std::cout << "int: " << static_cast<int>(this->_floatValue)
				<< std::endl;
		else
			std::cout << "int: impossible" << std::endl;
	}
	else if (this->_currentType == TypeTreater::doubleType)
	{
		if (canConvertToInt(this->_doubleValue))
			std::cout << "int: " << static_cast<int>(this->_doubleValue)
				<< std::endl;
		else
			std::cout << "int: impossible" << std::endl;
	}
}

void	TypeTreater::printFloat( void )
{
	if (this->_currentType == TypeTreater::charType)
		std::cout << "float: " << static_cast<float>(this->_charValue) << ".0f"
			<< std::endl;
	else if (this->_currentType == TypeTreater::intType)
		std::cout << "float: " << static_cast<float>(this->_intValue) << ".0f"
			<< std::endl;
	else if (this->_currentType == TypeTreater::floatType)
		std::cout << "float: " << this->_floatValue
			<< printDotZero(static_cast<float>(this->_floatValue)) << "f"
			<< std::endl;
	else if (this->_currentType == TypeTreater::doubleType)
	{
		if (canConvertToFloat(this->_doubleValue))
			std::cout << "float: " << static_cast<float>(this->_doubleValue)
				<< printDotZero(static_cast<float>(this->_doubleValue)) << "f"
				<< std::endl;
		else
			std::cout << "float: impossible" << std::endl;
	}
}

void	TypeTreater::printDouble( void )
{
	if (this->_currentType == TypeTreater::charType)
		std::cout << "double: " << static_cast<double>(this->_charValue)
			 << ".0" << std::endl;
	else if (this->_currentType == TypeTreater::intType)
		std::cout << "double: " << static_cast<double>(this->_intValue)
			<< ".0" << std::endl;
	else if (this->_currentType == TypeTreater::floatType)
		std::cout << "double: " << static_cast<double>(this->_floatValue)
			<< printDotZero(static_cast<double>(this->_floatValue))
			<< std::endl;
	else if (this->_currentType == TypeTreater::doubleType)
		std::cout << "double: " << this->_doubleValue
			<< printDotZero(static_cast<double>(this->_doubleValue))
			<< std::endl;
}

bool	TypeTreater::getType( char* input )
{
	this->_currentType = handleSpecialCases(input);
	if (this->_currentType != TypeTreater::noType)
		return true;
	if ((input[0] >= '0' && input[0] <= '9') || input[0] == '-'
			|| input[0] == '.')
	{
		this->_currentType = handleNumericValues(input);
		if (this->_currentType != TypeTreater::noType)
			return true;
	}
	if (input[1])
		return false;
	this->_currentType = TypeTreater::charType;
	return true;
}

void	TypeTreater::printTypes( void )
{
	if (this->_currentType == TypeTreater::noType)
		std::cout << "No type set" << std::endl;
	this->printChar();
	this->printInt();
	this->printFloat();
	this->printDouble();
}

/*==============================================================*
 *                      VERBOSE                                 *
 *==============================================================*/

// set to true to activate verbose mode
bool	TypeTreater::verbose = false;
