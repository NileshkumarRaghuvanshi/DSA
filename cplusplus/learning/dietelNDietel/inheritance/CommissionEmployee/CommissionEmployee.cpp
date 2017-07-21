#include "CommissionEmployee.h"
#include <iostream>
#include <cstdio>


CommissionEmployee::CommissionEmployee() {

	cout <<"This is default constructor"<<endl;
}

CommissionEmployee::CommissionEmployee(string first, string last, double sale, double comm, string ssn) {


	cout<<"This is constructor"<<endl;

	setFirstName(first);
	setLastName(last);
	setGrossSale(sale);
	setCommission(comm);
	setSocialSecurityNumber(ssn);
}

CommissionEmployee::~CommissionEmployee() {

	cout<<"This is destructor"<<endl;
}

string CommissionEmployee::getFirstName() const {

	//cout <<"hi there!"<<endl;
	return firstName;
}
	
void 
CommissionEmployee::setFirstName(const string &name) {

	firstName = name;

}

string 
CommissionEmployee::getLastName() const {

	return lastName;
}

void 
CommissionEmployee::setLastName(const string &name)  {

	lastName = name;
}


double
CommissionEmployee:: getGrossSale() const {

	return grossSale;

}

void 
CommissionEmployee::setGrossSale(double sale) {


	grossSale = sale;
}

double 
CommissionEmployee::getCommission() const {

	return commission;

}
void 
CommissionEmployee::setCommission(double commission) {

	cout<<"Commission is "<<fixed<<commission<<endl;
	printf("Commission is %lf\n",commission);
	this->commission = commission;
}

string 
CommissionEmployee::getSocialSecurityNumber() const {

	return socialSecurityNumber;
}

void 
CommissionEmployee::setSocialSecurityNumber(const string &ssn) {


	socialSecurityNumber = ssn;
}


void CommissionEmployee::printEmployeeInfo() {

	cout<<"Name 		: "<<getFirstName()<<" "<<getLastName()<<endl;
	cout<<"gross Sale 	: "<<getGrossSale()<<endl;
	cout<<"Commission 	: "<<getCommission()<<endl;
	cout<<"SSN 		: "<<getSocialSecurityNumber()<<endl;
	//cout<<"Earning		: "<<earning()<<endl;
}

	
double CommissionEmployee::earning() {

	return getGrossSale()*getCommission();
}

