#pragma once
#include <iostream>

class Bureaucrat;

class AForm {
    private:
    const std::string   _NAME;
    bool                _is_signed;
    const int           _SIGN_GRADE;           
    const int           _EXEC_GRADE;
    
    public:
    AForm();
    AForm(const std::string & name, int sign_grade, int exec_grade);
    AForm(const AForm & other);
    AForm &operator=(const AForm &);
    virtual ~AForm();

    // getters
    std::string get_name() const;
    bool        get_is_signed() const;
    int         get_sign_grade() const;
    int         get_exec_grade() const;

    // Exceptions
    class GradeTooHighException : public std::exception
    {
        public:
            const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            const char* what() const throw();
    };

    // utils
    virtual void    check_grade(const Bureaucrat & bur);
    virtual void    beSigned(const Bureaucrat & bur);
    virtual void    execute(Bureaucrat const & executor) = 0;
};

std::ostream& operator<<(std::ostream & os, const AForm & form);