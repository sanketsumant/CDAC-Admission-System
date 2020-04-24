/*
 * centercoordinator_menu.h
 *
 *  Created on: 23-Apr-2020
 *      Author: sunbeam
 */

#ifndef CENTERCOORDINATOR_MENU_H_
#define CENTERCOORDINATOR_MENU_H_

#include "Admissionsystem.h"

bool centercoordinator_match_idpass(string id,string password){
	Center *c=systemobj.find_center(id);
	if(c->getPassword()==password)
		return true;
	return false;
}

void list_courses(string id){
	Center *c=systemobj.find_center(id);
	c->display_Center_courses(systemobj.vcapacities);
}

void liststudents_allocatedto_center(string id){
	string course;
	Center *c=systemobj.find_center(id);
	cout<<"\nCourses Available at this center:"<<endl;
	c->display_Center_courses(systemobj.vcapacities);
	cout<<"\nEnter course:\t";
	cin>>course;
	sort(systemobj.vstudents.begin(),systemobj.vstudents.end(),systemobj.comp_name);
	systemobj.display_students_centercoursewise(course,id);
}

void reported_status(string id){
	int formno,status;
	cout<<"\nEnter student form no:\t";
	cin>>formno;
	Student *s=systemobj.find_student(formno);
	if(s->getAllocatedCenterId()==id)
	{
		status=s->getReported();
		if(status==0)
		{
			s->setReported(1);
			cout<<"\nCurrent status of student is updated as reported"<<endl;
		}
	}
	else
		cout<<"Indicating student is not allocated to that center"<<endl;

}

void list_admitted(string id){
	string course;
	Center *c=systemobj.find_center(id);
	cout<<"\nCourses Available at this center:"<<endl;
	c->display_Center_courses(systemobj.vcapacities);
	cout<<"\nEnter course:\t";
	cin>>course;
	sort(systemobj.vstudents.begin(),systemobj.vstudents.end(),systemobj.comp_name);
	systemobj.display_admitted_students_centercoursewise(course,id);
}


int centercoordinator_menu(){
	int centercoordinatorchoice;

	cout<<"\n\n0.Log out\n1.List courses (of that center)\n2.List students (allocated to that center)\n";
	cout<<"3.Update reported status\n4.List admitted students (with PRN)"<<endl;
	cout<<"\nEnter Your Choice:\t ";
	cin>>centercoordinatorchoice;
	return centercoordinatorchoice;
}


void centercoordinator(){
	int choice;
	string id,password;

	cout<<"Enter ID:\t";
	cin>>id;
	cout<<"Enter Password:\t";
	cin>>password;

	if(centercoordinator_match_idpass(id,password)==0)
		cout<<"\nInvalid id or password"<<endl;
	else
	{
		cout<<"\nLogin  successful"<<endl;
		while((choice=centercoordinator_menu())!=0)
		{
			switch(choice)
			{
			case 0:
				exit(0);
			case 1:
				list_courses(id);
				break;
			case 2:
				liststudents_allocatedto_center(id);
				break;
			case 3:
				reported_status(id);
				break;
			case 4:
				list_admitted(id);
				break;
			default:
				cout<<"\nEnter Valid Choice"<<endl;
			}
		}
	}
}



#endif /* CENTERCOORDINATOR_MENU_H_ */
