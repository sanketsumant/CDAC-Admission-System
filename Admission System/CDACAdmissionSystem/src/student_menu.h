/*
 * student_menu.h
 *
 *  Created on: 23-Apr-2020
 *      Author: sunbeam
 */

#ifndef STUDENT_MENU_H_
#define STUDENT_MENU_H_

#include <string>
#include <iostream>

#include "Admissionsystem.h"

using namespace std;

void register_student(){
	int size,degree;
	string name;
	double degreemarks;
	size=systemobj.vstudents.size();
	cout<<"Enter name:\t";
	cin>>name;
	systemobj.display_degrees();
	cout<<"Choose your degree option:\t";
	cin>>degree;
	cout<<"Enter Degree Percentage:\t";
	cin>>degreemarks;

	Student obj((size+1),name,-1,-1,-1,systemobj.vdegrees[degree-1],degreemarks,0,"NA","NA",0,0,"NA");
	systemobj.vstudents.push_back(obj);

	systemobj.save_student();

	cout<<"\nStudent registered successfully"<<endl;

	cout<<"\nYour id and password for login is:"<<endl;
	cout<<"id:  "<<size+1<<endl;
	cout<<"password: "<<name<<endl;
}

bool studentmatch_idpass(int id,string password){
	Student *s=systemobj.find_student(id);
	if(s->getName()==password)
		return true;
	return false;
}

void student_listcources(int id){
	Student *s=systemobj.find_student(id);
	systemobj.find_eligibility(s->getDegree(),s->getDegreeMarks());
}

void student_listcenters(){
	cout<<"\nAvailable centers:"<<endl;
	systemobj.display_centers();
}

void give_preferences(int id){
	int n;
	string coursename,centerid;
	cout<<"\nAll available courses:"<<endl;
	systemobj.display_centerswith_courses();
	cout<<"\nYour eligible courses:"<<endl;
	Student *s=systemobj.find_student(id);
	systemobj.find_eligibility(s->getDegree(),s->getDegreeMarks());
	cout<<"\nEnter no of preferences you want to give (Maximum ten allowed per student):\t";
	cin>>n;
	cout<<"\nEnter your preferences :"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter course name:\t";
		cin>>coursename;
		cout<<"Enter center ID:\t";
		cin>>centerid;
		Preference obj(id,i+1,coursename,centerid);
		s->student_preferences.push_back(obj);
		systemobj.vpreferences.push_back(obj);
	}
	cout<<"\nPreferences added Successfully"<<endl;
	sort(systemobj.vpreferences.begin(),systemobj.vpreferences.end(),systemobj.comp_form_no);
}

void see_allocated(int id){
	Student *s=systemobj.find_student(id);
	cout<<"\nAllocated preference no:\t"<<s->getAllocatedPreference()<<endl;
	cout<<"Allocated center ID:\t"<<s->getAllocatedCenterId()<<endl;
	cout<<"Allocated course name:\t"<<s->getAllocatedCoursename()<<endl;
}

void update_payment(int id){
	double paid,payment;
	Student *s=systemobj.find_student(id);
	paid=s->getPayment();
	cout<<"Your paid fees:\t"<<paid<<endl;
	if(paid==0)
	{
		cout<<"\nPay your first installment of Rs.11800"<<endl;
		cout<<"Enter amount:\t";
		cin>>payment;
		s->setPayment(payment);
		systemobj.save_student();
	}
	else if(paid==11800)
	{
		cout<<"\nPay your second installment:"<<endl;
		cout<<"Enter amount:\t";
		cin>>payment;
		s->setPayment(payment+paid);
		systemobj.save_student();
	}
}

int student_menu(){
	int studentchoice;

	cout<<"\n\n0.Log out\n1.List courses\n2.List centers\n";
	cout<<"3.Give preferences\n4.See allocated center/course\n5.Update payment details"<<endl;
	cout<<"\nEnter Your Choice:\t ";
	cin>>studentchoice;
	return studentchoice;
}

void sign_in(){
	int studentchoice,id;
	string password;

	cout<<"Enter ID:\t";
	cin>>id;
	cout<<"Enter Password:\t";
	cin>>password;

	if(studentmatch_idpass(id,password)==0)
		cout<<"\nInvalid id or password"<<endl;

	else
	{
		cout<<"\nLogin  successful"<<endl;
		while((studentchoice=student_menu())!=0)
		{
			switch(studentchoice)
			{
			case 0:
				exit(0);
			case 1:
				student_listcources(id);
				break;
			case 2:
				student_listcenters();
				break;
			case 3:
				give_preferences(id);
				break;
			case 4:
				see_allocated(id);
				break;
			case 5:
				update_payment(id);
				break;
			default:
				cout<<"\nEnter Valid Choice"<<endl;
			}
		}
	}
}

void student(){
	int choice;

	cout<<"\n0.Main menu"<<endl;
	cout<<"1.Register new student"<<endl;
	cout<<"2.Sign in"<<endl;
	cout<<"\nEnter your choice:\t";
	cin>>choice;

	switch(choice)
	{
	case 0: exit(0);
	case 1:
		register_student();
		break;
	case 2:
		sign_in();
		break;
	default:
		cout<<"\nEnter Valid Choice"<<endl;
	}


}


#endif /* STUDENT_MENU_H_ */
