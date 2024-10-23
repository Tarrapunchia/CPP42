#!/bin/bash

# Funzione per convertire CamelCase in UPPER_SNAKE_CASE
convert_to_upper_snake_case() {
    echo "$1" | sed -E 's/([a-z])([A-Z])/\1_\2/g' | tr '[:lower:]' '[:upper:]'
}

# Controlla se è stato passato almeno un argomento
if [ $# -eq 0 ]; then
    echo "Usage: $0 className1 [className2 ...]"
    exit 1
fi

# Cicla su ogni nome classe passato come argomento
for className in "$@"; do
    # Crea il nome dei file .hpp e .cpp
    hppFile="${className}.hpp"
    cppFile="${className}.cpp"
    
    # Trasforma il nome della classe in UPPER_SNAKE_CASE per l'header guard
    upperSnakeCase=$(convert_to_upper_snake_case "$className")

    # Contenuto del file .hpp
    cat <<EOL > "$hppFile"
#ifndef ${upperSnakeCase}_HPP
# define ${upperSnakeCase}_HPP

# include <iostream>

class $className
{
private:

public:
    $className( void );
    $className( const $className& other );
    $className &operator=( const $className& e );
    ~$className( void );
};

#endif
EOL

    # Contenuto del file .cpp
    cat <<EOL > "$cppFile"
#include "${className}.hpp"

$className::$className()
{
    std::cout << "\033[1;34m[DEBUG]: $className default constructor called\033[0m" << std::endl;
}

$className::$className( const $className& other )//: PARENT(other)
{
    std::cout << "\033[1;34m[DEBUG]: $className default constructor called\033[0m" << std::endl;
}

$className &${className}::operator=( const $className& e )
{
    std::cout << "\033[1;34m[DEBUG]: $className op = overload called\033[0m" << std::endl;
    //if (this != &e)
    //    type = e.type;
    return (*this);
}

$className::~$className()
{
    std::cout << "\033[1;34m[DEBUG]: $className destructor called\033[0m" << std::endl;
}
EOL

    # Stampa messaggio di conferma
    echo "Creati ${hppFile} e ${cppFile}"
done
