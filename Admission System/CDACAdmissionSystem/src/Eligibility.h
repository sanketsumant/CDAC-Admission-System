/*
 * Eligibility.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#include <string>

#ifndef ELIGIBILITY_H_
#define ELIGIBILITY_H_

using namespace std;

class Eligibility {
private:
	string course_name;
	string degree;
	double min_percentage;

public:
	Eligibility();
	Eligibility(const string& ecourse_name,const string& edegree,double emin_percentage);

	string& getCourseName();
	void setCourseName(const string& ecourse_name);
	string& getDegree();
	void setDegree(const string& edegree);
	double getMinPercentage();
	void setMinPercentage(double emin_percentage);

	void display();

	~Eligibility();

};

#endif /* ELIGIBILITY_H_ */
