#include "Intern.hpp"

#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/* ==============================================
 *           Static variables
 * ============================================== */
const AForm* Intern::_forms[3] = {new ShrubberyCreationForm(),
                                  new RobotomyRequestForm(),
                                  new PresidentialPardonForm()};

/* ==============================================
 *           Orthodox Canonical Form
 * ============================================== */
// Default constructor
Intern::Intern() {
#ifdef DEBUG
  std::cout << "[ Intern Default constructor called ]" << std::endl;
#endif
}

// Copy constructor
Intern::Intern(const Intern& i) {
#ifdef DEBUG
  std::cout << "[ Intern Copy constructor called ]" << std::endl;
#endif
  (void)i;
}

// Assignation operator overload
Intern& Intern::operator=(const Intern& i) {
#ifdef DEBUG
  std::cout << "[ Intern Copy assignment operator called ]" << std::endl;
#endif
  (void)i;
  return *this;
}

// Destructor
Intern::~Intern() {
#ifdef DEBUG
  std::cout << "[ Intern destructor called ]" << std::endl;
#endif
}

/* ==============================================
 *           Member functions
 * ============================================== */
AForm* Intern::makeForm(const std::string& formName,
                        const std::string& target) {
  for (int i = 0; i < 3; i++) {
    if (formName == _forms[i]->getName()) {
      std::cout << "Intern creates " << formName << std::endl;
      return _forms[i]->makeCopy(target);
    }
  }
  std::cout << "Intern can't create " << formName << std::endl;
  return NULL;
}

/* ==============================================
 *                    Overloads
 * ============================================== */
// << overload
std::ostream& operator<<(std::ostream& os, const Intern& i) {
  (void)i;
  os << "Intern";
  return os;
}
