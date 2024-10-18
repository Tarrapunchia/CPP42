SRC = 	main.cpp \
		ClapTrap.cpp \

OBJ = $(SRC:.cpp=.o)
NAME = ClapTrap
GCC = g++
FLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean $(NAME)

run: re
	clear
	./$(NAME)

debug:
	$(GCC) $(FLAGS) -g $(OBJ) -o $(NAME)

.PHONY: all clean fclean re

