SRC = 	main.cpp \
		Fixed.cpp

OBJ = $(SRC:.cpp=.o)
NAME = FIXED_POINT
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
	@./$(NAME)

.PHONY: all clean fclean re

