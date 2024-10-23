#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria * materias[4];
public:
    MateriaSource( void );
    MateriaSource( const MateriaSource& other );
    MateriaSource &operator=( const MateriaSource& e );
    ~MateriaSource( void );
    virtual void learnMateria(AMateria*);
    virtual AMateria* createMateria(std::string const & type);
};

#endif
