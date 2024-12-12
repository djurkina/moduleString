#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isValidNumber(const string & s) {
    if (s.empty()) return false;


    char firstChar = s[0];
    if (!isdigit(firstChar) && firstChar != '.' && firstChar != '-') return false;

    int pointCount = 0;
    int digitCount = 0;
    for (char c : s) {
        if (isdigit(c)) {
            digitCount++;
        } else if (c == '.') {
            pointCount++;
        } else if (c != '-' || c != firstChar){
            return false;
        }
    }

    return digitCount > 0 && pointCount <= 1;
}

int main() {
    string input;
    cout << "Введите строку: ";
    cin >> input;

    if (isValidNumber(input)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

