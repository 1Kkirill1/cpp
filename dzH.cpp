#include <iostream>
#include <string>

// Определяем состояния конечного автомата
enum State {
    REMAINDER_0 = 0, // Остаток 0 (число делится на 3)
    REMAINDER_1 = 1, // Остаток 1
    REMAINDER_2 = 2 // Остаток 2
};

// Функция для проверки, делится ли число на 3
bool isDivisibleBy3(const std::string& str) {
    State currentState = REMAINDER_0; // Начинаем с состояния 0

    for (char ch : str) {
        if (ch < '0' || ch > '9') { // Проверяем, что символ является цифрой
            return false; // Если строка содержит не цифры, возвращаем false
        }

        int digit = ch - '0'; // Преобразуем символ в цифру

        // Переход между состояниями в зависимости от текущего состояния и цифры
        switch (currentState) {
            case REMAINDER_0:
                currentState = static_cast<State>((digit) % 3);
            break;
            case REMAINDER_1:
                currentState = static_cast<State>((1 + digit) % 3);
            break;
            case REMAINDER_2:
                currentState = static_cast<State>((2 + digit) % 3);
            break;
        }
    }

    std::cout << str;

    // Если конечное состояние REMAINDER_0, число делится на 3
    if ( currentState == REMAINDER_0) {
        std::cout << " - Да\n";
    } else {
        std::cout << " - Нет\n";
    }

    return currentState == REMAINDER_0;
}

int dzH() {
     std::cout << "Является ли строка число делящимся на 3\n";
    isDivisibleBy3("028946703");
    return 0;
}