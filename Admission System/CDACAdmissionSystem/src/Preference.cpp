/*
 * Preference.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */
#include <string>
#include <iostream>

#include "Preference.h"

using namespace std;

Preference::Preference() {
	student_formno=0;
	preference_no=0;
	course_name="";
	center_id="";
}

Preference::Preference(int pstudent_formno,int ppreference_no,const string& pcourse_name,const string& pcenter_id) {
	student_formno=pstudent_formno;
	preference_no=ppreference_no;
	course_name=pcourse_name;
	center_id=pcenter_id;
}

string& Preference::getCenterId()  {
	return center_id;
}

void Preference::setCenterId(const string& pcenter_id) {
	center_id = pcenter_id;
}

string& Preference::getCourseName()  {
	return course_name;
}

void Preference::setCourseName(const string& pcourse_name) {
	course_name = pcourse_name;
}

int Preference::getPreferenceNo() {
	return preference_no;
}

void Preference::setPreferenceNo(int ppreference_no) {
	preference_no = ppreference_no;
}

int Preference::getStudentFormno() const {
	return student_formno;
}

void Preference::setStudentFormno(int pstudent_formno) {
	student_formno = pstudent_formno;
}

void Preference::display(){
	cout<<student_formno<<", "<<preference_no<<", "<<course_name<<", "<<center_id<<endl;
}

Preference::~Preference() {
	// TODO Auto-generated destructor stub
}
