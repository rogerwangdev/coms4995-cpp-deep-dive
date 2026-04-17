#include <iomanip>
#include <iostream>
#include "message.h"

template <typename T1, typename T2>
T1& baz(T1& x, const T2& y){
    x<<y;
    return x;
}

int main() {
    // std::cout << "hello c" << 2 << "cpp!" << std::endl;
    //message();
    // int x = 1;
    // std::cout<< baz(x, 3);

    std::_Setw width_manipulator = std::setw(10);
    baz(width_manipulator, 5);

    return 0;
}
    
