CC = c++

RM = rm -f

FLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = megaphone.cpp

OBJS = $(SRC:.cpp=.o)

NAME = megaphone

$(NAME): $(OBJS)
	$(CC) -g $(FLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

# ANY FILE ENDING IN .O DEPENDS ON THE SAME FILENAME ENDING IN .C TO BE PRESENT
%o.:%c
	$(CC) $(FLAGS) $< -c
# 	$< is a wild card that means 'include the first prerequisite filename from
# the target line here'

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)


re: fclean all

.PHONY: all clean fclean re
