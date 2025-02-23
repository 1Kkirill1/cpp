//"Реализовать простейшее
//графическое приложение
//с пустым окном"

#include <SFML/Graphics.hpp>
#include <iostream>

int dzJ() {
    // Создаем окно размером 1000x1000 с заголовком "Graphic1.1"
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Graphic1.1");

    // Создаем прямоугольник размером 50x50
    sf::Vector2f size(50, 50);
    sf::RectangleShape rect(size);

    // Устанавливаем позицию прямоугольника
    sf::Vector2f position(100, 100);
    rect.setPosition(position);

    // Устанавливаем цвет прямоугольника
    rect.setFillColor(sf::Color::Yellow);

    // Создаем объект для отслеживания времени
    sf::Clock clock;

    // Основной цикл программы
    while (window.isOpen()) {
        sf::Event event;
        // Обработка событий
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Очистка окна черным цветом
        window.clear(sf::Color::Black);

        // Рисуем прямоугольник
        window.draw(rect);

        // Обновление окна
        window.display();
    }

    return 0;
}