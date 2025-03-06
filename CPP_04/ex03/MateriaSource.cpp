#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
    for (int i = 0; i < 4; i++) {
        _materias[i] = nullptr;
    }
}

MateriaSource::MateriaSource( const MateriaSource& other )
{
    for (int i = 0; i < 4; i++) {
        _materias[i] = other._materias[i];
    }
}

MateriaSource& MateriaSource::operator=( const MateriaSource& other )
{
    if (this != &other)
    {
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

void MateriaSource::learnMateria( AMateria* m )
{
    if (!m)
        return ;
    for (int i = 0; i < 4; i++) {
        if (!_materias[i])
        {
            _materias[i] = m;
            break ;
        }
    }
}

AMateria* MateriaSource::createMateria( std::string const& type )
{
    for (int i = 0; i < 4; i++) {
        if (_materias[i] && _materias[i]->getType() == type)
            return (_materias[i]);
    }
    return nullptr;
}

MateriaSource::~MateriaSource( void )
{
    for (int i = 0; i < 4; i++) {
        if (_materias[i])
        {
            delete _materias[i];
            _materias[i] = nullptr;
        }
    }
}