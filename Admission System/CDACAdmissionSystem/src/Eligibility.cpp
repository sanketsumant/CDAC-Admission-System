/*
 * Eligibility.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */
#include <iostream>
#include <string>

#include "Eligibility.h"

using namespace std;

Eligibility::Eligibility() {
	course_name="";
	degree="";
	min_percentage=0.0;
}

Eligibility::Eligibility(const string& ecourse_name,const string& edegree,double emin_percentage) {
	course_name=ecourse_name;
	degree=edegree;
	min_percentage=emin_percentage;
}

string& Eligibility::getCourseName() {
	return course_name;
}

void Eligibility::setCourseName(const string& ecourse_name) {
	course_name = ecourse_name;
}

string& Eligibility::getDegree() {
	return degree;
}

void Eligibility::setDegree(const string& edegree) {
	this->degree = edegree;
}

double Eligibility::getMinPercentage() {
	return min_percentage;
}

void Eligibility::setMinPercentage(double emin_percentage) {
	min_percentage = emin_percentage;
}

void Eligibility::display(){
	cout<<course_name<<", "<<degree<<", "<<min_percentage<<endl;
}

Eligibility::~Eligibility() {
	// TODO Auto-generated destructor stub
}
