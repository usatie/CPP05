#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 public:
  // Orthodox Canonical Form
  RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm& r);
  RobotomyRequestForm& operator=(const RobotomyRequestForm& r);
  ~RobotomyRequestForm();

  // Constructor
  RobotomyRequestForm(std::string const& target);

 private:
  // Execute Action of the form
  void executeAction() const;
};

#endif
