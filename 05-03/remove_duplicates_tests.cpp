#include <iostream>
#include "list.h"
#include "remove_duplicates_tests.h"
#include "testcases.h"

void remove_duplicates_tests::testNullptr() {
    Node* list = nullptr;
    removeDuplicates(list);
    printResult("Test null list", nullptr == list);
}

void remove_duplicates_tests::testSingleElementList() {
    int arr[] = { 5 };
    Node* list = createList(arr, 1);
    removeDuplicates(list);
    printResult("Single element list", checkListNodes(list, arr, 1));
    destroyList(list);
}

void remove_duplicates_tests::testListWithoutDuplicates() {
    int arr[] = { 7, 8, 9 };
    Node* list = createList(arr, 3);
    removeDuplicates(list);
    printResult("List without duplicates", checkListNodes(list, arr, 3));
    destroyList(list);
}

void withDuplicatesA() {
    int arr[] = { 6, 6};
    int result[] { 6 };
    Node* list = createList(arr, 2);
    removeDuplicates(list);
    printResult("List with duplicates - A", checkListNodes(list, result, 1));
    destroyList(list);
}

void withDuplicatesB() {
    int arr[] = { 6, 6, 8 };
    int result[] { 6, 8 };
    Node* list = createList(arr, 3);
    removeDuplicates(list);
    printResult("List with duplicates - B", checkListNodes(list, result, 2));
    destroyList(list);
}

void withDuplicatesC() {
    int arr[] = { 6, 6, 7, 9, 9, 9 };
    int result[] { 6, 7, 9 };
    Node* list = createList(arr, 6);
    removeDuplicates(list);
    printResult("List with duplicates - C", checkListNodes(list, result, 3));
    destroyList(list);
}

void withDuplicatesD() {
    int arr[] = { 6, 7, 7, 8, 8, 8 };
    int result[] { 6, 7, 8 };
    Node* list = createList(arr, 6);
    removeDuplicates(list);
    printResult("List with duplicates - D", checkListNodes(list, result, 3));
    destroyList(list);
}

void remove_duplicates_tests::testListWithDuplicates() {
    withDuplicatesA();
    withDuplicatesB();
    withDuplicatesC();
    withDuplicatesD();
}
