#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

#include "AForm.hpp"

class Intern {
 public:
  // Orthodox Canonical Form
  Intern();
  Intern(const Intern& i);
  Intern& operator=(const Intern& i);
  ~Intern();

  // Member functions
  AForm* makeForm(const std::string& formName, const std::string& target);

 private:
  static const AForm* _forms[3];
};

// Insertion operator
std::ostream& operator<<(std::ostream& os, const Intern& i);

#endif
