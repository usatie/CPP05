#include "Bureaucrat.hpp"

#include <iostream>
#include <sstream>

// Default constructor
Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
#if DEBUG
  std::cout << "[ Bureaucrat Default constructor called ]" << std::endl;
#endif
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& b) : _name(b._name), _grade(b._grade) {
#if DEBUG
  std::cout << "[ Bureaucrat Copy constructor called ]" << std::endl;
#endif
}

// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b) {
#if DEBUG
  std::cout << "[ Bureaucrat Copy assignment operator called ]" << std::endl;
#endif
  if (this != &b) {
    _grade = b._grade;
    // _name = b._name ; // _name is const
  }
  return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {
#if DEBUG
  std::cout << "[ Bureaucrat destructor called ]" << std::endl;
#endif
}

// Constructor
Bureaucrat::Bureaucrat(std::string const& name, int grade)
    : _name(name), _grade(grade) {
#if DEBUG
  std::cout << "[ Bureaucrat Constructor called ]" << std::endl;
#endif
  if (_grade < _highestGrade) {
    throw Bureaucrat::GradeTooHighException(_grade);
  } else if (_grade > _lowestGrade) {
    throw Bureaucrat::GradeTooLowException(_grade);
  }
}

// Member functions
std::string const Bureaucrat::getName() const {
#if DEBUG
  std::cout << "[ Bureaucrat::getName() called ]" << std::endl;
#endif
  return _name;
}

int Bureaucrat::getGrade() const {
#if DEBUG
  std::cout << "[ Bureaucrat::getGrade() called ]" << std::endl;
#endif
  return _grade;
}

void Bureaucrat::incrementGrade() {
#if DEBUG
  std::cout << "[ Bureaucrat::incrementGrade() called ]" << std::endl;
#endif
  if (_grade == _highestGrade) {
    throw Bureaucrat::GradeTooHighException(_grade);
  } else {
    _grade--;
  }
}

void Bureaucrat::decrementGrade() {
#if DEBUG
  std::cout << "[ Bureaucrat::decrementGrade() called ]" << std::endl;
#endif
  if (_grade == _lowestGrade) {
    throw Bureaucrat::GradeTooLowException(_grade);
  } else {
    _grade++;
  }
}

// Non-member functions
std::ostream& operator<<(std::ostream& os, Bureaucrat const& b) {
  os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
  return os;
}

// GradeTooHighException
Bureaucrat::GradeTooHighException::GradeTooHighException() throw()
    : _description("Grade too high") {
#if DEBUG
  std::cout << "[ GradeTooHighException Default constructor called ]"
            << std::endl;
#endif
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {
#if DEBUG
  std::cout << "[ GradeTooHighException destructor called ]" << std::endl;
#endif
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
#if DEBUG
  std::cout << "[ GradeTooHighException::what() called ]" << std::endl;
#endif
  return _description.c_str();
}

Bureaucrat::GradeTooHighException::GradeTooHighException(int grade) throw() {
#if DEBUG
  std::cout << "[ GradeTooHighException Default constructor called ]"
            << std::endl;
#endif
  // _description
  std::ostringstream oss;
  oss << "Grade too high: " << grade;
  _description = oss.str();
}

// GradeTooLowException
Bureaucrat::GradeTooLowException::GradeTooLowException() throw()
    : _description("Grade too low") {
#if DEBUG
  std::cout << "[ GradeTooLowException Default constructor called ]"
            << std::endl;
#endif
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {
#if DEBUG
  std::cout << "[ GradeTooLowException destructor called ]" << std::endl;
#endif
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
#if DEBUG
  std::cout << "[ GradeTooLowException::what() called ]" << std::endl;
#endif
  return _description.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(int grade) throw() {
#if DEBUG
  std::cout << "[ GradeTooLowException Default constructor called ]"
            << std::endl;
#endif
  std::ostringstream oss;
  oss << "Grade too low: " << grade;
  _description = oss.str();
}
