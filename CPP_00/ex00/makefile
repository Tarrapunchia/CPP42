SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)
GCC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = megaphone

all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re