
/*
 * Admissionsystem.cpp
 *
 *  Created on: 20-Apr-2020
 *      Author: sunbeam
 */


#include "Admissionsystem.h"

Admissionsystem systemobj;

using namespace std;


Admissionsystem::Admissionsystem() {
	// TODO Auto-generated constructor stub

}

void Admissionsystem::load_centers(){
	ifstream fp;
	string line;
	int c;
	fp.open("centers.csv");
	if(!fp) {
		perror("failed to open file");
	}

	c=0;
	while(getline(fp, line)) {
		stringstream str(line);
		string tokens[5];
		for(int i=0; i<5; i++)
			getline(str, tokens[i], ',');
		Center centerobj(tokens[0], tokens[1] ,tokens[2],tokens[3],tokens[4]);
		vcenters.push_back(centerobj);
		c++;
	}
	fp.close();

	cout << "centers loaded: " << c << endl;
}



void Admissionsystem::load_courses(){
	ifstream fp;
	string line;
	int c;
	fp.open("courses.csv");
	if(!fp) {
		perror("failed to open file");
	}

	c=0;
	while(getline(fp, line)) {
		stringstream str(line);
		string tokens[4];
		for(int i=0; i<4; i++)
			getline(str, tokens[i], ',');
		Course courseobj(stoi(tokens[0]), tokens[1] ,stod(tokens[2]),tokens[3]);
		vcourses.push_back(courseobj);
		c++;
	}
	fp.close();

	cout << "courses loaded: " << c << endl;

}

void Admissionsystem::load_students(){
	ifstream fp;
	string line;
	int c;
	fp.open("test.csv");
	if(!fp) {
		perror("failed to open file");
	}

	c=0;
	while(getline(fp, line)) {
		stringstream str(line);
		string tokens[13];
		for(int i=0; i<13; i++)
			getline(str, tokens[i], ',');
		Student studentobj(stoi(tokens[0]), tokens[1], stoi(tokens[2]),stoi(tokens[3]),stoi(tokens[4]),tokens[5], stod(tokens[6]),stoi(tokens[7]),tokens[8],tokens[9],stod(tokens[10]),stoi(tokens[11]),tokens[12]);
		vstudents.push_back(studentobj);
		c++;
	}
	fp.close();

	cout << "students loaded: " << c << endl;
}

void Admissionsystem::load_capacities(){
	ifstream fp;
	string line;
	int c;
	fp.open("capacitiesmenu.csv");
	if(!fp) {
		perror("failed to open file");
	}

	c=0;
	while(getline(fp, line)) {
		stringstream str(line);
		string tokens[4];
		for(int i=0; i<4; i++)
			getline(str, tokens[i], ',');
		Capacity capacityobj(tokens[0], tokens[1], stoi(tokens[2]),stoi(tokens[3]));
		vcapacities.push_back(capacityobj);
		c++;
	}
	fp.close();

	cout << "capacities loaded: " << c << endl;

}



void Admissionsystem::load_preferences(){
	ifstream fp;
	string line;
	int c;
	fp.open("preferencesmenu.csv");
	if(!fp) {
		perror("failed to open file");
	}

	c=0;
	while(getline(fp, line)) {
		stringstream str(line);
		string tokens[4];
		for(int i=0; i<4; i++)
			getline(str, tokens[i], ',');
		Preference preferenceobj(stoi(tokens[0]), stoi(tokens[1]),tokens[2],tokens[3]);
		vpreferences.push_back(preferenceobj);
		c++;
	}
	fp.close();

	cout << "Preferences loaded: " << c << endl;

}

void Admissionsystem::load_eligibilities(){
	ifstream fp;
	string line;
	int c;
	fp.open("eligibilities.csv");
	if(!fp) {
		perror("failed to open file");
	}

	c=0;
	while(getline(fp, line)) {
		stringstream str(line);
		string tokens[3];
		for(int i=0; i<3; i++)
			getline(str, tokens[i], ',');
		Eligibility eligibilityobj(tokens[0],tokens[1],stod(tokens[2]));
		veligibilities.push_back(eligibilityobj);
		c++;
	}
	fp.close();

	cout << "eligibilities loaded: " << c << endl;

}

void Admissionsystem::load_degrees(){
	ifstream fp;
	string line;
	int c;
	fp.open("degrees.txt");
	if(!fp) {
		perror("failed to open file");
	}

	c=0;
	while(getline(fp, line)) {
		vdegrees.push_back(line);
		c++;
	}
	fp.close();

	cout << "degrees loaded: " << c << endl;
}

void Admissionsystem::save_student(){
	ofstream fp;

	fp.open("test.csv");
	if(!fp) {
		perror("failed to open file");
	}

	for(unsigned i=0;i<vstudents.size();i++)
	{
		fp<<vstudents[i].getform_no()<<","<<vstudents[i].getName()<<","<<vstudents[i].getRankA()<<","<<vstudents[i].getRankB()<<","<<vstudents[i].getRankC()<<","<<vstudents[i].getDegree()<<","<<vstudents[i].getDegreeMarks()<<","<<vstudents[i].getAllocatedPreference()<<","<<vstudents[i].getAllocatedCoursename()<<","<<vstudents[i].getAllocatedCenterId()<<","<<vstudents[i].getPayment()<<","<<vstudents[i].getReported()<<","<<vstudents[i].getPrn()<<endl;
	}

	fp.close();

}

void Admissionsystem::save_capacity(){
	ofstream fp;

	fp.open("capacitiesmenu.csv");
	if(!fp) {
		perror("failed to open file");
	}

	for(unsigned i=0;i<vcapacities.size();i++)
	{
		fp<<vcapacities[i].getCenterId()<<","<<vcapacities[i].getCourseName()<<","<<vcapacities[i].getCapacity()<<","<<vcapacities[i].getFilledCapacity()<<endl;
	}

	fp.close();

}

void Admissionsystem::save_preferences(){
	ofstream fp;

	fp.open("preferencesmenu.csv");
	if(!fp) {
		perror("failed to open file");
	}

	for(unsigned i=0;i<vpreferences.size();i++)
	{
		fp<<vpreferences[i].getStudentFormno()<<","<<vpreferences[i].getPreferenceNo()<<","<<vpreferences[i].getCourseName()<<","<<vpreferences[i].getCenterId()<<endl;
	}

	fp.close();

}

Center* Admissionsystem::find_center(string center_id) {
	unsigned i;
	for(i=0; i<vcenters.size(); i++) {
		if(vcenters[i].getCenterId() == center_id)
			return &vcenters[i];
	}
	return NULL;
}

Course* Admissionsystem::find_course(string course_name) {
	unsigned i;
	for(i=0; i<vcourses.size(); i++) {
		if(vcourses[i].getName() == course_name)
			return &vcourses[i];
	}
	return NULL;
}

Student* Admissionsystem::find_student( int form_no) {
	unsigned i;
	for(i=0; i<vstudents.size(); i++) {
		if(vstudents[i].getform_no() == form_no)
			return &vstudents[i];
	}
	return NULL;
}

void Admissionsystem::find_eligibility(string degree, double percentage){
	unsigned i,j;
	cout<<"\nAvailable Courses according to your eligibility:"<<endl;
	for(i=0; i<vcourses.size(); i++)
	{
		for(j=0; j<vcourses[i].eligibilities.size(); j++)
			if(vcourses[i].eligibilities[j].getDegree() == degree  && vcourses[i].eligibilities[j].getMinPercentage()<percentage)
				vcourses[i].display();
	}
}

void Admissionsystem::load_capacities_in_centerandcourse(){
	/*systemobj.load_courses();
	systemobj.load_centers();*/

	ifstream fp;
	string line;
	fp.open("capacitiesmenu.csv");
	if(!fp) {
		perror("failed to open file");
	}

	while(getline(fp, line)) {
		stringstream str(line);
		string tokens[4];
		for(int i=0; i<4; i++)
			getline(str, tokens[i], ',');
		Capacity capacityobj(tokens[0], tokens[1], stoi(tokens[2]),stoi(tokens[3]));
		vcapacities.push_back(capacityobj);

		Center *ccenter = find_center(capacityobj.getCenterId());
		ccenter->coursecapacity[capacityobj.getCourseName()]=vcapacities.size()-1;

		Course *ccourse = find_course(capacityobj.getCourseName());
		ccourse->centercapacity[capacityobj.getCenterId()] = vcapacities.size()-1;

	}
	fp.close();

}

void Admissionsystem::load_preferences_in_students(){
	//systemobj.load_students();
	ifstream fp;
	string line;
	fp.open("preferencesmenu.csv");
	if(!fp) {
		perror("failed to open file");
	}

	while(getline(fp, line)) {
		stringstream str(line);
		string tokens[4];
		for(int i=0; i<4; i++)
			getline(str, tokens[i], ',');
		Preference preferenceobj(stoi(tokens[0]), stoi(tokens[1]),tokens[2],tokens[3]);
		Student *s = find_student(preferenceobj.getStudentFormno());
		s->student_preferences.push_back(preferenceobj);
	}
	fp.close();


}

void Admissionsystem::load_eligibilities_in_courses(){
	//systemobj.load_courses();
	ifstream fp;
	string line;
	fp.open("eligibilities.csv");
	if(!fp) {
		perror("failed to open file");
	}

	while(getline(fp, line)) {
		stringstream str(line);
		string tokens[3];
		for(int i=0; i<3; i++)
			getline(str, tokens[i], ',');
		Eligibility eligibilityobj(tokens[0],tokens[1],stod(tokens[2]));
		Course *c=find_course(eligibilityobj.getCourseName());
		c->eligibilities.push_back(eligibilityobj);

	}
	fp.close();


}

void Admissionsystem::display_students(){
	for(unsigned i=0;i<vstudents.size();i++){
		vstudents[i].display();
	}
}

void Admissionsystem::display_courses(){
	for(unsigned i=0;i<vcourses.size();i++){
		vcourses[i].display();
	}
}

void Admissionsystem::display_centers(){
	for(unsigned i=0;i<vcenters.size();i++){
		vcenters[i].display();
	}
}

void Admissionsystem::display_capacities(){
	for(unsigned i=0;i<vcapacities.size();i++){
		vcapacities[i].display();
	}
}

void Admissionsystem::display_preferences(){
	for(unsigned i=0;i<vpreferences.size();i++){
		vpreferences[i].display();
	}
}

void Admissionsystem::display_eligibilities(){
	for(unsigned i=0;i<veligibilities.size();i++){
		veligibilities[i].display();
	}
}

void Admissionsystem::display_degrees(){
	cout<<endl<<endl;
	for(unsigned i=0;i<vdegrees.size();i++){
		cout<<i+1<<". "<<vdegrees[i]<<endl;
	}
}

void Admissionsystem::display_studentswith_preference(){
	for(unsigned i=0;i<vstudents.size();i++){
		vstudents[i].display_preferences();
		cout<<endl;
	}
}

void Admissionsystem::display_courseswith_eligibility(){
	for(unsigned i=0;i<vcourses.size();i++){
		vcourses[i].display_eligibilities();
		cout<<endl;
	}
}

void Admissionsystem::display_courseswith_capacity(){
	for(unsigned i=0;i<vcourses.size();i++){
		vcourses[i].display_course_capacity(vcapacities);
		cout<<endl;
	}
}

void Admissionsystem::display_centerswith_capacity(){
	cout<<endl;
	for(unsigned i=0;i<vcenters.size();i++){
		vcenters[i].display_Center_capacity(vcapacities);
		cout<<endl;
	}
}

void Admissionsystem::display_centerswith_courses(){
	cout<<endl;
	for(unsigned i=0;i<vcenters.size();i++){
		vcenters[i].display_Center_courses(vcapacities);
		cout<<endl;
	}
}

void Admissionsystem::display_allocated_students(){
	cout<<"\nList of allocated students:"<<endl;
	for(unsigned i=0;i<vstudents.size();i++){
		if(vstudents[i].getAllocatedPreference()>0)
			vstudents[i].display();
	}
}

void Admissionsystem::display_paid_students(){
	cout<<"\nList of allocated students who have paid 1st installment:"<<endl;
	for(unsigned i=0;i<vstudents.size();i++){
		if(vstudents[i].getAllocatedPreference()>0 && vstudents[i].getPayment()>0)
			vstudents[i].display();
	}
}

void Admissionsystem::display_students_centercoursewise(string course,string center){
	cout<<"\nList of allocated students:"<<endl;
	for(unsigned i=0;i<vstudents.size();i++){
		if(vstudents[i].getAllocatedCenterId()==center && vstudents[i].getAllocatedCoursename()==course)
			vstudents[i].display();
	}
}

void Admissionsystem::display_students_centercoursewise_withprn(string course,string center){
	cout<<"\nList of allocated students:"<<endl;
	for(unsigned i=0;i<vstudents.size();i++){
		if(vstudents[i].getAllocatedCenterId()==center && vstudents[i].getAllocatedCoursename()==course &&vstudents[i].getPrn()!="NA")
			vstudents[i].display();
	}
}

void Admissionsystem::display_admitted_students_centercoursewise(string course,string center){
	cout<<"\nList of admitted students:"<<endl;
	for(unsigned i=0;i<vstudents.size();i++){
		if(vstudents[i].getAllocatedCenterId()==center && vstudents[i].getAllocatedCoursename()==course && vstudents[i].getReported()==1)
			vstudents[i].display();
	}
}

void Admissionsystem::display_alladmitted_students_centercoursewise(){
	int c=0;
	cout<<"\nList of all admitted students:"<<endl;
	for(unsigned i=0;i<vstudents.size();i++){
		if(vstudents[i].getReported()==1)
		{
			vstudents[i].display();
			c++;
		}
	}
	cout<<"\nTotal: "<<c<<endl;
}

void Admissionsystem::display_prngenerated_students(){
	int srno=1;
	double coursefees;
	string prn,s1,s2,s3;
	cout<<"\nList of allocated students who have paid full fees and reported at center:"<<endl;
	for(unsigned i=0;i<vstudents.size();i++){
		if(vstudents[i].getReported()==1 )
		{
			Course *c=find_course(vstudents[i].getAllocatedCoursename());
			coursefees=c->getFees();
			if(vstudents[i].getPayment()== (coursefees+11800))
			{
				s1=vstudents[i].getAllocatedCoursename();
				s2=vstudents[i].getAllocatedCenterId();
				s3=to_string(srno);
				prn=s1+"_"+s2+"_"+s3;
				vstudents[i].setPrn(prn);
				vstudents[i].display();
				srno++;
			}
		}
	}
}

bool Admissionsystem::comp_rank_A( const Student& s1, const Student& s2) {
	return s1.getRankA()<s2.getRankA();
}

bool Admissionsystem::comp_rank_B( const Student& s1, const Student& s2) {
	return s1.getRankB()<s2.getRankB();
}

bool Admissionsystem::comp_rank_C( const Student& s1, const Student& s2) {
	return s1.getRankC()<s2.getRankC();
}

bool Admissionsystem::comp_name( const Student& s1, const Student& s2){
	return s1.getName()<s2.getName();
}

bool Admissionsystem::comp_course( const Student& s1, const Student& s2){
	return s1.getAllocatedCoursename()<s2.getAllocatedCoursename();
}

bool Admissionsystem::comp_center( const Student& s1, const Student& s2){
	return s1.getAllocatedCenterId()<s2.getAllocatedCenterId();
}

bool Admissionsystem::comp_feespaid( const Student& s1, const Student& s2){
	return s1.getPayment()<s2.getPayment();
}

bool Admissionsystem::comp_form_no( const Preference& p1, const Preference& p2){
	return p1.getStudentFormno()<p2.getStudentFormno();
}

void Admissionsystem::round1_allocation()
{
	unsigned i,j,count=0;
	for(i=0;i<10;i++)
	{
		sort(vstudents.begin(),vstudents.end(),comp_rank_A);
		for(j=0;j<vstudents.size();j++)
		{
			if(vstudents[j].student_preferences.size()>i)
			{
				if(vstudents[j].getRankA()!=-1 && vstudents[j].getAllocatedPreference()==0  && vstudents[j].getPayment()>=0)
				{
					Course *cptr=find_course(vstudents[j].student_preferences[i].getCourseName());
					if(cptr->getCcatSection()=="A")
					{
						Center *centerptr=find_center(vstudents[j].student_preferences[i].getCenterId());
						int index=centerptr->coursecapacity[vstudents[j].student_preferences[i].getCourseName()];
						if(vcapacities[index].getCapacity()!=vcapacities[index].getFilledCapacity())
						{
							count++;
							int filled=vcapacities[index].getFilledCapacity();
							int preference=vstudents[j].student_preferences[i].getPreferenceNo();
							string id=vstudents[j].student_preferences[i].getCenterId();
							string cname=vstudents[j].student_preferences[i].getCourseName();

							vstudents[j].setAllocatedPreference(preference);
							vstudents[j].setAllocatedCenterId(id);
							vstudents[j].setAllocatedCoursename(cname);
							vcapacities[index].setFilledCapacity(filled+1);
						}
					}
				}
			}
		}
		sort(vstudents.begin(),vstudents.end(),comp_rank_B);
		for(j=0;j<vstudents.size();j++)
		{
			if(vstudents[j].student_preferences.size()>i)
			{
				if(vstudents[j].getRankA()!=-1 && vstudents[j].getAllocatedPreference()==0  && vstudents[j].getPayment()>=0)
				{
					Course *cptr=find_course(vstudents[j].student_preferences[i].getCourseName());
					if(cptr->getCcatSection()=="B")
					{
						Center *centerptr=find_center(vstudents[j].student_preferences[i].getCenterId());
						int index=centerptr->coursecapacity[vstudents[j].student_preferences[i].getCourseName()];
						if(vcapacities[index].getCapacity()!=vcapacities[index].getFilledCapacity())
						{
							count++;
							int filled=vcapacities[index].getFilledCapacity();
							int preference=vstudents[j].student_preferences[i].getPreferenceNo();
							string id=vstudents[j].student_preferences[i].getCenterId();
							string cname=vstudents[j].student_preferences[i].getCourseName();

							vstudents[j].setAllocatedPreference(preference);
							vstudents[j].setAllocatedCenterId(id);
							vstudents[j].setAllocatedCoursename(cname);
							vcapacities[index].setFilledCapacity(filled+1);
						}
					}
				}
			}
		}
		sort(vstudents.begin(),vstudents.end(),comp_rank_C);
		for(j=0;j<vstudents.size();j++)
		{
			if(vstudents[j].student_preferences.size()>i)
			{
				if(vstudents[j].getRankA()!=-1 && vstudents[j].getAllocatedPreference()==0  && vstudents[j].getPayment()>=0)
				{
					Course *cptr=find_course(vstudents[j].student_preferences[i].getCourseName());
					if(cptr->getCcatSection()=="C")
					{
						Center *centerptr=find_center(vstudents[j].student_preferences[i].getCenterId());
						int index=centerptr->coursecapacity[vstudents[j].student_preferences[i].getCourseName()];
						if(vcapacities[index].getCapacity()!=vcapacities[index].getFilledCapacity())
						{
							count++;
							int filled=vcapacities[index].getFilledCapacity();
							int preference=vstudents[j].student_preferences[i].getPreferenceNo();
							string id=vstudents[j].student_preferences[i].getCenterId();
							string cname=vstudents[j].student_preferences[i].getCourseName();

							vstudents[j].setAllocatedPreference(preference);
							vstudents[j].setAllocatedCenterId(id);
							vstudents[j].setAllocatedCoursename(cname);
							vcapacities[index].setFilledCapacity(filled+1);
						}
					}
				}
			}
		}
	}
	cout<<"\nAllocation successful"<<endl;
	cout<<"No of seats allocated: "<<count<<endl;
}


void Admissionsystem::round2_allocation(){
	unsigned i;
	for(i=0;i<vstudents.size();i++)
	{
		if(vstudents[i].getAllocatedPreference()>0 && vstudents[i].getPayment()==0)
			vstudents[i].setPayment(-1);
	}

	for(i=0;i<vstudents.size();i++)
	{
		vstudents[i].setAllocatedPreference(0);
		vstudents[i].setAllocatedCenterId("NA");
		vstudents[i].setAllocatedCoursename("NA");
	}

	for(i=0;i<vcapacities.size();i++)
	{
		vcapacities[i].setFilledCapacity(0);
	}

	round1_allocation();
}


Admissionsystem::~Admissionsystem() {
	// TODO Auto-generated destructor stub
}
