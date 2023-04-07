#include "AForm.hpp"

#include <iostream>
#include <sstream>

/* ==============================================
 *           Orthodox Canonical Form
 * ============================================== */
// Default constructor
AForm::AForm()
    : _name("default"),
      _isSigned(false),
      _gradeToSign(LOWEST_GRADE),
      _gradeToExecute(LOWEST_GRADE),
      _target("default") {
#if DEBUG
  std::cout << "[ AForm Default constructor called ]" << std::endl;
#endif
}

// Constructor
AForm::AForm(const AForm& f)
    : _name(f._name),
      _isSigned(f._isSigned),
      _gradeToSign(f._gradeToSign),
      _gradeToExecute(f._gradeToExecute),
      _target(f._target) {
#if DEBUG
  std::cout << "[ AForm Copy constructor called ]" << std::endl;
#endif
}

// Copy assignment operator
AForm& AForm::operator=(const AForm& f) {
#if DEBUG
  std::cout << "[ AForm Copy assignment operator called ]" << std::endl;
#endif
  if (this != &f) {
    _isSigned = f._isSigned;
  }
  return *this;
}

// Destructor
AForm::~AForm() {
#if DEBUG
  std::cout << "[ AForm destructor called ]" << std::endl;
#endif
}

/* ==============================================
 *                  Constructor
 * ============================================== */
// Constructor
AForm::AForm(std::string const& name, int gradeToSign, int gradeToExecute,
             std::string const& target)
    : _name(name),
      _isSigned(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute),
      _target(target) {
#if DEBUG
  std::cout << "[ AForm Constructor called ]" << std::endl;
#endif
  // Check if grade is valid
  // Smaller number means higher grade
  if (_gradeToSign < HIGHEST_GRADE) {
    throw AForm::GradeTooHighException(_gradeToSign);
  } else if (_gradeToSign > LOWEST_GRADE) {
    throw AForm::GradeTooLowException(_gradeToSign);
  }
  if (_gradeToExecute < HIGHEST_GRADE) {
    throw AForm::GradeTooHighException(_gradeToExecute);
  } else if (_gradeToExecute > LOWEST_GRADE) {
    throw AForm::GradeTooLowException(_gradeToExecute);
  }
}

/* ==============================================
 *                    Member functions
 * ============================================== */

// Member functions
void AForm::beSigned(Bureaucrat const& b) {
#if DEBUG
  std::cout << "[ AForm beSigned called ]" << std::endl;
#endif
  if (b.getGrade() <= _gradeToSign) {
    _isSigned = true;
  } else {
    throw AForm::GradeTooLowException(b.getGrade());
  }
}

/* ==============================================
 *                    Getters
 * ============================================== */
std::string AForm::getName() const {
#if DEBUG
  std::cout << "[ AForm getName called ]" << std::endl;
#endif
  return _name;
}

bool AForm::getIsSigned() const {
#if DEBUG
  std::cout << "[ AForm getIsSigned called ]" << std::endl;
#endif
  return _isSigned;
}

int AForm::getGradeToSign() const {
#if DEBUG
  std::cout << "[ AForm getGradeToSign called ]" << std::endl;
#endif

  return _gradeToSign;
}

int AForm::getGradeToExecute() const {
#if DEBUG
  std::cout << "[ AForm getGradeToExecute called ]" << std::endl;
#endif

  return _gradeToExecute;
}

std::string AForm::getTarget() const {
#if DEBUG
  std::cout << "[ AForm getTarget called ]" << std::endl;
#endif
  return _target;
}

/* ==============================================
 *                    Exceptions
 * ============================================== */
// GradeTooHighException
AForm::GradeTooHighException::GradeTooHighException() throw()
    : _description("Grade is too high") {
#if DEBUG
  std::cout << "[ AForm GradeTooHighException Default constructor called ]"
            << std::endl;
#endif
}

AForm::GradeTooHighException::~GradeTooHighException() throw() {
#if DEBUG
  std::cout << "[ AForm GradeTooHighException destructor called ]" << std::endl;
#endif
}

const char* AForm::GradeTooHighException::what() const throw() {
#if DEBUG
  std::cout << "[ AForm GradeTooHighException what called ]" << std::endl;
#endif

  return _description.c_str();
}

AForm::GradeTooHighException::GradeTooHighException(int grade) throw() {
#if DEBUG
  std::cout << "[ AForm GradeTooHighException Constructor called ]"
            << std::endl;
#endif

  std::ostringstream oss;
  oss << "Grade is too high: " << grade;
  _description = oss.str();
}

// GradeTooLowException
AForm::GradeTooLowException::GradeTooLowException() throw()
    : _description("Grade is too low") {
#if DEBUG
  std::cout << "[ AForm GradeTooLowException Default constructor called ]"
            << std::endl;
#endif
}

AForm::GradeTooLowException::~GradeTooLowException() throw() {
#if DEBUG
  std::cout << "[ AForm GradeTooLowException destructor called ]" << std::endl;
#endif
}

const char* AForm::GradeTooLowException::what() const throw() {
#if DEBUG
  std::cout << "[ AForm GradeTooLowException what called ]" << std::endl;
#endif

  return _description.c_str();
}

AForm::GradeTooLowException::GradeTooLowException(int grade) throw() {
#if DEBUG
  std::cout << "[ AForm GradeTooLowException Constructor called ]" << std::endl;
#endif
  std::ostringstream oss;
  oss << "Grade is too low: " << grade;
  _description = oss.str();
}

/* ==============================================
 *                    Overloads
 * ============================================== */
// << overload
std::ostream& operator<<(std::ostream& os, const AForm& f) {
  os << f.getName() << " is " << (f.getIsSigned() ? "signed" : "unsigned")
     << ", grade to sign: " << f.getGradeToSign()
     << ", grade to execute: " << f.getGradeToExecute()
     << ", target: " << f.getTarget() << ".";
  return os;
}
