#include "AForm.hpp"
#include <fstream>

class RobotomyRequestForm: public AForm {
    private:
    std::string _target;

    public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string & target);
    RobotomyRequestForm(const RobotomyRequestForm & other);
    ~RobotomyRequestForm() {};

    void    execute(Bureaucrat const & executor);
};