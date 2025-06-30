SRC =	ScalarConverter.cpp \
	 	main.cpp

OBJ = $(SRC:.cpp=.o)
NAME = ScalarConverter
GCC = g++
FLAGS = -Wall -Werror -Wextra -g -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(GCC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

run: re
	clear
	./$(NAME)

debug:
	$(GCC) $(FLAGS) -g $(OBJ) -o $(NAME)

.PHONY: all clean fclean re run debug
