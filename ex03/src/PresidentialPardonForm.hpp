#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
class PresidentialPardonForm : public AForm {
 public:
  // Orthodox Canonical Class
  PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm& p);
  PresidentialPardonForm& operator=(const PresidentialPardonForm& p);
  ~PresidentialPardonForm();

  // Constructor
  explicit PresidentialPardonForm(const std::string& target);

 private:
  // Execute Action of the form
  void executeAction() const;
  // Make a copy of the form
  AForm* makeCopy(const std::string& target) const;
};

#endif
