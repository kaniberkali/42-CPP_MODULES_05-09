NAME		= bureaucrat
SRC			= main.cpp Bureaucrat.cpp Form.cpp
OBJ			= $(SRC:.cpp=.o)
HDR			= Bureaucrat.hpp Form.hpp
CC			= c++
RM 			= rm -rf
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ) $(HDR)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re