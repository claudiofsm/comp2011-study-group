#include "list.h"

Node* createNode(int data) {
    Node* n = new Node;
    n->data = data;
    n->next = nullptr;
    return n;
}

Node* createList(int arr[], int size) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < size; i++) {
        Node* n = createNode(arr[i]);
        if (nullptr == head) {
            head = n;
            tail = head;
        } else {
            tail->next = n;
            tail = n;
        }
    }
    return head;
}

void destroyList(Node* list) {
    Node* current = list;
    while (nullptr != current) {
        Node* temp = current->next;
        delete current;
        current = temp;
    }
}

bool checkListNodes(const Node* list, int arr[], int size) {
    if (nullptr == list) {
        return 0 == size;
    }
    const Node* current = list;
    for (int i = 0; i < size; i++) {
        if (current->data != arr[i]) {
            return false;
        }
        current = current->next;
    }
    return nullptr == current;
}
