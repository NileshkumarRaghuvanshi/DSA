#include <iostream>
#include <unordered_map>
#include <map>
#include <string>


using namespace std;



int main() {

	unordered_map<string, int> data;
	data["Nilesh"] = 12;
	data["Darshana"] = 14;
	data["Apexa"] = 15;
	data["Neha"] = 16;


	unordered_map<string,int>::iterator it;

	for(it = data.begin(); it!=data.end(); it++)
		cout<<it->first<<" "<<it->second<<endl;


	it = data.find("Apexa");
	if(it != data.end() )
		cout<<it->second<<endl;
	else
		cout<<"Element is not present"<<endl;
	return 0;

}
