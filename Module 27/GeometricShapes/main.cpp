#include <iostream>
#include <cmath>

enum class ColorID {
    NONE,
    RED,
    BLUE,
    GREEN
};

class Figure {
    std::string name = "none";
    ColorID color = ColorID::NONE;
    double x = 0;
    double y = 0;
    double xFrame = 0;
    double yFrame = 0;
    double squareF = 0;

public:
<<<<<<< HEAD
=======

>>>>>>> origin/main
    void info() {
        std::cout << name << " INFO" << std::endl;
        std::cout << "Coordinates of the center X: " << x << " Y: " << y << std::endl;
        std::cout << "Color: ";
        switch (color) {
            case ColorID::NONE:
                std::cout << "NO color" << std::endl;
                break;
            case ColorID::RED:
<<<<<<< HEAD
                std::cout << "red" << std::endl;
=======

>>>>>>> origin/main
                break;
            case ColorID::BLUE:
                std::cout << "blue" << std::endl;
                break;
            case ColorID::GREEN:
                std::cout << "green" << std::endl;
                break;
        }
        std::cout << "Square: " << squareF << std::endl;
        std::cout << "Frame";
        if (yFrame == 0) {
            std::cout << " is Square with side :" << xFrame << std::endl;
        } else {
            std::cout << "is Rectangle with sides: X= " << xFrame << " Y: " << yFrame << std::endl << std::endl;
<<<<<<< HEAD
=======
            std::cout << "A: x = " + std::to_string(x) + " y = " + std::to_string(y) + "\n" +
                        "B: x = " + std::to_string(x) + " y = " + std::to_string(y + yFrame) + "\n" +
                        "C: x = " + std::to_string(x + xFrame) + " y = " + std::to_string(y + yFrame) + "\n" +
                        "D: x = " + std::to_string(x + xFrame) + " y = " + std::to_string(y) + "\n" << std::endl;
>>>>>>> origin/main
        }
    }

protected:
    void initialization() {
        std::cout << "Enter the coordinates of the center (X Y)" << std::endl << ">: ";
<<<<<<< HEAD
        std::cin >> x >> y;
=======
        std::cin >> x;
        std::cout << ">: ";
        std::cin >> y;
>>>>>>> origin/main
        std::cout << "Enter the number of color: "
                  << "\n0 - No color"
                  << "\n1 - Red"
                  << "\n2 - Blue"
                  << "\n3 - Green" << std::endl << ">:";
        int iColor;
        std::cin >> iColor;
        if (iColor == 1) {
            color = ColorID::RED;
        } else if (iColor == 2) {
            color = ColorID::BLUE;
        } else if (iColor == 3) {
            color = ColorID::GREEN;
        } else {
            color = ColorID::NONE;
        }
    }

    void set_name(std::string inName) {
        name = inName;
    }

    void set_square(double inS) {
        squareF = inS;
    }

    void set_frame(double inX, double inY) {
        xFrame = inX;
        yFrame = inY;
    }
<<<<<<< HEAD
=======

>>>>>>> origin/main
};

class Circle : public Figure {
    const std::string name = "Circle";
    double radius = 0;
    double squareCircle() {
        return (3.1415 * radius * radius);
    }
public:
    void init() {
        Figure::initialization();
        std::cout << "Enter radius:" << std::endl << ">: ";
        std::cin >> radius;
        Figure::set_square(squareCircle());
        Figure::set_name(name);
        Figure::set_frame(2 * radius, 0);
    }
};

class Square : public Figure {
    const std::string name = "Square";
    double side = 0;
    double squareSquare() {
        return (side * side);
    }
public:
    void init() {
        Figure::initialization();
        std::cout << "Enter length side:" << std::endl << ">: ";
        std::cin >> side;
        Figure::set_square(squareSquare());
        Figure::set_name(name);
        Figure::set_frame(side, 0);
    }
};

class Triangle : public Figure {
    const std::string name = "Triangle";
    double side = 0;
    double squareTriangle() {
        return (side * side * sqrt(3) / 4);
    }
public:
    void init() {
        Figure::initialization();
        std::cout << "Enter length side:" << std::endl << ">: ";
        std::cin >> side;
        Figure::set_square(squareTriangle());
        Figure::set_name(name);
        Figure::set_frame(side, side * sqrt(3) / 2);
    }
};

class Rectangle : public Figure {
    const std::string name = "Rectangle";
    double length = 0;
    double width = 0;
    double squareRectangle() {
        return (length * width);
    }
public:
<<<<<<< HEAD
=======

>>>>>>> origin/main
    void init() {
        Figure::initialization();
        std::cout << "Enter length side:" << std::endl << ">: ";
        std::cin >> length;
        std::cout << "Enter width side:" << std::endl << ">: ";
        std::cin >> width;
        Figure::set_square(squareRectangle());
        Figure::set_name(name);
        Figure::set_frame(length, width);
    }
<<<<<<< HEAD
};

Rectangle* getOuterRectangle() {

}



int main() {
    Circle::Figure f {};

    while (true) {
        std::string com;
        std::cout << "Enter command (circle, square, triangle, rectangle, exit)" << std::endl << ">: ";
=======

};

int main() {
    Circle::Figure f {};
    std::string com;

    while (com != "exit") {
        std::cout << "Enter command (circle, square, triangle, rectangle, exit)\n" << ">: ";
>>>>>>> origin/main
        std::cin >> com;

        if (com == "circle") {
            Circle circle;
            circle.init();
            circle.info();
        } else if (com == "square") {
            Square square;
            square.init();
            square.info();
        } else if (com == "triangle") {
            Triangle triangle;
            triangle.init();
            triangle.info();
        } else if (com == "rectangle") {
            Rectangle rectangle;
            rectangle.init();
            rectangle.info();
<<<<<<< HEAD
        } else if (com == "exit") {
            break;
        } else {
            std::cout << "Error command" << std::endl;
        }
    }
=======
        } else if (com != "exit"){
            std::cout << "Error command" << std::endl;
        }
    }
    std::cout << "Close program!" << std::endl;
>>>>>>> origin/main
    return 0;
}