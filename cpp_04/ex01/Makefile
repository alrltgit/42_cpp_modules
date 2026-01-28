CC = c++

RM = rm -f

FLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp src/Animal.cpp src/Cat.cpp src/Dog.cpp \
	src/WrongAnimal.cpp src/WrongCat.cpp src/Brain.cpp

OBJS = $(SRC:.cpp=.o)

NAME = Animal

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
