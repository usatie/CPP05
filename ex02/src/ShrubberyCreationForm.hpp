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
  // Member functions
  void executeAction() const;
};

#endif
