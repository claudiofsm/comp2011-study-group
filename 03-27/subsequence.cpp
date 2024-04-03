#include <iostream>

using namespace std;

bool isSubsequence(string first, string second) {
    if (first.length() < second.length()) {
        return false;
    }
    if (second.empty()) {
        return true;
    }
    if (first[0] == second[0]) {
        return isSubsequence(first.substr(1), second.substr(1));
    } else {
        return isSubsequence(first.substr(1), second);
    }
}

int main() {
    cout << "Please enter the first string: ";

    string first;
    cin >> first;

    cout << "Please enter the second string: ";

    string second;
    cin >> second;

    cout << "Result: " << std::boolalpha << isSubsequence(first, second) << endl;

    return 0;
}