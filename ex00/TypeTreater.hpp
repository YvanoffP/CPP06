#ifndef TYPETREATER_H
# define TYPETREATER_H

# include <iostream>
# include <stdexcept>

class TypeTreater
{

    public:
        TypeTreater( void );
        TypeTreater( char *arg );
        TypeTreater( const TypeTreater &src );
        ~TypeTreater( void );

        TypeTreater &operator=( const TypeTreater &rhs );

        void argAnalyse( char *arg );
        void printTypes( void );

        static bool verbose;

    private:
        int     _currentType;
        char	_charValue;
        int     _intValue;
        float   _floatValue;
        double  _doubleValue;

        void    resetValues( void );
        bool    getType( char *arg );
        void	setVariable( char *arg );
        int		handleSpecialCases( char *arg ) const;
        int		handleNumericValues( char *arg ) const;
        void	printChar( void );
        bool	canConvertToChar( double number );
        void	printInt( void );
        void	printFloat( void );
        void	printDouble( void );

        static const int noType = -1;
        static const int charType = 0;
        static const int intType = 1;
        static const int floatType = 2;
        static const int doubleType = 3;

    public:
        class EmptyArg: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Please enter an input to be analysed by the converter";
                }
            };
        class CannotAnalyse: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "The input is not a valid char, int, float or double";
                }
        };

};

#endif
