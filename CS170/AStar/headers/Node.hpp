#ifndef __NODE__HPP__
#define __NODE__HPP__

#include <iostream>

class Node {
    /* Stub class, will turn into Board class eventually */

    private:
        int val;
        Node* next;

    public:
        Node() : val(-1) {};
        Node(int v) : val(v) {};

        // Accessors
        int getVal() const { return this->val; };
        Node* getNext() const { return this->next; };

        // Modifiers
        void setVal(int v) { this->val = v; };
        void setNext(Node* v) { this->next = v; };
};

#endif