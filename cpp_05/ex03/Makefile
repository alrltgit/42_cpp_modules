CC = c++

RM = rm -f

FLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp \
	src/Bureaucrat.cpp \
	src/AForm.cpp \
	src/PresidentialPardonForm.cpp \
	src/RobotomyRequestForm.cpp \
	src/ShrubberyCreationForm.cpp \
	src/Intern.cpp

OBJS = $(SRC:.cpp=.o)

NAME = Intern

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
