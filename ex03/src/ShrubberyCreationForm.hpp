#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 public:
  // Orthodox Canonical Form
  ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm& s);
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& s);
  ~ShrubberyCreationForm();

  // Constructor
  explicit ShrubberyCreationForm(std::string const& target);

 private:
  // Execute Action of the form
  void executeAction() const;
  // Make a copy of the form
  AForm* makeCopy(std::string const& target) const;
};

#endif
