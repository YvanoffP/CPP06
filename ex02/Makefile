SRCS			= main.cpp \
				  Base.cpp

OBJS			= $(SRCS:.cpp=.o)

CXX				= g++-11
RM				= rm -f
CXXFLAGS		= -Wall -Wextra -Werror -pedantic -I.
CPP_FLAGS       = -std=c++98

NAME			= identify

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) $(CPP_FLAGS) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re testR
