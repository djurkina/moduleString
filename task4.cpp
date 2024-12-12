#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string secretNumber, guess;

    cout << "Введите задуманное число: ";
    cin >> secretNumber;

    cout << "Введите второе число: ";
    cin >> guess;

    if (secretNumber.length() != 4 || guess.length() != 4) {
        cout << "Числа должны быть четырехзначными!" << endl;
        return 1;
    }

    int bulls = 0;
    int cows = 0;
    map<char, int> secretCount;

    for (size_t i = 0; i < 4; ++i) {
        if (secretNumber[i] == guess[i]) {
            bulls++;
        } else {
            secretCount[secretNumber[i]]++;
        }
    }


    for (size_t i = 0; i < 4; ++i) {
        if (secretNumber[i] != guess[i] && secretCount[guess[i]] > 0) {
            cows++;
            secretCount[guess[i]]--;
        }
    }

    cout << "Быков: " << bulls << ", коров: " << cows << endl;

    return 0;
}

