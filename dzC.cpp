#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

// "Реализовать класс с виртуальным
// методом size (Фигура, Shape)
// используя наследование,
// создать классы отдельных фигур:
// Rectangular, Triangle, Circle
// и использовать их в main"

// Абстрактный базовый класс Shape
class Shape {
public:
    // Виртуальный метод для вычисления размера (площади)
    virtual double size() const = 0;

    // Виртуальный деструктор для корректного удаления объектов производных классов
    virtual ~Shape() = default;
};

// Класс прямоугольника
class Rectangular : public Shape {
private:
    double width;
    double height;

public:
    Rectangular(double w, double h) : width(w), height(h) {}

    // Переопределение метода size для прямоугольника
    double size() const override {
        return width * height;
    }
};

// Класс треугольника
class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    // Переопределение метода size для треугольника
    double size() const override {
        return 0.5 * base * height;
    }
};

// Класс круга
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Переопределение метода size для круга
    double size() const override {
        return M_PI * radius * radius;
    }
};

int dzC() {
    // Создаем объекты фигур
    std::unique_ptr<Shape> rect = std::make_unique<Rectangular>(5.0, 10.0);
    std::unique_ptr<Shape> tri = std::make_unique<Triangle>(4.0, 6.0);
    std::unique_ptr<Shape> circle = std::make_unique<Circle>(3.0);

    // Используем вектор для хранения указателей на объекты Shape
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::move(rect));
    shapes.push_back(std::move(tri));
    shapes.push_back(std::move(circle));

    // Выводим размеры фигур
    for (const auto& shape : shapes) {
        std::cout << "Size: " << shape->size() << std::endl;
    }

    return 0;
}