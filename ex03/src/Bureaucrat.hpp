#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

// To avoid circular dependencies
class AForm;

class Bureaucrat {
 private:
  std::string const _name;
  int _grade;

 public:
  // Orthodox Canonical Form
  Bureaucrat();
  Bureaucrat(const Bureaucrat& b);
  Bureaucrat& operator=(const Bureaucrat& b);
  ~Bureaucrat();

  // Constructor
  Bureaucrat(std::string const& name, int grade);

  // Member functions
  void incrementGrade();
  void decrementGrade();
  void signForm(AForm& form) const;
  void executeForm(AForm const& form) const;

  // Getters
  std::string const getName() const;
  int getGrade() const;

  // Exceptions
  class GradeTooHighException : public std::exception {
   public:
    // According to subject PDF, exception classes don't have to be designed
    // in Orthodox Canonical Form
    GradeTooHighException() throw();  // throw() is a C++98 thing. It's not
                                      // needed in C++11. It's a hint to the
                                      // compiler that the function will not
                                      // throw an exception.
    virtual ~GradeTooHighException() throw();
    // what() is a virtual function in std::exception
    virtual const char* what() const throw();
    // Constructor
    explicit GradeTooHighException(int grade) throw();

   private:
    std::string _description;
  };

  class GradeTooLowException : public std::exception {
   public:
    // std::exception
    GradeTooLowException() throw();
    virtual ~GradeTooLowException() throw();
    // what() is a virtual function in std::exception
    virtual const char* what() const throw();
    // Constructor
    explicit GradeTooLowException(int grade) throw();

   private:
    std::string _description;
  };
};

// Insertion operator
std::ostream& operator<<(std::ostream& os, Bureaucrat const& b);

#endif
