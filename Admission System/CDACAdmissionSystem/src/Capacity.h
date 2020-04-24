/*
 * Capacity.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */
#include <string>

#ifndef CAPACITY_H_
#define CAPACITY_H_

using namespace std;

class Capacity {
private:
	string center_id;
	string course_name;
	int capacity;
	int filled_capacity;

public:
	Capacity();
	Capacity(const string& ccenter_id,const string& ccourse_name,int ccapacity,int cfilled_capacity);

	int getCapacity();
	void setCapacity(int ccapacity);
	string& getCenterId();
	void setCenterId(const string& ccenter_id);
	string& getCourseName();
	void setCourseName(const string& ccourse_name);
	int getFilledCapacity();
	void setFilledCapacity(int cfilled_capacity);

	void display();
	void display_centerandcourse();

	~Capacity();
};

#endif /* CAPACITY_H_ */
