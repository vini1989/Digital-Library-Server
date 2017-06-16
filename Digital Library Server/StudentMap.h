#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <vector>
#include "Student.h"

class StudentMap {
private:
	std::map<int, std::vector<std::string>> studentMap;
	int m_key;
	std::string m_firstName;
	std::string m_lastName;
	std::string m_department;


public:
	StudentMap();
	std::string insertStudent(std::shared_ptr<Student> &student);

	void showAllStudents();

	void showSingleStudent(int studentId);
	bool StudentMap::deleteStudent(int studentId);

	std::map<int, std::vector<std::string>> getAllStudentDetails();
	std::vector<std::string> getSingleStudentDetails(int studentId);

	std::vector<std::string> editStudent(std::shared_ptr<Student> &student);

};