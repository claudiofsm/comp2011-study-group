#include "list.h"

void removeDuplicates(Node*& list) {
    if (nullptr == list) {
        return;
    }

    Node* current = list;
    while (nullptr != current->next) {
        if (current->data == current->next->data) {
            Node* afterNext = current->next->next;
            delete current->next;
            current->next = afterNext;
        } else {
            current = current->next;
        }
    }
}

void reverse(Node*& list) {
    if (nullptr == list) {
        return;
    }

    Node* current = list;
    Node* next = nullptr;
    Node* head = nullptr;

    while (nullptr != current) {
        next = current->next;

        current->next = head;
        head = current;

        current = next;
    }

    list = head;
}
