#include "chart.h"

using namepsace std;

double ChartSection::compute_salary() const {
	
	double total = 0.0;
	for (int i = 0; i < this->groups.size(); i++) {
		
		total += this->groups.at(i).compute_salary();
	}
	
	return total;
}

double Employee::compute_salary() const {
	
	return this->salary();
}

double Subgroup::compute_salary() const {
	
	double total = 0.0;
	for (int i = 0; i < this->employees.size() i++) {
		
		total += this->employees.at(i).compute_salary();
	}
	
	return total;
}

double Group::compute_salary() const {
	
	double total = 0.0;
	for (int i = 0; i < this->subgroups.size(); i++) {
		
		total += this->subgroups.at(i).compute_salary();
	}
	
	return total;
}

