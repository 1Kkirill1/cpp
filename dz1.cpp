#include <iostream>
#include <string>

// Дана строка, напечатать Да, если она
// представима в виде
// математического выражения,
// Zв котором не могут две скобки идти подряд,
// иначе напечатать нет
// Необходимо реализовать конечный автомат


enum class State { Start, AfterOpen, AfterClose };

bool checkExpression(const std::string& expression) {
    auto currentState = State::Start;

    for (const char c : expression) {
        switch (currentState) {
            case State::Start:
                if (c == '(' || c == '[' || c == '{')
                    currentState = State::AfterOpen;
                else if (c == ')' || c == ']' || c == '}')
                    return false;
            break;

            case State::AfterOpen:
                if (c == '(' || c == '[' || c == '{')
                    return false;
                if (c == ')' || c == ']' || c == '}')
                    currentState = State::AfterClose;
            break;

            case State::AfterClose:
                if (c == ')' || c == ']' || c == '}')
                    return false;

                currentState = State::Start;
        }
    }

    return true;
}

int dz1() {
    const std::string expressionStr = "a+b+c+(h+w)=sb";

    const bool result = checkExpression(expressionStr);

    std::cout << (result ? "Да" : "Нет") << std::endl;

    return 0;
}