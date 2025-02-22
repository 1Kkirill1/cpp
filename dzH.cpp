#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cout << "Введите строку: ";
    cin >> input;

    int state = 0;

    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        if (isdigit(c)) {
            int digit = c - '0';
            state = (state + digit) % 3;
        } else {
            cout << "Нет" << endl;
            return 0;
        }
    }

    if (state == 0) {
        cout << "Да" << endl;
    } else {
        cout << "Нет" << endl;
    }

    return 0;
}