#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct student_data {
	string first_name;
	string last_name;
};

int main() {

	//read from the file and just write everythnig to console
	ifstream file("StudentData.txt");
	string line;
	while (getline(file, line)) {
		cout << line << endl;
	}

	//wait for user input
	cout << "Press Enter to continue...";
	cin.get();
		



	return 1;
}