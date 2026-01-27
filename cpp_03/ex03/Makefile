CC = c++

RM = rm -f

FLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp src/ClapTrap.cpp src/ScavTrap.cpp src/FragTrap.cpp src/DiamondTrap.cpp

OBJS = $(SRC:.cpp=.o)

NAME = DiamondTrap

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
