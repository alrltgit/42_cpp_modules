CC = c++

RM = rm -f

FLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = megaphone.cpp

OBJS = $(SRC:.cpp=.o)

NAME = megaphone

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
