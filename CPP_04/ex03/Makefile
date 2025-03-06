SRC = \
        Character.cpp \
        Cure.cpp \
        Ice.cpp \
        AMateria.cpp \
        MateriaSource.cpp \
		main.cpp

OBJ = $(SRC:.cpp=.o)
NAME = InterfaceAndRecap
GCC = g++
FLAGS = -Wall -Werror -Wextra -std=c++98 -g

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
