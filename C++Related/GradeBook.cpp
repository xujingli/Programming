//GradeBook.cpp
#include <iostream>
#include <string>
using namespace std;

#include "GradeBook.h"

GradeBook::GradeBook(string name)
{
	setCourseName(name); 
}
	
void GradeBook::setCourseName(string name){
	courseName = name;
}
	
string GradeBook::getCourseName(){
	return courseName;
}
	
void GradeBook::displayMessage(){
	cout << "Welcome to the grade book for\n" 
		<< getCourseName() << "!" <<endl;
}
