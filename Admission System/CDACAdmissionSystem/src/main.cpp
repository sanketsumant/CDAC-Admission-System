/*
 * main.cpp
 *
 *  Created on: 20-Apr-2020
 *      Author: sunbeam
 */

/*
 * main.cpp
 *
 *  Created on: 15-Apr-2020
 *      Author: sunbeam
 */

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


#include "Admissionsystem.h"
#include "main_menu.h"


using namespace std;




int main()
{
	systemobj.load_students();
	systemobj.load_centers();
	systemobj.load_courses();
	systemobj.load_preferences();
	//systemobj.load_capacities();
	systemobj.load_eligibilities();
	systemobj.load_degrees();

	systemobj.load_capacities_in_centerandcourse();
	systemobj.load_eligibilities_in_courses();
	systemobj.load_preferences_in_students();

	main_menu();

	systemobj.save_student();
	systemobj.save_preferences();
	systemobj.save_capacity();

	//systemobj.display_studentswith_preference();

	return 0;
}






