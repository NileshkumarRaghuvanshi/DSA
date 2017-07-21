#include "first.h"

using namespace std;



test::test() {

	cout <<"hi this is constructor"<<endl;
}

test::~test() {

	cout<<"Hi this is destructor"<<endl;
}

void 
test::setData(int data) {

	this->data = data;
}

void
test::printData() {

	cout << "the data is "<<data<<endl;
}
