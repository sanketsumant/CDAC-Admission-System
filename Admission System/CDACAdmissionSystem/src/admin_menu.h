/*
 * admin_menu.h
 *
 *  Created on: 23-Apr-2020
 *      Author: sunbeam
 */

#ifndef ADMIN_MENU_H_
#define ADMIN_MENU_H_

#include "Admissionsystem.h"


bool adminmatch_idpass(string id,string password){
	if(id=="admin" && password=="admin")
		return true;
	return false;
}

void update_studentranks(){
	int id,ranka,rankb,rankc;
	cout<<"\nEnter student form no:\t";
	cin>>id;
	Student *s=systemobj.find_student(id);
	cout<<"\nEnter rank A:\t";
	cin>>ranka;
	cout<<"\nEnter rank B:\t";
	cin>>rankb;
	cout<<"\nEnter rank C:\t";
	cin>>rankc;
	s->setRankA(ranka);
	s->setRankB(rankb);
	s->setRankC(rankc);

	cout<<"\nRanks updated successfully"<<endl;
}

void generate_prn(){
	sort(systemobj.vstudents.begin(),systemobj.vstudents.end(),systemobj.comp_course);
	sort(systemobj.vstudents.begin(),systemobj.vstudents.end(),systemobj.comp_center);
	sort(systemobj.vstudents.begin(),systemobj.vstudents.end(),systemobj.comp_name);
	systemobj.display_prngenerated_students();
}

void liststudents_allocatedto_centerandcourse(){
	string course,centerid;
	cout<<"\nEnter Center:\t";
	cin>>centerid;
	cout<<"\nEnter course:\t";
	cin>>course;
	Center *c=systemobj.find_center(centerid);

	sort(systemobj.vstudents.begin(),systemobj.vstudents.end(),systemobj.comp_name);
	systemobj.display_students_centercoursewise_withprn(course,centerid);
}

int admin_menu(){
	int adminchoice;

	cout<<"\n\n0.Log out\n1.List Courses & Eligibilities\n2.List centers & capacities\n3.List students\n";
	cout<<"4.Update student ranks\n5.Allocate centers (Round 1)\n6.Allocate centers (Round 2)\n7.List allocated students\n";
	cout<<"8.List paid students\n9.List reported (at center) students\n10.Generate PRN\n11.List admitted students (with PRN) for given center"<<endl;
	cout<<"\nEnter Your Choice:\t ";
	cin>>adminchoice;
	return adminchoice;
}

void admin(){
	int choice;
	string id,password;

	cout<<"Enter ID:\t";
	cin>>id;
	cout<<"Enter Password:\t";
	cin>>password;

	if(adminmatch_idpass(id,password)==0)
		cout<<"\nInvalid id or password"<<endl;
	else
	{
		cout<<"\nLogin  successful"<<endl;
		while((choice=admin_menu())!=0)
		{
			switch(choice)
			{
			case 0:
				exit(0);
			case 1:
				systemobj.display_courseswith_eligibility();
				break;
			case 2:
				systemobj.display_courseswith_capacity();
				break;
			case 3:
				systemobj.display_students();
				break;
			case 4:
				update_studentranks();
				break;
			case 5:
				systemobj.round1_allocation();
				break;
			case 6:
				systemobj.round2_allocation();
				break;
			case 7:
			{
				sort(systemobj.vstudents.begin(),systemobj.vstudents.end(),systemobj.comp_course);
				sort(systemobj.vstudents.begin(),systemobj.vstudents.end(),systemobj.comp_center);
				sort(systemobj.vstudents.begin(),systemobj.vstudents.end(),systemobj.comp_name);
				systemobj.display_allocated_students();
			}
			break;
			case 8:
			{
				sort(systemobj.vstudents.begin(),systemobj.vstudents.end(),systemobj.comp_course);
				sort(systemobj.vstudents.begin(),systemobj.vstudents.end(),systemobj.comp_center);
				sort(systemobj.vstudents.begin(),systemobj.vstudents.end(),systemobj.comp_name);
				sort(systemobj.vstudents.begin(),systemobj.vstudents.end(),systemobj.comp_feespaid);
				systemobj.display_paid_students();
			}
			break;
			case 9:
			{
				sort(systemobj.vstudents.begin(),systemobj.vstudents.end(),systemobj.comp_course);
				sort(systemobj.vstudents.begin(),systemobj.vstudents.end(),systemobj.comp_center);
				sort(systemobj.vstudents.begin(),systemobj.vstudents.end(),systemobj.comp_name);
				systemobj.display_alladmitted_students_centercoursewise();
			}
			break;
			case 10:
				generate_prn();
				break;
			case 11:
				liststudents_allocatedto_centerandcourse();
				break;
			default:
				cout<<"\nEnter Valid Choice"<<endl;
			}
		}
	}
}



#endif /* ADMIN_MENU_H_ */
