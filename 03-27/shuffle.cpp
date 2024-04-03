#include <iostream>
#include <cmath>

using namespace std;

string randomShuffle(string input) {
    if (input.length() <= 1) {
        return input;
    }

    int pos = rand() % input.length();
    return input.at(pos) + randomShuffle(input.substr(0, pos) + input.substr(pos + 1));
}

int main() {
    srand(time(0));

    cout << "Please enter the string to be shuffled: ";

    string s;
    cin >> s;

    cout << "The shuffled version is: " << randomShuffle(s) << endl;

    return 0;
}