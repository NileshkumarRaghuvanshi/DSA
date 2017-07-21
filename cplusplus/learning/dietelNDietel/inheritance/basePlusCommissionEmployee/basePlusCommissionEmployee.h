#include <iostream>

#include "../CommissionEmployee/CommissionEmployee.h"

class basePlusCommissionEmployee : public CommissionEmployee {


public:
	void setBaseSalary(double sal);
	double getBaseSalary();
	double earning();
	void printEmployeeInfo();

private:
	double baseSalary;
};
