/*
 * Student.cpp
 *
 *  Created on: 16-Apr-2020
 *      Author: sunbeam
 */

#include <iostream>
#include <string>

#include "Student.h"
#include "Preference.h"


using namespace std;

Student::Student() {
	form_no=0;
	name="";
	rank_a=0;
	rank_b=0;
	rank_c=0;
	degree="";
	percentage=0.0;
	allocated_preference=0;
	allocated_coursename="";
	allocated_centerid="";
	payment=0.0;
	reported=0;
	prn="";
}

Student::Student(int sform_no, const string& sname, int srank_a, int srank_b, int srank_c, const string& sdegree, double spercentage,int sallocated_preference,const string& sallocated_coursename,const string& sallocated_centerid,double spayment,int sreported,const string& sprn){
	form_no=sform_no;
	name=sname;
	rank_a=srank_a;
	rank_b=srank_b;
	rank_c=srank_c;
	degree=sdegree;
	percentage=spercentage;
	allocated_preference=sallocated_preference;
	allocated_coursename=sallocated_coursename;
	allocated_centerid=sallocated_centerid;
	payment=spayment;
	reported=sreported;
	prn=sprn;
}

int Student::getform_no() {
	return form_no;
}

void Student::setform_no(int sform_no) {
	this->form_no = sform_no;
}

const string& Student::getName() const{
	return name;
}

void Student::setName(const string& sname) {
	this->name = sname;
}

int Student::getRankA() const{
	return rank_a;
}

void Student::setRankA(int srank_a)  {
	rank_a = srank_a;
}

int Student::getRankB() const {
	return rank_b;
}

void Student::setRankB(int srank_b) {
	rank_b = srank_b;
}

int Student::getRankC()  const{
	return rank_c;
}

void Student::setRankC(int srank_c) {
	rank_c = srank_c;
}

string& Student::getDegree()  {
	return degree;
}

void Student::setDegree(const string& sdegree) {
	this->degree = sdegree;
}

double Student::getDegreeMarks() {
	return percentage;
}

void Student::setDegreeMarks(double spercentage) {
	percentage = spercentage;
}

const string& Student::getAllocatedCenterId() const{
	return allocated_centerid;
}

void Student::setAllocatedCenterId(const string& sallocated_centerid) {
	allocated_centerid = sallocated_centerid;
}

const string& Student::getAllocatedCoursename()const{
	return allocated_coursename;
}

void Student::setAllocatedCoursename(const string& sallocated_coursename) {
	allocated_coursename = sallocated_coursename;
}

int Student::getAllocatedPreference() {
	return allocated_preference;
}

void Student::setAllocatedPreference(int sallocated_preference) {
	allocated_preference = sallocated_preference;
}

double Student::getPayment() const{
	return payment;
}

void Student::setPayment(double spayment) {
	this->payment = spayment;
}

string& Student::getPrn() {
	return prn;
}

void Student::setPrn(const string& sprn) {
	this->prn = sprn;
}

int Student::getReported() {
	return reported;
}

void Student::setReported(int sreported) {
	this->reported = sreported;
}

void Student::display(){
	cout<<form_no<<", "<<name<<", "<<rank_a<<", "<<rank_b<<", "<<rank_c<<", "<<degree<<", "<<percentage<<", "<<allocated_preference<<", "<<allocated_coursename<<", "<<allocated_centerid<<", "<<payment<<", "<<reported<<", "<<prn<<endl;
}

void Student::display_preferences(){
	cout<<form_no<<", "<<name<<", "<<rank_a<<", "<<rank_b<<", "<<rank_c<<", "<<degree<<", "<<percentage<<", "<<allocated_preference<<", "<<allocated_coursename<<", "<<allocated_centerid<<", "<<payment<<", "<<reported<<", "<<prn<<endl;
	for(unsigned i=0; i<student_preferences.size(); i++) {
		cout << "          - ";
		student_preferences[i].display();
	}
}


Student::~Student() {
	// TODO Auto-generated destructor stub
}
