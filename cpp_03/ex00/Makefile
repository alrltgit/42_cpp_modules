CC = c++

RM = rm -f

FLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp ClapTrap.cpp

OBJS = $(SRC:.cpp=.o)

NAME = ClapTrap

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
