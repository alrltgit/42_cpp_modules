CC = g++

RM = rm -f

FLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = Contact.cpp Phonebook.cpp main.cpp

OBJS = $(SRC:.cpp=.o)

NAME = phonebook

$(NAME): $(OBJS)
	$(CC) -g $(FLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

%o.:%c
	$(CC) $(FLAGS) $< -c

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
