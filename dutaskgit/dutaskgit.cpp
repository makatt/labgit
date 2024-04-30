#include <iostream>
#include <cmath>
#include <clocale>

class Trapezoid {
private:
    double x1, y1, x2, y2, x3, y3, x4, y4;

public:
    Trapezoid(double _x1, double _y1, double _x2, double _y2, double _x3, double _y3, double _x4, double _y4) {
        x1 = _x1;
        y1 = _y1;
        x2 = _x2;
        y2 = _y2;
        x3 = _x3;
        y3 = _y3;
        x4 = _x4;
        y4 = _y4;
    }

    bool isIsosceles() {
        double d1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        double d2 = sqrt(pow(x3 - x4, 2) + pow(y3 - y4, 2));
        double d3 = sqrt(pow(x4 - x1, 2) + pow(y4 - y1, 2));
        double d4 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));

        return (d1 == d2) || (d2 == d3) || (d3 == d4) || (d4 == d1);
    }

    double sideLength(double x1, double y1, double x2, double y2) {
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }

    double perimeter() {
        double d1 = sideLength(x1, y1, x2, y2);
        double d2 = sideLength(x2, y2, x3, y3);
        double d3 = sideLength(x3, y3, x4, y4);
        double d4 = sideLength(x4, y4, x1, y1);

        return d1 + d2 + d3 + d4;
    }

    double area() {
        double d1 = sideLength(x1, y1, x2, y2);
        double d2 = sideLength(x3, y3, x4, y4);
        double height = fabs(y2 - y1); 

        return 0.5 * (d1 + d2) * height;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    int N;
    std::cout << "Введите количество трапеций: ";
    std::cin >> N;

    double totalArea = 0.0;
    double averageArea = 0.0;
    int count = 0;

    for (int i = 0; i < N; ++i) {
        double x1, y1, x2, y2, x3, y3, x4, y4;
        std::cout << "Введите координаты трапеции " << i + 1 << ": ";
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        Trapezoid trap(x1, y1, x2, y2, x3, y3, x4, y4);

        totalArea += trap.area();
    }

    if (N != 0) {
        averageArea = totalArea / N;

        for (int i = 0; i < N; ++i) {
            double x1, y1, x2, y2, x3, y3, x4, y4;
            std::cout << "Введите координаты трапеции " << i + 1 << ": ";
            std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

            Trapezoid trap(x1, y1, x2, y2, x3, y3, x4, y4);

            if (trap.area() > averageArea) {
                count++;
            }
        }
    }

    std::cout << "Количество трапеций площадью больше средней: " << count << std::endl;

    return 0;
}