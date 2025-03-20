#include "person.h"
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

Person::Person(const char *name_, Person* father_, Person* mother_){
    this->name = new char[strlen(name_) + 1];

    // kinda doubt this does anything 
    strcpy(name, name_);

    this->father = father_;
    this->mother = mother_;
    this->capacity = 1;
    this->numChildren = 0;
    this->children = new Person*[capacity];
}

Person::~Person(){

    /*
    // Added this for loop /***
    for (int i = 0; i < this->numChildren; i++) {
        
        delete[] this->children[i];
    }
    //********//**/

    delete[] this->children;
    delete[] this->name;
}

void Person::addChild(Person *newChild){
    if(this->numChildren == this->capacity) expand(&children, &capacity);
    children[numChildren++] = newChild;
}

void Person::printAncestors(){
    cout << endl << "Ancestors of " << name << endl;
    printLineage('u', 0);
}

void Person::printDecendents(){
    cout << endl << "Decendents of " << name << endl;
    printLineage('d', 0);
}

void Person::printLineage(char dir, int level){
    char *temp = compute_relation(level);

    if(dir == 'd'){
        for(int i = 0; i < numChildren; i++){
            cout << temp << "child: " << children[i]->getName() << endl;
            children[i]->printLineage(dir, level + 1);
        }
    } else {
        if(mother){
            cout << temp << "mother: " << mother->getName() << endl;
            mother->printLineage(dir, level + 1);
        }
        if(father){
            cout << temp << "father: " << father->getName() << endl;
            father->printLineage(dir, level + 1);
        }
    }

    delete[] temp;
}

/* helper function to compute the lineage
* if level = 0 then returns the empty string
* if level >= 1 then returns ("great ")^(level - 1) + "grand "
*/
char* Person::compute_relation(int level){
    if(level == 0) return strcpy(new char[1], "");

    char *temp = strcpy(new char[strlen("grand ") + 1], "grand ");
    
    for(int i = 2; i <= level; i++){
        char *temp2 = new char[strlen("great ") + strlen(temp) + 1];
        strcat(strcpy(temp2, "great "), temp);
        char* temp_del = temp;
        temp = temp2;
        delete[] temp_del;
    }
    return temp;
}

/* non-member function which doubles the size of t
 * NOTE: t's type will be a pointer to an array of pointers
 */
void expand(Person ***t, int *MAX){
    Person** temp = new Person*[2 * *MAX];
    memcpy(temp, *t, *MAX * sizeof(**t));
    *MAX *= 2;
    Person** tmp = *t;
    *t = temp;

    delete[] tmp;
}