SRC = \
        Animal.cpp \
        Cat.cpp \
        Dog.cpp \
        WrongAnimal.cpp \
        WrongCat.cpp \
        main.cpp \

OBJ = $(SRC:.cpp=.o)
NAME = Animals
GCC = g++
FLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) $(FLAGS) $(OBJ) -o $(NAME)

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
