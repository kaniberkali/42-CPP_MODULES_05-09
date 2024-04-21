NAME		= bureaucrat
SRC			= main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp Intern.cpp
OBJ			= $(SRC:.cpp=.o)
HDR			= Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp Intern.hpp
CC			= c++
RM 			= rm -rf
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ) $(HDR)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) *shrubbery
 
fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re