#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
    private:
    const std::string   _name;
    int                 _grade;

    public:
    Bureaucrat( void );
    Bureaucrat( const std::string& name, const int grade );
    Bureaucrat( const Bureaucrat& other );
    Bureaucrat& operator=( const Bureaucrat& other );
    ~Bureaucrat( void );

    // Getters
    const std::string&  getName() const;
    int                 getGrade() const;

    // Setters
    void                decreaseGrade();
    void                increaseGrade();

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

};
// overload
std::ostream &operator<<(std::ostream & out, const Bureaucrat & bur);

#endif