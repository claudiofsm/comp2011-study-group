#include <iostream>
#include "remove_duplicates_tests.h"
#include "reverse_tests.h"

using namespace std;

void printResult(const char* name, bool result) {
    cout << name << ": ";
    if (result) {
        cout << "Passed";
    } else {
        cout << "FAILED";
    }
    cout << endl;
}

void runRemoveDuplicatesTests() {
    cout << "Test removeDuplicates() function" << endl;
    cout << "--------------------------------" << endl;
    remove_duplicates_tests::testNullptr();
    remove_duplicates_tests::testSingleElementList();
    remove_duplicates_tests::testListWithoutDuplicates();
    remove_duplicates_tests::testListWithDuplicates();
    cout << endl;
}

void runReverseTests() {
    cout << "Test reverse() function" << endl;
    cout << "-----------------------" << endl;
    reverse_tests::testNullptr();
    reverse_tests::testSingleElementList();
    reverse_tests::testMultipleElementList();
    cout << endl;
}
