#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {

	map<string, int> data;

	data["Nilesh"] = 0007;
	data["Jayesh"] = 00010;
	data["Bhavna"] = 00011;
	data["Darshana"] = 00012;
	data["Nilesh"] = 00015;
	//data.insert("Nilesh",0007);


	map<string, int>::iterator it = data.begin();

	cout <<"map size is"<<data.size()<<endl;

	for(; it!= data.end(); it++) {
		cout << "key is "<<it->first << " value is "<<it->second <<endl;

	}

	it = data.find("Nilesh");
	cout << "value is "<< it->second <<endl;
	return 0;
}
