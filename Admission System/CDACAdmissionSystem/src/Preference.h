/*
 * Preference.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */
#include <string>

#ifndef PREFERENCE_H_
#define PREFERENCE_H_

using namespace std;

class Preference {
private:
	int student_formno;
	int preference_no;
	string course_name;
	string center_id;


public:
	Preference();
	Preference(int pstudent_formno,int ppreference_no,const string& pcourse_name,const string& pcenter_id);

	string& getCenterId();
	void setCenterId(const string& pcenter_id);
	string& getCourseName();
	void setCourseName(const string& pccourse_name);
	int getPreferenceNo() ;
	void setPreferenceNo(int ppreference_no);
	int getStudentFormno() const;
	void setStudentFormno(int pstudent_formno);

	void display();

	~Preference();

};

#endif /* PREFERENCE_H_ */
