// CommissionEmployee class member-function definitions.
#include <iomanip>
#include <sstream>
#include "CommissionEmployee.h" // CommissionEmployee class definition
using namespace std;

// constructor 
CommissionEmployee::CommissionEmployee(const string &first,
   const string &last, const string &ssn, double sales, double rate)
   : Employee(first, last, ssn) {
   setGrossSales(sales);
   setCommissionRate(rate);
}

// set gross sales amount
void CommissionEmployee::setGrossSales(double sales) {
   grossSales = sales;
}

// return gross sales amount
double CommissionEmployee::getGrossSales() const { return grossSales; }

// set commission rate
void CommissionEmployee::setCommissionRate(double rate) {
   commissionRate = rate;
}

// return commission rate
double CommissionEmployee::getCommissionRate() const {
   return commissionRate;
}

// calculate earnings; override pure virtual function earnings in Employee
double CommissionEmployee::earnings() const {
   return getCommissionRate() * getGrossSales();
}

// return a string representation of CommissionEmployee's information 
string CommissionEmployee::toString() const {
   ostringstream output;
   output << fixed << setprecision(2);
   output << "commission employee: " << Employee::toString()
      << "\ngross sales: " << getGrossSales()
      << "; commission rate: " << getCommissionRate();
   return output.str();
}
