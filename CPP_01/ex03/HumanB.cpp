#include "HumanB.hpp"

HumanB::HumanB( std::string name ): _name(name)
{
    // Weapon weapon = Weapon("No weapon");
    // this->_weapon = &weapon;
}
HumanB::HumanB( std::string name, Weapon* weapon ) : _name(name), _weapon(weapon)
{
}
void HumanB::attack()
{
    std::cout << _name << " attacks with their "
                << this->_weapon->getType() << std::endl;
}
void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}
HumanB::~HumanB()
{
}
