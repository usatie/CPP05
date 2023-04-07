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
#if DEBUG
  std::cout << "[ Form Default constructor called ]" << std::endl;
#endif
}

// Constructor
Form::Form(const Form& f)
    : _name(f._name),
      _signed(f._signed),
      _gradeToSign(f._gradeToSign),
      _gradeToExecute(f._gradeToExecute) {
#if DEBUG
  std::cout << "[ Form Copy constructor called ]" << std::endl;
#endif
}

// Copy assignment operator
Form& Form::operator=(const Form& f) {
#if DEBUG
  std::cout << "[ Form Copy assignment operator called ]" << std::endl;
#endif
  if (this != &f) {
    _signed = f._signed;
  }
  return *this;
}

// Destructor
Form::~Form() {
#if DEBUG
  std::cout << "[ Form destructor called ]" << std::endl;
#endif
}

/* ==============================================
 *                    Member functions
 * ============================================== */
// Constructor
Form::Form(std::string const& name, int gradeToSign, int gradeToExecute)
    : _name(name),
      _signed(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
#if DEBUG
  std::cout << "[ Form Constructor called ]" << std::endl;
#endif
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
#if DEBUG
  std::cout << "[ Form beSigned called ]" << std::endl;
#endif
  if (b.getGrade() <= _gradeToSign) {
    _signed = true;
  } else {
    throw Form::GradeTooLowException(b.getGrade());
  }
}

/* ==============================================
 *                    Getters
 * ============================================== */
std::string Form::getName() const {
#if DEBUG
  std::cout << "[ Form getName called ]" << std::endl;
#endif
  return _name;
}

bool Form::getSigned() const {
#if DEBUG
  std::cout << "[ Form getSigned called ]" << std::endl;
#endif
  return _signed;
}

int Form::getGradeToSign() const {
#if DEBUG
  std::cout << "[ Form getGradeToSign called ]" << std::endl;
#endif

  return _gradeToSign;
}

int Form::getGradeToExecute() const {
#if DEBUG
  std::cout << "[ Form getGradeToExecute called ]" << std::endl;
#endif

  return _gradeToExecute;
}

/* ==============================================
 *                    Exceptions
 * ============================================== */
// GradeTooHighException
Form::GradeTooHighException::GradeTooHighException() throw()
    : _description("Grade is too high") {
#if DEBUG
  std::cout << "[ Form GradeTooHighException Default constructor called ]"
            << std::endl;
#endif
}

Form::GradeTooHighException::~GradeTooHighException() throw() {
#if DEBUG
  std::cout << "[ Form GradeTooHighException destructor called ]" << std::endl;
#endif
}

const char* Form::GradeTooHighException::what() const throw() {
#if DEBUG
  std::cout << "[ Form GradeTooHighException what called ]" << std::endl;
#endif

  return _description.c_str();
}

Form::GradeTooHighException::GradeTooHighException(int grade) throw() {
#if DEBUG
  std::cout << "[ Form GradeTooHighException Constructor called ]" << std::endl;
#endif

  std::ostringstream oss;
  oss << "Grade is too high: " << grade;
  _description = oss.str();
}

// GradeTooLowException
Form::GradeTooLowException::GradeTooLowException() throw()
    : _description("Grade is too low") {
#if DEBUG
  std::cout << "[ Form GradeTooLowException Default constructor called ]"
            << std::endl;
#endif
}

Form::GradeTooLowException::~GradeTooLowException() throw() {
#if DEBUG
  std::cout << "[ Form GradeTooLowException destructor called ]" << std::endl;
#endif
}

const char* Form::GradeTooLowException::what() const throw() {
#if DEBUG
  std::cout << "[ Form GradeTooLowException what called ]" << std::endl;
#endif

  return _description.c_str();
}

Form::GradeTooLowException::GradeTooLowException(int grade) throw() {
#if DEBUG
  std::cout << "[ Form GradeTooLowException Constructor called ]" << std::endl;
#endif
  std::ostringstream oss;
  oss << "Grade is too low: " << grade;
  _description = oss.str();
}
