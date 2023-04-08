#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <iostream>

#define FORM_NAME "robotomy request"
#define GRADE_TO_SIGN 72
#define GRADE_TO_EXECUTE 45

/* ==============================================
 *           Orthodox Canonical Form
 * ============================================== */
// Default constructor
RobotomyRequestForm::RobotomyRequestForm()
    : AForm(FORM_NAME, GRADE_TO_SIGN, GRADE_TO_EXECUTE, "default") {
#if DEBUG
  std::cout << "[ RobotomyRequestForm Default constructor called ]"
            << std::endl;
#endif
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& r)
    : AForm(r) {
#if DEBUG
  std::cout << "[ RobotomyRequestForm Copy constructor called ]" << std::endl;
#endif
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& r) {
#if DEBUG
  std::cout << "[ RobotomyRequestForm Copy assignment operator called ]"
            << std::endl;
#endif
  AForm::operator=(r);
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
#if DEBUG
  std::cout << "[ RobotomyRequestForm destructor called ]" << std::endl;
#endif
}

/* ==============================================
 *                  Constructor
 * ============================================== */
RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
    : AForm(FORM_NAME, GRADE_TO_SIGN, GRADE_TO_EXECUTE, target) {
#if DEBUG
  std::cout << "[ RobotomyRequestForm constructor called ]" << std::endl;
#endif
}

/* ==============================================
 *                Member functions
 * ============================================== */
// Execute Action of the form
void RobotomyRequestForm::executeAction() const {
  // Print the drilling noises
  std::cout << "BZZZZZZZ BZZZZZZZZ BZZZZZZZZ BZZZZZZZZ BZZZZZZZZ" << std::endl;
  // Randomly print either success or failure
  if (rand() % 2) {
    std::cout << this->getTarget() << " has been robotomized successfully"
              << std::endl;
  } else {
    std::cout << this->getTarget() << " robotomization failed" << std::endl;
  }
}

// Make a copy of the form
AForm* RobotomyRequestForm::makeCopy(std::string const& target) const {
  return new RobotomyRequestForm(target);
}
