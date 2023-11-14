#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

#include "Node.hpp"

class Queue {

    private:
        int size;
        Node* head;
        Node* tail;

    public:
        // Constructors
        Queue() : size(0), head(nullptr), tail(nullptr) {};
        
        // Accessors
        Node* getFront() const { return this->head; };
        Node* getBack() const { return this->tail; };
        int getSize() const { return this->size; };

        // Modifiers
        void add(Node*);
        void pop_front(); // Gets front node and deletes it
        void sortAscending();   // Simple bubble sorts
        void sortDescending();  // Simple bubble sorts
};

#endif