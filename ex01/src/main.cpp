#include <iomanip>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
      Form form("Submission Form", 42, 42);
      std::cout << bureaucrat << std::endl;
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
      Bureaucrat bureaucrat("Tanaka", 43);
      Form form("Submission Form", 42, 42);
      std::cout << bureaucrat << std::endl;
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
      Form form("Submission Form", 42, 42);
      std::cout << bureaucrat << std::endl;
      std::cout << form << std::endl;
      bureaucrat.signForm(form);
      std::cout << form << std::endl;
      bureaucrat.signForm(form);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
}

void test_form() {
  printTitle("Test Form");
  // Test Orthodox Canonical Form
  {
    printSubtitle("Test Orthodox Canonical Form");
    Form a;
    Form b(a);
    Form c = b;
    a = c;
  }
  // Test Constructor
  {
    printSubtitle("Test Constructor");
    try {
      Form form("Submission Form", 1, 1);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test Constructor Grade Too High
  {
    printSubtitle("Test Constructor Grade Too High");
    try {
      Form form("Submission Form", 0, 1);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test Constructor Grade Too Low
  {
    printSubtitle("Test Constructor Grade Too Low");
    try {
      Form form("Submission Form", 151, 1);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test Constructor Grade Too High
  {
    printSubtitle("Test Constructor Grade Too High");
    try {
      Form form("Submission Form", 1, 0);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test Constructor Grade Too Low
  {
    printSubtitle("Test Constructor Grade Too Low");
    try {
      Form form("Submission Form", 1, 151);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test getName
  {
    printSubtitle("Test getName");
    try {
      Form form("Submission Form", 42, 42);
      std::cout << form.getName() << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test getGradeToSign
  {
    printSubtitle("Test getGradeToSign");
    try {
      Form form("Submission Form", 42, 42);
      std::cout << form.getGradeToSign() << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test getGradeToExecute
  {
    printSubtitle("Test getGradeToExecute");
    try {
      Form form("Submission Form", 42, 42);
      std::cout << form.getGradeToExecute() << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test getIsSigned
  {
    printSubtitle("Test getIsSigned");
    try {
      Form form("Submission Form", 42, 42);
      std::cout << form.getIsSigned() << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test beSigned
  {
    printSubtitle("Test beSigned");
    try {
      Form form("Submission Form", 42, 42);
      std::cout << form << std::endl;
      Bureaucrat bureaucrat("Tanaka", 42);
      form.beSigned(bureaucrat);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test beSigned Grade Too Low
  {
    printSubtitle("Test beSigned Grade Too Low");
    try {
      Form form("Submission Form", 42, 42);
      std::cout << form << std::endl;
      Bureaucrat bureaucrat("Tanaka", 43);
      form.beSigned(bureaucrat);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test beSigned Already Signed
  {
    printSubtitle("Test beSigned Already Signed");
    try {
      Form form("Submission Form", 42, 42);
      std::cout << form << std::endl;
      Bureaucrat bureaucrat("Tanaka", 42);
      form.beSigned(bureaucrat);
      std::cout << form << std::endl;
      form.beSigned(bureaucrat);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  // Test operator<<
  {
    printSubtitle("Test operator<<");
    try {
      Form form("Submission Form", 42, 42);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
}

int main(void) {
  test_bureaucrat();
  test_form();
  return 0;
}
