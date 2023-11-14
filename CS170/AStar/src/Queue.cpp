#include "../headers/Queue.hpp"

void Queue::add(Node* inc) {
    /* This function assumes that queue is sorted */

    // Queue is empty
    if (this->size == 0) {
        this->head = this->tail = inc;
        this->size++;
        return;
    }

    // Only 1 value
    if (this->head == this->tail) {
        if (inc->getVal() < this->head->getVal()) {
            inc->setNext(this->head);
            this->head = inc;
        }
        else {
            this->head->setNext(inc);
            this->tail = inc;
        }
        this->size++;
        return;
    }

    // <= 2 values
    if (inc->getVal() <= this->head->getVal()) {
        inc->setNext(this->head);
        this->head = inc;
        this->size++;
        return;
    } // Otherwise, meaning if it's more than or equal to the head

    // Make an iteration node in order to move
    Node* prev = this->head;
    Node* iter = this->head->getNext();

    // Move while the value of inc is smaller than the next node
    while(inc->getVal() > iter->getVal()) {
        // Change the tail
        if (iter->getNext() == nullptr) {
            iter->setNext(inc);
            this->tail = inc;
            this->size++;
            return;
        }
        prev = iter;
        iter = iter->getNext(); // Move iter one position
    }
    // Now that we have iter in the right position, insert
    inc->setNext(iter);
    prev->setNext(inc);
    this->size++;
    return;
}

// Not doing these ones for now, not necessary as inserts work in ascending order
void Queue::sortAscending() {

    std::cout << "Queue:: sorting ascendingly" << std::endl;
    return;
}

// Not doing these for now, not necessary FOR NOW
void Queue::sortDescending() {

    std::cout << "Queue:: sorting descendingly" << std::endl;
    return;
}

void Queue::pop_front() {
    Node* tmp = this->head;

    // Queue is empty
    if (this->head == nullptr) {
        return;
    }
    // Only 1 item in Queue
    if (this->head == this->tail) {
        this->head = this->tail = nullptr;
        delete tmp;
        return;
    }

    // Otherwise, meaning >= 2 items
    this->head = this->head->getNext();
    delete tmp;
}