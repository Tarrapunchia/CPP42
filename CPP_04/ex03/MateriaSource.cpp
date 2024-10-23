#include "MateriaSource.hpp"

#include "Character.hpp"

Character::Character() : _name("Generic Character")
{
    std::cout << "\033[1;34m[DEBUG]: Character default constructor called\033[0m" << std::endl;
    for (size_t i = 0; i < 4; i++)
        _inventory[i] = nullptr;
}

Character::Character(std::string &name) : _name(name)
{
    std::cout << "\033[1;34m[DEBUG]: Character name constructor called\033[0m" << std::endl;
    for (size_t i = 0; i < 4; i++)
        _inventory[i] = nullptr;
}

Character::Character( const Character& other )//: PARENT(other)
{
    std::cout << "\033[1;34m[DEBUG]: Character copy constructor called\033[0m" << std::endl;
    if (&other)
    {
        for (size_t i = 0; i < 4; i++)
            if (other._inventory[i])
                _inventory[i] = other._inventory[i].clone();
            else
                _inventory[i] = nullptr;
    }
}

Character &Character::operator=( const Character& e )
{
    std::cout << "\033[1;34m[DEBUG]: Character op = overload called\033[0m" << std::endl;
    if (this != &e)
    {
        _name = e._name;
        for (size_t i = 0; i < 4; i++)
            if (_inventory[i])
            {
                delete _inventory[i];
                _inventory[i] = nullptr;
            }
        for (size_t i = 0; i < 4; i++)
            if (e._inventory[i])
                _inventory[i] = e._inventory[i].clone();
    }
    return (*this);
}

Character::~Character()
{
    std::cout << "\033[1;34m[DEBUG]: Character destructor called\033[0m" << std::endl;
    for (size_t i = 0; i < 4; i++)
        if (_inventory[i])
        {
            delete _inventory[i];
            _inventory[i] = nullptr;
        }
}

std::string const &Character::getName() const { return _name; }

void Character::equip(AMateria* m) = 0
{
    for (size_t i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            break ;
        }
    }
}

void Character::unequip(int idx)
{
    if ((idx >= 0 && idx < 4) && _inventory[i])
        _inventory[i] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
    if ((idx >= 0 && idx < 4) && _inventory[i])
        _inventory[i]->use(target);
}
