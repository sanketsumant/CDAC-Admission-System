/*
 * Student.h
 *
 *  Created on: 16-Apr-2020
 *      Author: sunbeam
 */

#include <string>
#include <vector>

#include "Preference.h"


#ifndef STUDENT_H_
#define STUDENT_H_

using namespace std;

class Student {
private:
	int form_no;
	string name;
	int rank_a;
	int rank_b;
	int rank_c;
	string degree;
	double percentage;
	int allocated_preference;
	string allocated_coursename;
	string allocated_centerid;
	double payment;
	int reported;
	string prn;

public:
	vector<Preference> student_preferences;

public:
	Student();
	Student(int sform_no, const string& sname, int srank_a, int srank_b, int srank_c, const string& sdegree, double spercentage,int sallocated_preference,const string& sallocated_coursename,const string& sallocated_centerid,double spayment,int sreported,const string& sprn);

	int getform_no();
	const string& getName() const;
	int getRankA()const;
	int getRankB()const;
	int getRankC()const;
	string& getDegree();
	double getDegreeMarks();

	void setform_no(int sform_no);
	void setName(const string& sname);
	void setRankA(int srank_a);
	void setRankB(int srank_b);
	void setRankC(int srank_c);
	void setDegree(const string& sdegree);
	void setDegreeMarks(double sdegreeMarks);
	const string& getAllocatedCenterId() const;
	void setAllocatedCenterId(const string& sallocated_centerid);
	const string& getAllocatedCoursename() const;
	void setAllocatedCoursename(const string& sallocated_coursename);
	int getAllocatedPreference();
	void setAllocatedPreference(int sallocated_preference);
	double getPayment() const;
	void setPayment(double spayment);
	string& getPrn();
	void setPrn(const string& sprn);
	int getReported();
	void setReported(int reported);

	void display();
	void display_preferences();

	~Student();

};

//Student studentobj;


#endif /* STUDENT_H_ */
