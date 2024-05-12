#include <iostream>
#include "list.h"
#include "reverse_tests.h"
#include "testcases.h"

void reverse_tests::testNullptr() {
    Node* list = nullptr;
    reverse(list);
    printResult("Test null list", nullptr == list);
}

void reverse_tests::testSingleElementList() {
    int arr[] = { 3 };
    Node* list = createList(arr, 1);
    reverse(list);
    printResult("Test single element list", checkListNodes(list, arr, 1));
    destroyList(list);
}

void reverse_tests::testMultipleElementList() {
    int arr[] = { 5, 6, 7, 8, 9 };
    Node* list = createList(arr, 5);
    reverse(list);
    int result[] = { 9, 8, 7, 6, 5 };
    printResult("Test multiple element list", checkListNodes(list, result, 5));
    destroyList(list);
}
