#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm: public AForm {
    private:
    std::string _target;

    public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string & target);
    PresidentialPardonForm(const PresidentialPardonForm & other);
    ~PresidentialPardonForm() {};

    void    execute(Bureaucrat const & executor);
};