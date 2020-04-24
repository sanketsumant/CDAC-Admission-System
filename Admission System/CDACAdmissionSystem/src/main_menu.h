/*
 * menu.h
 *
 *  Created on: 22-Apr-2020
 *      Author: sunbeam
 */

#ifndef MAIN_MENU_H_
#define MAIN_MENU_H_

#include "Admissionsystem.h"
#include "student_menu.h"
#include "admin_menu.h"
#include "centercoordinator_menu.h"


int menu_choice(){
	int choice;
	cout<<"\n\n0.Exit\n1.Student\n2.Admin\n3.Center Coordinator\n\n";
	cout<<"Enter Your Choice:\t ";\
	cin>>choice;
	return choice;
}

void main_menu(){
	int mainmenuchoice;
	while((mainmenuchoice=menu_choice())!=0)
	{
		switch(mainmenuchoice)
		{
		case 0: exit(0);
		case 1:
			student();
			break;
		case 2:
			admin();
			break;
		case 3:
			centercoordinator();
			break;
		default:
			cout<<"\nEnter Valid Choice"<<endl;
		}
	}
}


#endif /* MAIN_MENU_H_ */
