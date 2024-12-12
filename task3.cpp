#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int countWords(const string& text) {
    if (text.empty()) return 0;

    string trimmedText;
    // Удаляем лишние пробелы:
    bool prevSpace = false;
    for (char c : text) {
        if (isspace(c)) {
            if (!prevSpace) {
                trimmedText += ' ';
                prevSpace = true;
            }
        } else {
            trimmedText += c;
            prevSpace = false;
        }
    }


    if (trimmedText.empty()) return 0;

    int wordCount = 0;
    bool inWord = false;
    for (char c : trimmedText) {
        if (!isspace(c) && !inWord) {
            wordCount++;
            inWord = true;
        } else if (isspace(c)) {
            inWord = false;
        }
    }
    return wordCount;
}

int main() {
    string input;
    cout << "Введите строку:" << endl;
    getline(cin, input); 

    int wordCount = countWords(input);
    cout << "Ответ: " << wordCount << endl;

    return 0;
}

