#include <iostream>

class Point{
public:
    int x = 0;
    int y = 0;
};

class Window {
private:
    Point left_up_angle;
    int win_heigth = 10;
    int win_width = 10;
    static const int screen_width = 50;
    static const int screen_height = 80;
public:
    void setMove (Point vec) {
        if (vec.x < 0) vec.x = 0;
        if (vec.x > 80) vec.x = 80 - 1;
        if (vec.y < 0) vec.y = 0;
        if (vec.y > 50) vec.y = 50 - 1;
        left_up_angle = vec;
    }

    void resize (int new_heigth, int new_width) {
        win_heigth = new_heigth;
        win_width = new_width;
    }

    void display (int array[screen_width][screen_height]) {
        for (int i = 0; i < screen_width; i++) {
            for (int j = 0; j < screen_height; j++) {
                std::cout << array[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void fillingArray (int array[screen_width][screen_height]) {
        bool findPoint = false;
        int column_Start = 0, row = 0, col = 0;

        for (int i = 0; i < screen_width; i++) {
            col = 0;
            for (int j = 0; j < screen_height; j++) {
                if ((left_up_angle.x == j) && (left_up_angle.y == i)) {
                    column_Start = j;
                    findPoint = true;
                }
                if ((row < win_heigth) && (col < win_width) && findPoint && (j >= column_Start)) {
                    array[i][j] = 1;
                    col++;
                } else array[i][j] = 0;
            }
            if (findPoint) row++;
        }
    }
};
int main () {
    Window window;
    int screen[50][80];
    std::string command;

    while (true){
        std::cout << "Enter command:"<< std::endl;
        std::cin >> command;
        if (command == "move"){
            Point vec;
            std::cout << "Enter x and y:" << std::endl;
            std::cin >> vec.x >> vec.y;
            if (vec.x < 0 || vec.x > 50 || vec.y < 0 || vec.y > 80) {
                std::cerr << "Incorrect!";
                return 0;
            } else {
                window.setMove(vec);
            }
        }
        else if (command == "resize"){
            std::cout << "Enter a new heigth  and  width:" << std::endl;
            int new_heigth, new_width;
            std::cin >> new_heigth >> new_width;
            if (new_heigth < 0 || new_heigth > 80 || new_width < 0 || new_width > 50) {
                std::cerr << "Incorrect!";
                return 0;
            }
            window.resize(new_heigth, new_width);
        }
        else if (command == "display"){
            window.fillingArray(screen);
            window.display(screen);
        }
        else if (command == "exit") return 0;
    }
}