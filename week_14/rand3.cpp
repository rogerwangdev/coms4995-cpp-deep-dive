#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <functional>
using namespace std;

int main() {
    random_device rd;
    random_device::result_type seed;
    seed = (rd.entropy() > 0) ? rd() : time(nullptr);

    mt19937 engine { seed };
    // default_random_engine engine { seed };

    cout << "typeid(engine).name():\n" << typeid(engine).name() << '\n';
    cout << "\nsizeof(engine): " << sizeof(engine) << '\n';
}
