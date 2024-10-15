SRC =	tests.cpp \
		Account.cpp \

OBJ = $(SRC:.cpp=.o)
GCC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = test

all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re