#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
    private:
    std::string   _name;
    int           _grade;

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
            const char* what() const noexcept;
    };

    class GradeTooLowException : public std::exception
    {
        public:
            const char* what() const noexcept;
    };

};
// overload
std::ostream &operator<<(std::ostream & out, const Bureaucrat & bur);

#endif