SRC =	main.cpp \
		HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp

OBJ = $(SRC:.cpp=.o)
GCC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = unecessary_violence

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