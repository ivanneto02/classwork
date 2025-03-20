#ifndef CHART_H
#define CHART_H

#include <iostream>
#include <vector>

using namespace std;

class ChartSection {
	
	private:
		vector<Group*> groups;
		int sections;
		int employees;
		
	public:
		void AddSection(ChartSection);
		double compute_salary() const;
};

class Employee : public ChartSection {
	
	private:
		string name;
		double salary;
		int age;
	
	public:
		double compute_salary() const;
		void set_salary(double);
};

class Subgroup : public ChartSection {
	
	private:
		string subground_name;
		int size;
		vector<Employee*> employees;
	
	public:
		double compute_salary() const;
};

class Group : public ChartSection {
	
	private:
		string group_name;
		int size;
		vector<Subgroup*> subgroups;
	
	public:
		double compute_salary() const;
};

#endif /* CHART_H */

