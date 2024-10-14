SRC = src/main.cpp \
      src/Contact.cpp \
      src/PhoneBook.cpp

INC = "./inc"
OBJ_DIR = obj
OBJ = $(patsubst src/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

GCC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -I$(INC)

NAME = PhoneBook

all: $(NAME)

# Compila il programma finale
$(NAME): $(OBJ)
	$(GCC) $(FLAGS) $(OBJ) -o $(NAME)

# Regola per compilare i singoli file .o nella cartella obj
$(OBJ_DIR)/%.o: src/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(GCC) $(FLAGS) -c $< -o $@

# Pulizia dei file oggetto
clean:
	rm -f $(OBJ_DIR)/*.o

# Pulizia completa
fclean: clean
	rm -rf $(OBJ_DIR) $(NAME)

# Rigenera tutto
re: fclean all

.PHONY: all clean fclean re
