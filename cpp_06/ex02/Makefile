CC = c++

RM = rm -f

FLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp \
	src/A.cpp \
	src/B.cpp \
	src/C.cpp \
	src/Base.cpp

OBJS = $(SRC:.cpp=.o)

NAME = Base

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
