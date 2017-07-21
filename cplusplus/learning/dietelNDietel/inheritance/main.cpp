#include <iostream>


#include "CommissionEmployee/CommissionEmployee.h"
#include "basePlusCommissionEmployee/basePlusCommissionEmployee.h"

using namespace std;


int main() {




	CommissionEmployee emp1("Nilesh","Raghuvanshi",30000.0,0.8,"123456789");
	emp1.printEmployeeInfo();
	emp1.getFirstName();

	emp1.setFirstName("Jayesh");
	//emp1.setLastName("Raghuvanshi");
	//emp1.setSocialSecurityNumber("123498765");
	emp1.setGrossSale(35000);
	emp1.setCommission(0.9);

	//cout <<"Commission is "<<emp1.getCommission()<<endl;	
	emp1.printEmployeeInfo();
	cout<<"Commission employee earning is "<<emp1.earning()<<endl;

	cout<<"*****************************************************************************************************"<<endl;
	cout<<"*****************************************************************************************************"<<endl;

	basePlusCommissionEmployee emp2;
	//emp1.printEmployeeInfo();
	//emp1.getFirstName();

	emp2.setFirstName("Nilesh");
	emp2.setLastName("Raghuvanshi");
	emp2.setSocialSecurityNumber("123498765");
	emp2.setGrossSale(35000);
	emp2.setCommission(0.9);
	emp2.setBaseSalary(1000);

	//cout <<"Commission is "<<emp1.getCommission()<<endl;	
	emp2.printEmployeeInfo();
	cout<<"base plus commission employee earning is "<<emp2.earning()<<endl;

	return 0;
}
