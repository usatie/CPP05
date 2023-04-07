#include "Form.hpp"

#include <iostream>
#include <sstream>

/* ==============================================
 *           Orthodox Canonical Form
 * ============================================== */
// Default constructor
Form::Form()
    : _name("default"),
      _signed(false),
      _gradeToSign(LOWEST_GRADE),
      _gradeToExecute(LOWEST_GRADE) {
  std::cout << "[ Form Default constructor called ]" << std::endl;
}

// Constructor
Form::Form(const Form& f)
    : _name(f._name),
      _signed(f._signed),
      _gradeToSign(f._gradeToSign),
      _gradeToExecute(f._gradeToExecute) {
  std::cout << "[ Form Copy constructor called ]" << std::endl;
}

// Copy assignment operator
Form& Form::operator=(const Form& f) {
  std::cout << "[ Form Copy assignment operator called ]" << std::endl;
  if (this != &f) {
    _signed = f._signed;
  }
  return *this;
}

// Destructor
Form::~Form() { std::cout << "[ Form destructor called ]" << std::endl; }

/* ==============================================
 *                    Member functions
 * ============================================== */
// Constructor
Form::Form(std::string const& name, int gradeToSign, int gradeToExecute)
    : _name(name),
      _signed(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  std::cout << "[ Form Constructor called ]" << std::endl;
  // Check if grade is valid
  // Smaller number means higher grade
  if (_gradeToSign < HIGHEST_GRADE) {
    throw Form::GradeTooHighException(_gradeToSign);
  } else if (_gradeToSign > LOWEST_GRADE) {
    throw Form::GradeTooLowException(_gradeToSign);
  }
  if (_gradeToExecute < HIGHEST_GRADE) {
    throw Form::GradeTooHighException(_gradeToExecute);
  } else if (_gradeToExecute > LOWEST_GRADE) {
    throw Form::GradeTooLowException(_gradeToExecute);
  }
}

// Member functions
void Form::beSigned(Bureaucrat const& b) {
  if (b.getGrade() <= _gradeToSign) {
    _signed = true;
  } else {
    throw Form::GradeTooLowException(b.getGrade());
  }
}

/* ==============================================
 *                    Getters
 * ============================================== */
std::string Form::getName() const { return _name; }

bool Form::getSigned() const { return _signed; }

int Form::getGradeToSign() const { return _gradeToSign; }

int Form::getGradeToExecute() const { return _gradeToExecute; }

/* ==============================================
 *                    Exceptions
 * ============================================== */
// GradeTooHighException
Form::GradeTooHighException::GradeTooHighException() throw()
    : _description("Grade is too high") {}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

const char* Form::GradeTooHighException::what() const throw() {
  return _description.c_str();
}

Form::GradeTooHighException::GradeTooHighException(int grade) throw() {
  std::ostringstream oss;
  oss << "Grade is too high: " << grade;
  _description = oss.str();
}

// GradeTooLowException
Form::GradeTooLowException::GradeTooLowException() throw()
    : _description("Grade is too low") {}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char* Form::GradeTooLowException::what() const throw() {
  return _description.c_str();
}

Form::GradeTooLowException::GradeTooLowException(int grade) throw() {
  std::ostringstream oss;
  oss << "Grade is too low: " << grade;
  _description = oss.str();
}
