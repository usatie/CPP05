#include "PresidentialPardonForm.hpp"

#include <iostream>

#define FORM_NAME "PresidentialPardonForm"
#define FORM_SIGN_GRADE 25
#define FORM_EXEC_GRADE 5

/* ==============================================
 *           Orthodox Canonical Form
 * ============================================== */
PresidentialPardonForm::PresidentialPardonForm()
    : AForm(FORM_NAME, FORM_SIGN_GRADE, FORM_EXEC_GRADE, "default") {
#ifdef DEBUG
  std::cout << "[ PresidentialPardonForm Default constructor called ]"
            << std::endl;
#endif
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& p)
    : AForm(p) {
#ifdef DEBUG
  std::cout << "[ PresidentialPardonForm Copy constructor called ]"
            << std::endl;
#endif
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& p) {
#ifdef DEBUG
  std::cout << "[ PresidentialPardonForm Copy assignment operator called ]"
            << std::endl;
#endif
  AForm::operator=(p);
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
#ifdef DEBUG
  std::cout << "[ PresidentialPardonForm destructor called ]" << std::endl;
#endif
}

/* ==============================================
 *                  Constructor
 * ============================================== */
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm(FORM_NAME, FORM_SIGN_GRADE, FORM_EXEC_GRADE, target) {
#ifdef DEBUG
  std::cout << "[ PresidentialPardonForm constructor called ]" << std::endl;
#endif
}

/* ==============================================
 *                  Member Function
 * ============================================== */
void PresidentialPardonForm::executeAction() const {
  std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox."
            << std::endl;
}
