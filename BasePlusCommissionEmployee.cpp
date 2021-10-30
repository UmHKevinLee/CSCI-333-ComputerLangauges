// BasePlusCommissionEmployee member-function definitions.
#include <iomanip>
#include <sstream>
#include "BasePlusCommissionEmployee.h"
using namespace std;

// constructor 
BasePlusCommissionEmployee::BasePlusCommissionEmployee(
   const string& first, const string& last, const string& ssn,
   double sales, double rate, double salary)
   : CommissionEmployee(first, last, ssn, sales, rate) {
   setBaseSalary(salary);
}

// set base salary
void BasePlusCommissionEmployee::setBaseSalary(double salary) {
   baseSalary = salary;
}

// return base salary
double BasePlusCommissionEmployee::getBaseSalary() const {
   return baseSalary;
}

// calculate earnings;
// override virtual function earnings in CommissionEmployee
double BasePlusCommissionEmployee::earnings() const {
   return getBaseSalary() + CommissionEmployee::earnings();
}

// return a string representation of a BasePlusCommissionEmployee
string BasePlusCommissionEmployee::toString() const {
   ostringstream output;
   output << fixed << setprecision(2);
   output << "base-salaried " << CommissionEmployee::toString()
      << "; base salary: " << getBaseSalary();
   return output.str();
}
