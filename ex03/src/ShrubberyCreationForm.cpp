#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>

#define FORM_NAME "shrubbery creation"
#define GRADE_TO_SIGN 145
#define GRADE_TO_EXECUTE 137
#define RESET "\033[m"
#define RED "\033[0;31m"

/* ==============================================
 *           Orthodox Canonical Form
 * ============================================== */
// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm(FORM_NAME, GRADE_TO_SIGN, GRADE_TO_EXECUTE, "default") {
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
    : AForm(FORM_NAME, GRADE_TO_SIGN, GRADE_TO_EXECUTE, target) {
#if DEBUG
  std::cout << "[ ShrubberyCreationForm constructor called ]" << std::endl;
#endif
}

/* ==============================================
 *                Member functions
 * ============================================== */
void ShrubberyCreationForm::executeAction() const {
#if DEBUG
  std::cout << "[ ShrubberyCreationForm executeAction called ]" << std::endl;
#endif
  std::ofstream ofs((getTarget() + "_shrubbery").c_str());
  if (!ofs) {
    std::cerr << RED << "Error: cannot open file " << getTarget()
              << "_shrubbery" << std::endl
              << RESET;
    return;
  }
  // Create a file with the target name and write ASCII trees in it
  // This ASCII tree is from http://www.ascii-art.de/ascii/s/shrubbery.txt
  // (see below)
  /*
             {{ }{
          {{}}}{{
        {{}}{}}
           }}}}{
          {{}}}
         }{{}{}}
           {{}{}}
         }}{{}}
          {{}}{{
           \  /
        .-''| |``-.
       '-._/_o_\_.-'
        `._     _.'
         | :F_P: |
         `._    .'
            `--'

                     .o00o
                   o000000oo
                  00000000000o
                 00000000000000
              oooooo  00000000  o88o
           ooOOOOOOOoo  ```''  888888
         OOOOOOOOOOOO'.qQQQQq. `8888'
        oOOOOOOOOOO'.QQQQQQQQQQ/.88'
        OOOOOOOOOO'.QQQQQQQQQQ/ /q
         OOOOOOOOO QQQQQQQQQQ/ /QQ
           OOOOOOOOO `QQQQQQ/ /QQ'
             OO:F_P:O `QQQ/  /Q'
                \\. \ |  // |
                d\ \\\|_////
                qP| \\ _' `|Ob
                   \  / \  \Op
                   |  | O| |
           _       /\. \_/ /\
            `---__/|_\\   //|  __
                  `-'  `-'`-'-'
   */
  ofs << "             {{ }{" << std::endl;
  ofs << "          {{}}}{{" << std::endl;
  ofs << "        {{}}{}{}" << std::endl;
  ofs << "           }}}}{" << std::endl;
  ofs << "          {{}}}" << std::endl;
  ofs << "         }{{}{}" << std::endl;
  ofs << "           {{}{}" << std::endl;
  ofs << "         }}{{}}" << std::endl;
  ofs << "          {{}}{{" << std::endl;
  ofs << "           \\  /" << std::endl;
  ofs << "        .-''| |``-." << std::endl;
  ofs << "       '-._/_o_\\_.-'" << std::endl;
  ofs << "        `._     _.'" << std::endl;
  ofs << "         | :F_P: |" << std::endl;
  ofs << "         `._    .'" << std::endl;
  ofs << "            `--'" << std::endl;
  ofs << std::endl;
  ofs << std::endl;
  ofs << "                     .o00o" << std::endl;
  ofs << "                   o000000oo" << std::endl;
  ofs << "                  00000000000o" << std::endl;
  ofs << "                 00000000000000" << std::endl;
  ofs << "              oooooo  00000000  o88o" << std::endl;
  ofs << "           ooOOOOOOOoo  ```''  888888" << std::endl;
  ofs << "         OOOOOOOOOOOO'.qQQQQq. `8888'" << std::endl;
  ofs << "        oOOOOOOOOOO'.QQQQQQQQQQ/.88'" << std::endl;
  ofs << "        OOOOOOOOOO'.QQQQQQQQQQ/ /q" << std::endl;
  ofs << "         OOOOOOOOO QQQQQQQQQQ/ /QQ" << std::endl;
  ofs << "           OOOOOOOOO `QQQQQQ/ /QQ'" << std::endl;
  ofs << "             OO:F_P:O `QQQ/  /Q'" << std::endl;
  ofs << "                \\. \\ |  // |" << std::endl;
  ofs << "                d\\ \\\\\\|_////" << std::endl;
  ofs << "                qP| \\\\ _' `|Ob" << std::endl;
  ofs << "                   \\  / \\  \\Op" << std::endl;
  ofs << "                   |  | O| |" << std::endl;
  ofs << "           _       \\. \\_/ /\\" << std::endl;
  ofs << "            `---__/|_\\\\   //|  __" << std::endl;
  ofs << "                  `-'  `-'`-'-'" << std::endl;
  ofs.close();
}

AForm* ShrubberyCreationForm::makeCopy(std::string const& target) const {
  return new ShrubberyCreationForm(target);
}
