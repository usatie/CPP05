#include "ShrubberyCreationForm.hpp"

#include <iostream>

#define GRADE_TO_SIGN 145
#define GRADE_TO_EXECUTE 137

/* ==============================================
 *           Orthodox Canonical Form
 * ============================================== */
// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", GRADE_TO_SIGN, GRADE_TO_EXECUTE,
            "default") {
#if DEBUG
  std::cout << "[ ShrubberyCreationForm Default constructor called ]"
            << std::endl;
#endif
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s)
    : AForm(s) {
#if DEBUG
  std::cout << "[ ShrubberyCreationForm Copy constructor called ]" << std::endl;
#endif
}

// Copy assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& s) {
#if DEBUG
  std::cout << "[ ShrubberyCreationForm Copy assignment operator called ]"
            << std::endl;
#endif
  AForm::operator=(s);
  return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
#if DEBUG
  std::cout << "[ ShrubberyCreationForm destructor called ]" << std::endl;
#endif
}

/* ==============================================
 *                  Constructor
 * ============================================== */
ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
    : AForm("ShrubberyCreationForm", GRADE_TO_SIGN, GRADE_TO_EXECUTE, target) {
#if DEBUG
  std::cout << "[ ShrubberyCreationForm constructor called ]" << std::endl;
#endif
}
