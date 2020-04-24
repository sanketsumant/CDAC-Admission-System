/*
 * Admissionsystem.h
 *
 *  Created on: 20-Apr-2020
 *      Author: sunbeam
 */

#ifndef ADMISSIONSYSTEM_H_
#define ADMISSIONSYSTEM_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "Student.h"
#include "Preference.h"
#include "Eligibility.h"
#include "Center.h"
#include "Course.h"
#include "Capacity.h"


class Admissionsystem {
public:
	vector<Center> vcenters;
	vector<Course> vcourses;
	vector<Student> vstudents;
	vector<Capacity> vcapacities;
	vector<Preference> vpreferences;
	vector<Eligibility> veligibilities;
	vector<string> vdegrees;

public:
	Admissionsystem();


	void load_students();
	void load_courses();
	void load_centers();
	void load_capacities();
	void load_preferences();
	void load_eligibilities();
	void load_degrees();


	void save_student();
	void save_capacity();
	void save_preferences();


	void load_capacities_in_centerandcourse();
	void load_preferences_in_students();
	void load_eligibilities_in_courses();


	Center* find_center(string center_id);
	Course* find_course(string course_name);
	Student* find_student(int form_no);
	void find_eligibility(string degree, double min_percentage);


	void display_students();
	void display_courses();
	void display_centers();
	void display_capacities();
	void display_preferences();
	void display_eligibilities();
	void display_degrees();


	void display_studentswith_preference();
	void display_courseswith_eligibility();
	void display_courseswith_capacity();
	void display_centerswith_capacity();
	void display_centerswith_courses();


	void display_allocated_students();
	void display_paid_students();
	void display_students_centercoursewise(string course,string center);
	void display_admitted_students_centercoursewise(string course,string center);
	void display_students_centercoursewise_withprn(string course,string center);
	void display_alladmitted_students_centercoursewise();
	void display_prngenerated_students();

	static bool comp_rank_A( const Student& s1, const Student& s2);
	static bool comp_rank_B( const Student& s1, const Student& s2);
	static bool comp_rank_C( const Student& s1, const Student& s2);
	static bool comp_name( const Student& s1, const Student& s2);
	static bool comp_course( const Student& s1, const Student& s2);
	static bool comp_center( const Student& s1, const Student& s2);
	static bool comp_feespaid( const Student& s1, const Student& s2);


	static bool comp_form_no( const Preference& p1, const Preference& p2);


	void round1_allocation();
	void round2_allocation();


	~Admissionsystem();
};


extern Admissionsystem systemobj;

#endif /* ADMISSIONSYSTEM_H_ */
