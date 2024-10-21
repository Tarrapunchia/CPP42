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
}

$className::$className( const $className& other )
{
//	values = other.values;
}

$className &${className}::operator=( const $className& e )
{
    return (*this);
}

$className::~$className()
{
}
EOL

    # Stampa messaggio di conferma
    echo "Creati ${hppFile} e ${cppFile}"
done
