#include "Character.hpp"

Character::Character( void ): _name("desichado")
{
    for (int i = 0; i < 4; i++) {
        this->_materias[i] = nullptr;
    }
}

Character::Character( const std::string name ): _name(name)
{
    for (int i = 0; i < 4; i++) {
        this->_materias[i] = nullptr;
    }
}

Character::Character( const Character& other ): _name(other._name)
{
    for (int i = 0; i < 4; i++) {
        this->_materias[i] = other._materias[i]->clone();
    }
}

Character& Character::operator=( const Character& other )
{
    if (this != &other)
    {
        _name = other._name;
        for (int i = 0; i < 4; i++) {
            if (_materias[i])
            {
                delete _materias[i];
                _materias[i] = nullptr;
            }
            if (other._materias[i])
                _materias[i] = other._materias[i]->clone();
        }
    }
    return (*this);
}

Character::~Character( void )
{
    for (int i = 0; i < 4; i++) {
        if (_materias[i])
        {
            delete _materias[i];
            _materias[i] = nullptr;
        }
    }
}

std::string const& Character::getName() const { return (_name); }

void Character::equip( AMateria* m )
{
    if (!m)
        return ;
    for (int i = 0; i < 4; i++) {
        if (!_materias[i])
        {
            _materias[i] = m->clone();
            break ;
        }
    }
}

void Character::unequip( int idx )
{
    if (idx > 3 || idx < 0)
        return ;
    _materias[idx] = nullptr;
}

void Character::use( int idx, ICharacter& target )
{
    if (idx > 3 || idx < 0)
        return ;
    _materias[idx]->use(target);
}