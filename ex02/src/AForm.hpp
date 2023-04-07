#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

class AForm {
 private:
  const std::string _name;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExecute;
  const std::string _target;

 public:
  // Orthodox Canonical Form
  AForm();
  AForm(const AForm& f);
  AForm& operator=(const AForm& f);
  virtual ~AForm();

  // Constructor
  AForm(std::string const& name, int gradeToSign, int gradeToExecute,
        std::string const& target);

  // Member functions
  void beSigned(const Bureaucrat& b);

  // Getters
  std::string getName() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
  std::string getTarget() const;

  // Exceptions
  class GradeTooHighException : public std::exception {
   public:
    // According to subject PDF, exception classes don't have to be designed
    // in Orthodox Canonical AForm
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
std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
