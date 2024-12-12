#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool isValidTime(const string & time) {
    if (time.length() != 5 || time[2] != ':') return false;
    for (int i = 0; i < 2; ++i) {
        if (time[i] < '0' || time[i] > '9') return false;
    }
    for (int i = 3; i < 5; ++i) {
        if (time[i] < '0' || time[i] > '9') return false;
    }
    int hh = stoi(time.substr(0, 2));
    int mm = stoi(time.substr(3, 2));
    return (hh >= 0 && hh <= 23 && mm >= 0 && mm <= 59);
}

int main() {
    string departureTime, arrivalTime;

    cout << "Введите время отправления (HH:MM): ";
    cin >> departureTime;

    while (!isValidTime(departureTime)) {
        cout << "Некорректный формат времени. Пожалуйста, введите время в формате HH:MM: ";
        cin >> departureTime;
    }

    cout << "Введите время прибытия (HH:MM): ";
    cin >> arrivalTime;

    while (!isValidTime(arrivalTime)) {
        cout << "Некорректный формат времени. Пожалуйста, введите время в формате HH:MM: ";
        cin >> arrivalTime;
    }

    int depHour = stoi(departureTime.substr(0, 2));
    int depMin = stoi(departureTime.substr(3, 2));
    int arrHour = stoi(arrivalTime.substr(0, 2));
    int arrMin = stoi(arrivalTime.substr(3, 2));

    int totalMinutes = arrHour * 60 + arrMin - (depHour * 60 + depMin);

    if (totalMinutes < 0) {
        totalMinutes += 24 * 60;
    }

    int hours = totalMinutes / 60;
    int minutes = totalMinutes % 60;

    cout << "Поездка составила " << hours << " ч. " << minutes << " мин." << endl;

    return 0;
}

