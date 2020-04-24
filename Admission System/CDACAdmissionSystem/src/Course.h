/*
 * Course.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */
#include <string>
#include <vector>
#include <map>

#include "Eligibility.h"
#include "Capacity.h"

#ifndef COURSE_H_
#define COURSE_H_

using namespace std;

class Course {
private:
	int id;
	string name;
	double fees;
	string ccat_section;

public:
	vector<Eligibility> eligibilities;
	map<string,int> centercapacity;

public:
	Course();
	Course(int cid,string cname,double cfees,const string& cccat_section);

	string& getCcatSection();
	void setCcatSection(const string& cccat_section);
	double getFees();
	void setFees(double cfees);
	int getId();
	void setId(int cid);
	string& getName();
	void setName(const string& cname);

	vector<Eligibility>& getEligibilityvector();
	void display();
	void display_eligibilities();
	void display_course_capacity(vector<Capacity>& vcapacities);

	~Course();

};

#endif /* COURSE_H_ */
