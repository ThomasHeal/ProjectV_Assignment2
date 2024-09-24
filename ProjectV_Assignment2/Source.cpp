#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

/// <summary>
/// Student structure, store student first and last name as strings
/// </summary>
struct STUDENT_DATA {
	string first_name;
	string last_name;
};

/// <summary>
/// Read student name + emails from the student data emails file
/// </summary>
void readEmails() {
	ifstream emailFile("StudentData_Emails.txt");
	string line;
	if (emailFile.is_open()) {
		while (getline(emailFile, line)) {
			cout << line << endl; //print out the name and email on each line of document
		}
		emailFile.close();
	}
	else {
		cerr << "Error: Unable to open file." << endl;
	}
}

#define Pre_Release //define pre-release mode

int main() {
#ifdef Pre_Release
	cout << "Running Pre-Release" << endl;
	readEmails(); //read emails from the file if in pre-release mode
#else
	cout << "Running Standard Version" << endl;
#endif


	vector<STUDENT_DATA> student_list;

	//Read student data from the "StudentData.txt" file
	ifstream file("StudentData.txt");
	string line;

	if (file.is_open()) {
		while (getline(file, line)) {
			STUDENT_DATA newStudent; //create new student data
			stringstream ss(line);
			getline(ss, newStudent.first_name, ','); //read first name, store it in new student first_name
			getline(ss, newStudent.last_name, ','); //read last name, store it in new student last_name
			student_list.push_back(newStudent); //add new student to the list
		}
		file.close();
	}
	else {
		cout << "Error: Unable to open file." << endl;
		return 1;
	}

	

#ifdef _DEBUG
	//print out the student list
	for (int i = 0; i < student_list.size(); i++) {
		cout << student_list[i].first_name << " " << student_list[i].last_name << endl;
	}
#endif

	cin.get();

	return 1;
}