/*
 * Capacity.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */
#include <iostream>
#include <string>

#include "Capacity.h"

using namespace std;

Capacity::Capacity() {
	center_id="";
	course_name="";
	capacity=0;
	filled_capacity=0;
}

Capacity::Capacity(const string& ccenter_id,const string& ccourse_name,int ccapacity,int cfilled_capacity) {
	center_id=ccenter_id;
	course_name=ccourse_name;
	capacity=ccapacity;
	filled_capacity=cfilled_capacity;
}

int Capacity::getCapacity() {
	return capacity;
}

void Capacity::setCapacity(int ccapacity) {
	this->capacity = ccapacity;
}

string& Capacity::getCenterId() {
	return center_id;
}

void Capacity::setCenterId(const string& ccenter_id) {
	center_id = ccenter_id;
}

string& Capacity::getCourseName() {
	return course_name;
}

void Capacity::setCourseName(const string& ccourse_name) {
	course_name = ccourse_name;
}

int Capacity::getFilledCapacity() {
	return filled_capacity;
}

void Capacity::setFilledCapacity(int cfilled_capacity) {
	filled_capacity = cfilled_capacity;
}

void Capacity::display(){
	cout<<center_id<<", "<<course_name<<", "<<capacity<<", "<<filled_capacity<<endl;
}

void Capacity::display_centerandcourse(){
	cout<<course_name<<endl;
}

Capacity::~Capacity() {
	// TODO Auto-generated destructor stub
}
