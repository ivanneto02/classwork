#ifndef __QUEUE_TESTS_HPP__
#define __QUEUE_TESTS_HPP__

#include "gtest/gtest.h"
#include "../headers/Queue.hpp"

TEST(QueueTests, testAdd1) {
    
    int arr[1] = {2};

    // Edge case 1:
    Node* node1 = new Node(2);

    Queue newQueue;
    newQueue.add(node1);

    EXPECT_EQ(newQueue.getSize(), 1);
    EXPECT_EQ(newQueue.getFront()->getVal(), 2);

    Node* iter = newQueue.getFront();
    for (int i = 0; i < newQueue.getSize(); i++) {
        
        EXPECT_EQ(iter->getVal(), arr[i]);
        iter = iter->getNext();
    }
}

TEST(QueueTests, testAdd2) {
    
    int arr[2] = {2, 2};

    // Edge case 2:
    Node* node1 = new Node(2);
    Node* node2 = new Node(2);

    Queue newQueue;
    newQueue.add(node1);
    newQueue.add(node2);

    EXPECT_EQ(newQueue.getSize(), 2);
    EXPECT_EQ(newQueue.getFront()->getVal(), 2);
    EXPECT_EQ(newQueue.getBack()->getVal(), 2);

    Node* iter = newQueue.getFront();
    for (int i = 0; i < newQueue.getSize(); i++) {
        
        EXPECT_EQ(iter->getVal(), arr[i]);
        iter = iter->getNext();
    }
}

TEST(QueueTests, testAdd3) {
    
    int arr[3] = {2, 2, 4};

    // Edge case 3:
    Node* node1 = new Node(2);
    Node* node2 = new Node(2);
    Node* node3 = new Node(4);

    Queue newQueue;
    newQueue.add(node1);
    newQueue.add(node2);
    newQueue.add(node3);

    EXPECT_EQ(newQueue.getSize(), 3);
    EXPECT_EQ(newQueue.getFront()->getVal(), 2);
    EXPECT_EQ(newQueue.getBack()->getVal(), 4);

    Node* iter = newQueue.getFront();
    for (int i = 0; i < newQueue.getSize(); i++) {
        
        EXPECT_EQ(iter->getVal(), arr[i]);
        iter = iter->getNext();
    }
}

TEST(QueueTests, testAdd4) {
    
    int arr[2] = {2, 4};

    // Edge case 4:
    Node* node1 = new Node(4);
    Node* node2 = new Node(2);

    Queue newQueue;
    newQueue.add(node1);
    newQueue.add(node2);

    EXPECT_EQ(newQueue.getSize(), 2);
    EXPECT_EQ(newQueue.getFront()->getVal(), 2);
    EXPECT_EQ(newQueue.getBack()->getVal(), 4);

    Node* iter = newQueue.getFront();
    for (int i = 0; i < newQueue.getSize(); i++) {
        
        EXPECT_EQ(iter->getVal(), arr[i]);
        iter = iter->getNext();
    }
}

TEST(QueueTests, testAdd5) {
    
    int arr[2] = {1, 2};
    
    // Edge case 5:
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);

    Queue newQueue;
    newQueue.add(node1);
    newQueue.add(node2);

    EXPECT_EQ(newQueue.getSize(), 2);
    EXPECT_EQ(newQueue.getFront()->getVal(), 1);
    EXPECT_EQ(newQueue.getBack()->getVal(), 2);

    Node* iter = newQueue.getFront();
    for (int i = 0; i < newQueue.getSize(); i++) {
        
        EXPECT_EQ(iter->getVal(), arr[i]);
        iter = iter->getNext();
    }
}

TEST(QueueTests, testAdd6) {
    
    int arr[7] = {1, 1, 2, 2, 5, 6, 7};

    // Edge case 5:
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(5);
    Node* node4 = new Node(1);
    Node* node5 = new Node(2);
    Node* node6 = new Node(7);
    Node* node7 = new Node(6);

    Queue newQueue;
    newQueue.add(node1);
    newQueue.add(node2);
    newQueue.add(node3);
    newQueue.add(node4);
    newQueue.add(node5);
    newQueue.add(node6);
    newQueue.add(node7);

    EXPECT_EQ(newQueue.getSize(), 7);
    EXPECT_EQ(newQueue.getFront()->getVal(), 1);
    EXPECT_EQ(newQueue.getBack()->getVal(), 7);

    // // Ignore
    // std::cout << newQueue.getFront()->getVal() << std::endl;
    // std::cout << newQueue.getFront()->getNext()->getVal() << std::endl;
    // std::cout << newQueue.getFront()->getNext()->getNext()->getVal() << std::endl;
    // std::cout << newQueue.getFront()->getNext()->getNext()->getNext()->getVal() << std::endl;
    // // Ignore

    Node* iter = newQueue.getFront();
    for (int i = 0; i < newQueue.getSize(); i++) {
        
        EXPECT_EQ(iter->getVal(), arr[i]);
        iter = iter->getNext();
    }
}

#endif