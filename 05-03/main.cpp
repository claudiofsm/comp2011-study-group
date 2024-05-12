#include <iostream>
#include "list.h"
#include "reverse_tests.h"
#include "testcases.h"

using namespace std;

int main() {
    runRemoveDuplicatesTests();
    runReverseTests();
    cout << "All testcases completed.";
    return 0;
}