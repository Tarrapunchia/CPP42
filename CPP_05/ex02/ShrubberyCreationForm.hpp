#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm {
    private:
    std::string _target;

    public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string & target);
    ShrubberyCreationForm(const ShrubberyCreationForm & other);
    ~ShrubberyCreationForm() {};

    void    execute(Bureaucrat const & executor);
};