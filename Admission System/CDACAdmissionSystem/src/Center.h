/*
 * Center.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */
#include "Course.h"

#include <string>
#include <vector>
#include <map>

#ifndef CENTER_H_
#define CENTER_H_

using namespace std;

class Center {
private:
	string center_id;
	string center_name;
	string address;
	string coordinator;
	string password;

public:
	map<string,int> coursecapacity;

public:
	Center();
	Center(const string& ccenter_id,const string& ccenter_name,const string& caddress,const string& ccoordinator,const string& cpassword);

	string& getAddress() ;
	void setAddress(const string& caddress);
	string& getCenterId() ;
	void setCenterId(const string& ccenter_id);
	string& getCenterName() ;
	void setCenterName(const string& ccenter_name);
	string& getCoordinator();
	void setCoordinator(const string& ccoordinator);
	string& getPassword();
	void setPassword(const string& password);

	void display();
	void display_Center_capacity(vector<Capacity>& vcapacities);
	void display_Center_courses(vector<Capacity>& vcapacities);

	~Center();

};

#endif /* CENTER_H_ */
