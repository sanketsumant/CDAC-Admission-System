/*
 * Course.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */
#include <iostream>
#include <string>

#include "Course.h"
#include "Eligibility.h"

using namespace std;

Course::Course() {
	id=0;
	name="";
	fees=0.0;
	ccat_section="";
}

Course::Course(int cid,string cname,double cfees,const string& cccat_section){
	id=cid;
	name=cname;
	fees=cfees;
	ccat_section=cccat_section;
}

string& Course::getCcatSection() {
	return ccat_section;
}

void Course::setCcatSection(const string& cccat_section) {
	ccat_section = cccat_section;
}

double Course::getFees() {
	return fees;
}

void Course::setFees(double cfees) {
	this->fees = cfees;
}

int Course::getId() {
	return id;
}

void Course::setId(int cid) {
	this->id = cid;
}

string& Course::getName(){
	return name;
}

void Course::setName(const string& cname) {
	this->name = cname;
}

void Course::display(){
	cout<<id<<", "<<name<<", "<<fees<<", "<<ccat_section<<", "<<endl;
}

void Course::display_eligibilities(){
	cout<<id<<", "<<name<<", "<<fees<<", "<<ccat_section<<", "<<endl;
	for(unsigned i=0; i<eligibilities.size(); i++) {
		cout << "          - ";
		eligibilities[i].display();
	}
}

void Course::display_course_capacity(vector<Capacity>& vcapacities){
	cout<<id<<", "<<name<<", "<<fees<<", "<<ccat_section<<", "<<endl;
	map<string,int>::iterator itr = centercapacity.begin();
	while(itr != centercapacity.end()) {
		cout<<"    -";
		vcapacities[itr->second].display();
		itr++;
	}
}

vector<Eligibility>& Course::getEligibilityvector(){
	return eligibilities;
}

Course::~Course() {
	// TODO Auto-generated destructor stub
}
