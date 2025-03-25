#pragma once
#include <iostream>

class Bureaucrat;

class Form {
    private:
    const std::string   _NAME;
    bool                _is_signed {false};
    const int           _SIGN_GRADE;           
    const int           _EXEC_GRADE;

    public:
    Form();
    Form(const std::string & name, int sign_grade, int exec_grade);
    Form(const Form & other);
    ~Form() {};

    // getters
    std::string get_name() const;
    bool        get_is_signed() const;
    int         get_sign_grade() const;
    int         get_exec_grade() const;

    // Exceptions
    class GradeTooHighException : public std::exception
    {
        public:
            const char* what() const noexcept;
    };

    class GradeTooLowException : public std::exception
    {
        public:
            const char* what() const noexcept;
    };

    // utils
    void    beSigned(const Bureaucrat & bur);
};

std::ostream& operator<<(std::ostream & os, const Form & form);