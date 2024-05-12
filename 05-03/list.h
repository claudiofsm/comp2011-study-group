#ifndef __LIST_H__
#define __LIST_H__

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data);

Node* createList(int arr[], int size);

void destroyList(Node* list);

bool checkListNodes(const Node* list, int arr[], int size);

void removeDuplicates(Node*& list);

void reverse(Node*& list);

#endif