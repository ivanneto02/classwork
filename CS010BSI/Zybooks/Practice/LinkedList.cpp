#include <iostream>

using namespace std;

class node {

    public:

        node(int data) {

            cout << "In linked list constructor (" << data << ")" << endl;
            this->data = data;
        }

        ~node() {
            
            cout << "In linked list destructor (" << this->data << ")" << endl;
        }

        int data;
        node* next;

};

class LinkedList {

    public:

        LinkedList();
        ~LinkedList();

        void prepend(int);
        //void append(int);

        node* head;

};

LinkedList::LinkedList() {
    cout << "In LinkedList constructor" << endl;
    this->head = nullptr;
}

LinkedList::~LinkedList() {

    cout << "In LinkedList destructor" << endl;

    while (head) {

        node* temp = this->head->next;
        delete this->head;
        this->head = temp;

    }

}

void LinkedList::prepend(int data) {

    node* newNode = new node(data);
    newNode->next = this->head;
    this->head = newNode;
   
}

int main() {

    LinkedList* list1 = new LinkedList();

    for (int i = 1; i < 11; i++) {

        list1->prepend(i);

    }

    cout << "Right before deletion..." << endl;
    delete list1;

    return 0;
}