#include <iostream>

class Pt {
    public:
        double x;
        double y;



    Pt(double _x = 4.0, double _y = 5.0) {
        x = _x;
        y = _y;
        std::cout << "hi" << std::endl;
    }

    ~Pt() {
        std::cout << "bye" << std::endl;
    }

    void print() {
        std::cout << "(" << this->x << "," << this->y << ")" << std::endl;
    }
};

int main() {

    std::cout << "Start" << std::endl;
    {
        Pt p1;
        p1.print();
    }
    std::cout << "End" << std::endl;

}