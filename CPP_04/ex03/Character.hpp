#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"

class Character: public ICharacter
{
    private:
    std::string  _name;
    AMateria*    _materias[4];

    public:
    Character( void );
    Character( const std::string name);
    Character( const Character& other );
    Character &operator=( const Character& other );

    // interfac mths
    ~Character( void );
    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif