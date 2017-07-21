#include <iostream>
#include "basePlusCommissionEmployee.h"

using namespace std;

void
basePlusCommissionEmployee::setBaseSalary(double sal) {

	baseSalary = sal;
}
	
double 
basePlusCommissionEmployee::getBaseSalary() {
		
	return baseSalary;
}

double 
basePlusCommissionEmployee::earning() {
		
	return (CommissionEmployee::earning()+ getBaseSalary());

}

void 
basePlusCommissionEmployee::printEmployeeInfo() {
	cout<<"Base plus Employee class"<<endl;
	CommissionEmployee::printEmployeeInfo();
	cout<<"Base Salary	: "<<getBaseSalary()<<endl;
	//cout<<"Earning		: "<<earning()<<endl;

}

