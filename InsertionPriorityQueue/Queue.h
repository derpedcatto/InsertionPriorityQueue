#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    int priority;
    Node* next = nullptr;
};

class Queue
{
private:
    Node* head = nullptr;
    Node* tail = nullptr;

public:
    void Print();
    void Push(int val, int priority);
    void Pop();
    void Pop(int priority);
};