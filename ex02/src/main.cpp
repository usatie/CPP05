#include <iomanip>
#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define RESET "\033[m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define BOLD "\033[1m"

// print title in green color surrounded by '='
void printTitle(std::string const& title) {
  // set color to green
  std::cout << GREEN << BOLD;
  // print '='
  std::cout << std::setfill('=') << std::setw(80) << "" << std::endl;
  // print title at the center
  std::cout << std::setfill(' ') << std::setw(40 - title.length() / 2) << ""
            << title << std::endl;
  // print '='
  std::cout << std::setfill('=') << std::setw(80) << "" << std::endl;
  // reset color
  std::cout << RESET << std::setfill(' ') << std::setw(0);
}

// print test subtitle in white color surrounded by '-'
void printSubtitle(std::string const& subtitle) {
  // print '-'
  std::cout << std::setfill('-') << std::setw(80) << "" << std::endl;
  // print subtitle at the center
  std::cout << std::setfill(' ') << std::setw(40 - subtitle.length() / 2) << ""
            << subtitle << std::endl;
  // print '-'
  std::cout << std::setfill('-') << std::setw(80) << "" << std::endl;
  // reset color
  std::cout << RESET << std::setfill(' ') << std::setw(0);
}

void test_bureaucrat() {
  printTitle("Test Bureaucrat");
  // Test Orthodox Canonical Form
  {
    printSubtitle("Test Orthodox Canonical Form");
    Bureaucrat a;
    Bureaucrat b(a);
    Bureaucrat c = b;
    a = c;
  }
  // Test Constructor
  {
    printSubtitle("Test Constructor");
    try {
      Bureaucrat bureaucrat("Tanaka", 1);
      std::cout << bureaucrat << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test Constructor Grade Too High
  {
    printSubtitle("Test Constructor Grade Too High");
    try {
      Bureaucrat bureaucrat("Tanaka", 0);
      std::cout << bureaucrat << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test Constructor Grade Too Low
  {
    printSubtitle("Test Constructor Grade Too Low");
    try {
      Bureaucrat bureaucrat("Tanaka", 151);
      std::cout << bureaucrat << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test getName
  {
    printSubtitle("Test getName");
    try {
      Bureaucrat bureaucrat("Tanaka", 42);
      std::cout << bureaucrat.getName() << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test getGrade
  {
    printSubtitle("Test getGrade");
    try {
      Bureaucrat bureaucrat("Shun Usami", 42);
      std::cout << bureaucrat.getGrade() << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test Increment
  {
    printSubtitle("Test Increment");
    try {
      Bureaucrat bureaucrat("Tanaka", 42);
      std::cout << bureaucrat << std::endl;
      bureaucrat.incrementGrade();
      std::cout << bureaucrat << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test Decrement
  {
    printSubtitle("Test Decrement");
    try {
      Bureaucrat bureaucrat("Tanaka", 42);
      std::cout << bureaucrat << std::endl;
      bureaucrat.decrementGrade();
      std::cout << bureaucrat << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test Increment Grade Too High
  {
    printSubtitle("Test Increment Grade Too High");
    try {
      Bureaucrat bureaucrat("Tanaka", 1);
      std::cout << bureaucrat << std::endl;
      bureaucrat.incrementGrade();
      std::cout << bureaucrat << std::endl;
      bureaucrat.incrementGrade();
      std::cout << bureaucrat << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test Decrement Grade Too Low
  {
    printSubtitle("Test Decrement Grade Too Low");
    try {
      Bureaucrat bureaucrat("Tanaka", 150);
      std::cout << bureaucrat << std::endl;
      bureaucrat.decrementGrade();
      std::cout << bureaucrat << std::endl;
      bureaucrat.decrementGrade();
      std::cout << bureaucrat << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test Sign Form
  {
    printSubtitle("Test Sign Form");
    try {
      Bureaucrat bureaucrat("Tanaka", 42);
      std::cout << bureaucrat << std::endl;
      RobotomyRequestForm form("Pawapoke-kun");
      std::cout << form << std::endl;
      bureaucrat.signForm(form);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test Sign Form Grade Too Low
  {
    printSubtitle("Test Sign Form Grade Too Low");
    try {
      Bureaucrat bureaucrat("Tanaka", 150);
      std::cout << bureaucrat << std::endl;
      RobotomyRequestForm form("Pawapoke-kun");
      std::cout << form << std::endl;
      bureaucrat.signForm(form);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test Sign Form Already Signed
  {
    printSubtitle("Test Sign Form Already Signed");
    try {
      Bureaucrat bureaucrat("Tanaka", 42);
      std::cout << bureaucrat << std::endl;
      RobotomyRequestForm form("Pawapoke-kun");
      std::cout << form << std::endl;
      bureaucrat.signForm(form);
      std::cout << form << std::endl;
      bureaucrat.signForm(form);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test Execute Form
  {
    printSubtitle("Test Execute Form");
    try {
      Bureaucrat bureaucrat("Tanaka", 42);
      std::cout << bureaucrat << std::endl;
      RobotomyRequestForm form("Pawapoke-kun");
      std::cout << form << std::endl;
      bureaucrat.signForm(form);
      std::cout << form << std::endl;
      bureaucrat.executeForm(form);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test Execute Form Grade Too Low
  {
    printSubtitle("Test Execute Form Grade Too Low");
    try {
      Bureaucrat bureaucrat("Tanaka", 150);
      Bureaucrat signer("Suzuki", 42);
      std::cout << bureaucrat << std::endl;
      std::cout << signer << std::endl;
      RobotomyRequestForm form("Pawapoke-kun");
      std::cout << form << std::endl;
      signer.signForm(form);
      std::cout << form << std::endl;
      bureaucrat.executeForm(form);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test Execute Form Not Signed
  {
    printSubtitle("Test Execute Form Not Signed");
    try {
      Bureaucrat bureaucrat("Tanaka", 42);
      std::cout << bureaucrat << std::endl;
      RobotomyRequestForm form("Pawapoke-kun");
      std::cout << form << std::endl;
      bureaucrat.executeForm(form);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
}

void test_shrubbery_creation_form() {
  printTitle("Test Shrubbery Creation Form");
  // Test Orthodox Canonical Form
  {
    printSubtitle("Test Orthodox Canonical Form");
    ShrubberyCreationForm a;
    ShrubberyCreationForm b(a);
    ShrubberyCreationForm c = b;
    a = c;
  }
  // Test Constructor
  {
    printSubtitle("Test Constructor");
    try {
      ShrubberyCreationForm form("home");
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test Execute
  {
    printSubtitle("Test Execute");
    try {
      ShrubberyCreationForm form("home");
      Bureaucrat bureaucrat("Tanaka", 42);
      std::cout << form << std::endl;
      std::cout << bureaucrat << std::endl;
      form.beSigned(bureaucrat);
      form.execute(bureaucrat);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test Execute Grade Too Low
  {
    printSubtitle("Test Execute Grade Too Low");
    try {
      ShrubberyCreationForm form("home");
      Bureaucrat bureaucrat("Tanaka", 150);
      std::cout << form << std::endl;
      std::cout << bureaucrat << std::endl;
      form.execute(bureaucrat);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test Execute Form Not Signed
  {
    printSubtitle("Test Execute Form Not Signed");
    try {
      ShrubberyCreationForm form("home");
      Bureaucrat bureaucrat("Tanaka", 42);
      std::cout << form << std::endl;
      std::cout << bureaucrat << std::endl;
      form.execute(bureaucrat);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
}

void test_robotomy_request_form() {
  printTitle("Test Robotomy Request Form");
  // Test Orthodox Canonical Form
  {
    printSubtitle("Test Orthodox Canonical Form");
    RobotomyRequestForm a;
    RobotomyRequestForm b(a);
    RobotomyRequestForm c = b;
    a = c;
  }
  // Test Constructor
  {
    printSubtitle("Test Constructor");
    try {
      RobotomyRequestForm form("Pawapoke-kun");
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test Execute
  {
    printSubtitle("Test Execute");
    try {
      RobotomyRequestForm form("Pawapoke-kun");
      Bureaucrat bureaucrat("Tanaka", 42);
      std::cout << form << std::endl;
      std::cout << bureaucrat << std::endl;
      form.beSigned(bureaucrat);
      // Execute 10 times
      for (int i = 0; i < 10; i++) {
        form.execute(bureaucrat);
      }
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test Execute Grade Too Low
  {
    printSubtitle("Test Execute Grade Too Low");
    try {
      RobotomyRequestForm form("Pawapoke-kun");
      Bureaucrat bureaucrat("Tanaka", 150);
      std::cout << form << std::endl;
      std::cout << bureaucrat << std::endl;
      form.execute(bureaucrat);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test Execute Form Not Signed
  {
    printSubtitle("Test Execute Form Not Signed");
    try {
      RobotomyRequestForm form("Pawapoke-kun");
      Bureaucrat bureaucrat("Tanaka", 42);
      std::cout << form << std::endl;
      std::cout << bureaucrat << std::endl;
      form.execute(bureaucrat);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
}

void test_presidential_pardon_form() {
  printTitle("Test Presidential Pardon Form");
  // Test Orthodox Canonical Form
  {
    printSubtitle("Test Orthodox Canonical Form");
    PresidentialPardonForm a;
    PresidentialPardonForm b(a);
    PresidentialPardonForm c = b;
    a = c;
  }
  // Test Constructor
  {
    printSubtitle("Test Constructor");
    try {
      PresidentialPardonForm form("Trillian");
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test Execute
  {
    printSubtitle("Test Execute");
    try {
      PresidentialPardonForm form("Trillian");
      Bureaucrat bureaucrat("Tanaka", 1);
      std::cout << form << std::endl;
      std::cout << bureaucrat << std::endl;
      form.beSigned(bureaucrat);
      form.execute(bureaucrat);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test Execute Grade Too Low
  {
    printSubtitle("Test Execute Grade Too Low");
    try {
      PresidentialPardonForm form("Trillian");
      Bureaucrat bureaucrat("Tanaka", 150);
      std::cout << form << std::endl;
      std::cout << bureaucrat << std::endl;
      form.execute(bureaucrat);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test Execute Form Not Signed
  {
    printSubtitle("Test Execute Form Not Signed");
    try {
      PresidentialPardonForm form("Trillian");
      Bureaucrat bureaucrat("Tanaka", 42);
      std::cout << form << std::endl;
      std::cout << bureaucrat << std::endl;
      form.execute(bureaucrat);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
}

int main(void) {
  // Set random seed for RobotomyRequestForm
  srand((unsigned int)time(NULL));
  test_bureaucrat();
  test_shrubbery_creation_form();
  test_robotomy_request_form();
  test_presidential_pardon_form();
  return 0;
}
