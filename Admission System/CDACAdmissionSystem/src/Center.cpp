/*
 * Center.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#include <iostream>
#include <string>

#include "Center.h"

using namespace std;

Center::Center() {
	center_id="";
	center_name="";
	address="";
	coordinator="";
	password="";
}

Center::Center(const string& ccenter_id,const string& ccenter_name,const string& caddress,const string& ccoordinator,const string& cpassword) {
	center_id=ccenter_id;
	center_name=ccenter_name;
	address=caddress;
	coordinator=ccoordinator;
	password=cpassword;
}

string& Center::getAddress() {
	return address;
}

void Center::setAddress(const string& caddress) {
	this->address = caddress;
}

string& Center::getCenterId() {
	return center_id;
}

void Center::setCenterId(const string& ccenter_id) {
	center_id = ccenter_id;
}

string& Center::getCenterName() {
	return center_name;
}

void Center::setCenterName(const string& ccenter_name) {
	center_name = ccenter_name;
}

string& Center::getCoordinator() {
	return coordinator;
}

void Center::setCoordinator(const string& ccoordinator) {
	this->coordinator = ccoordinator;
}

string& Center::getPassword() {
	return password;
}

void Center::setPassword(const string& cpassword) {
	this->password = cpassword;
}

void Center::display(){
	cout<<center_id<<", "<<center_name<<", "<<address<<", "<<coordinator<<", "<<password<<endl;
}

void Center::display_Center_capacity(vector<Capacity>& vcapacities){
	cout<<center_id<<", "<<center_name<<", "<<address<<", "<<coordinator<<", "<<password<<endl;
	map<string,int>::iterator itr = coursecapacity.begin();
	while(itr != coursecapacity.end()) {
		cout<<"   -";
		vcapacities[itr->second].display();
		itr++;
	}
}

void Center::display_Center_courses(vector<Capacity>& vcapacities){
	cout<<endl;
	cout<<center_id<<", "<<center_name<<", "<<address<<endl;
	map<string,int>::iterator itr = coursecapacity.begin();
	while(itr != coursecapacity.end()) {
		cout<<"    -";
		vcapacities[itr->second].display_centerandcourse();
		itr++;
	}
}

Center::~Center() {
	// TODO Auto-generated destructor stub
}
