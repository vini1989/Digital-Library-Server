#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "StudentMap.h" 

 StudentMap::StudentMap():
	studentMap(),
 m_key(),
m_firstName(),
m_lastName(),
m_department()
 { ; }


	std::string StudentMap::insertStudent(std::shared_ptr<Student> &student) {

		std::map<int, std::vector<std::string>>::iterator itr = studentMap.find(student->studentId());
		if (itr == studentMap.end()) {
			studentMap[student->studentId()].push_back(student->getFirstName());
			studentMap[student->studentId()].push_back(student->getLastName());
			studentMap[student->studentId()].push_back(student->getDepartment());
			return "Student Added Successfully" ;
		}
		else
		{
			return "Student already exists" ;
		}
	}

	void StudentMap::showAllStudents() {
		std::map<int, std::vector<std::string>>::iterator itr;
		std::cout << "List of all students" << std::endl;
		for (itr = studentMap.begin();itr != studentMap.end();itr++) {
			std::cout << itr->first << ": ";
			for (std::vector<std::string>::iterator it = itr->second.begin();it != itr->second.end();it++) {
				std::cout << *it << ",";
			}
		}
	}

	void StudentMap::showSingleStudent(int studentId) {
		std::map<int, std::vector<std::string>>::iterator itr = studentMap.find(studentId);
		std::cout << "Student Details are:" << std::endl;
		if (itr != studentMap.end()) {
			std::cout << itr->first << ": ";
			for (std::vector<std::string>::iterator it = itr->second.begin();it != itr->second.end();it++) {
				std::cout << *it << ",";
			}
		}
	}

	bool StudentMap::deleteStudent(int studentId) {
		bool isDelete;
		std::map<int, std::vector<std::string>>::iterator itr = studentMap.find(studentId);
		if (itr != studentMap.end()) {
			studentMap.erase(itr);
			return isDelete = true;
		}
		else isDelete = false;
	}

	std::map<int, std::vector<std::string>> StudentMap::getAllStudentDetails() {
		try {
			return studentMap;
		}
		catch (std::exception e) {
			std::cout << "Cannot return map";
		}
	}

	std::vector<std::string> StudentMap::getSingleStudentDetails(int studentId) {
		try{
		std::map<int, std::vector<std::string>>::iterator it = studentMap.find(studentId);
		if(it!=studentMap.end())
		return it->second;
		else {
			std::vector<std::string> vec;
			vec.push_back("No student found with requested id. Please enter correct id");
			return vec;
		}
		}
		catch (std::exception e) {
			//return student not found statement from here.
		}

	}

	std::vector<std::string> StudentMap::editStudent(std::shared_ptr<Student> &student) {
		std::vector<std::string> vector;
	
		//itr->second.erase;
	//	studentMap[student->studentId].at(0)= student->getFirstName();
	//studentMap[student->studentId].at(1)= student->getLastName();
	//studentMap[student->studentId].at(2)= student->getDepartment();
	std::map<int, std::vector<std::string>>::iterator itr = studentMap.find(student->studentId());
	if (itr != studentMap.end()) {
		vector.push_back(student->getFirstName());
		vector.push_back(student->getLastName());
		vector.push_back(student->getDepartment());
		itr->second = vector;
		return vector;
	}
	else {
		vector.push_back("No student found with requested id. Please enter correct id");
		return vector;
	}
	}

