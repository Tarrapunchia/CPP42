#!/bin/bash

# Controlla se è stato passato almeno un argomento
if [ $# -lt 2 ]; then
    echo "Usage: $0 executableName sourceFile1 [sourceFile2 ...]"
    exit 1
fi

# Estrai il nome dell'eseguibile
executableName="$1"
shift  # Rimuove il primo argomento, lasciando solo i file sorgente

# Creazione del Makefile
makefile="Makefile"
{
    echo "SRC = \\"
    for srcFile in "$@"; do
        echo "        ${srcFile} \\"
    done
    echo ""
    echo "OBJ = \$(SRC:.cpp=.o)"
    echo "NAME = ${executableName}"
    echo "GCC = g++"
    echo "FLAGS = -Wall -Werror -Wextra -std=c++98"
    echo ""
    echo "all: \$(NAME)"
    echo ""
    echo "\$(NAME): \$(OBJ)"
    echo "	\$(GCC) \$(FLAGS) \$(OBJ) -o \$(NAME)"
    echo ""
    echo "clean:"
    echo "	rm -f \$(OBJ)"
    echo ""
    echo "fclean: clean"
    echo "	rm -rf \$(NAME)"
    echo ""
    echo "re: fclean \$(NAME)"
    echo ""
    echo "run: re"
    echo "	clear"
    echo "	./\$(NAME)"
    echo ""
    echo "debug:"
    echo "	\$(GCC) \$(FLAGS) -g \$(OBJ) -o \$(NAME)"
    echo ""
    echo ".PHONY: all clean fclean re run debug"
} > "$makefile"

echo "Creato $makefile per l'eseguibile '$executableName' con i file sorgente: $@"
