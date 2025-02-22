#include <iostream>
#include <string>

// "Реализовать класс с виртуальным
// методом draw (Car)
// используя наследование,
// создать классы отдельных машин:
// SportCar, Tractor,
// создать массив конкретных машин
// и последовательно нарисовать их"


#include <iostream>
#include <vector>
#include <memory>

// Базовый класс Car с виртуальным методом draw
class Car {
public:
    // Виртуальный метод для отрисовки машины
    virtual void draw() const {
        std::cout << "Drawing a generic car\n";
    }

    // Виртуальный деструктор для корректного удаления объектов производных классов
    virtual ~Car() = default;
};

// Производный класс SportCar
class SportCar : public Car {
public:
    // Переопределение метода draw для SportCar
    void draw() const override {
        std::cout << "Drawing a sport car: 🚗\n";
    }
};

// Производный класс Tractor
class Tractor : public Car {
public:
    // Переопределение метода draw для Tractor
    void draw() const override {
        std::cout << "Drawing a tractor: 🚜\n";
    }
};

int dzD() {
    // Создаем объекты машин
    std::unique_ptr<Car> car1 = std::make_unique<SportCar>();
    std::unique_ptr<Car> car2 = std::make_unique<Tractor>();

    // Используем вектор для хранения указателей на объекты Car
    std::vector<std::unique_ptr<Car>> cars;
    cars.push_back(std::move(car1));
    cars.push_back(std::move(car2));

    // Вызываем метод draw для каждого объекта
    for (const auto& car : cars) {
        car->draw(); // Полиморфный вызов
    }

    return 0;
}