#ifndef COMMISSION_EMPLOYEE_H
#define COMMISSION_EMPLOYEE_H

#include <string>

using namespace std;

class CommissionEmployee {



public:

	CommissionEmployee();
	CommissionEmployee(string, string, double, double, string);
	~CommissionEmployee();

	string getFirstName() const;
	void setFirstName(const string &);

	string getLastName() const;
	void setLastName(const string &);

	double getGrossSale() const;
	void setGrossSale(double);

	double getCommission() const;
	void setCommission(double);

	string getSocialSecurityNumber() const;
	void setSocialSecurityNumber(const string &);

	void printEmployeeInfo();
	double earning();

private:
	string firstName;
	string lastName;
	double grossSale;
	double commission;
	string socialSecurityNumber;

};
#endif //COMMISSION_EMPLOYEE_H
