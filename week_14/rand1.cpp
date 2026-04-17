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

    // 1. Random number generator using C functions
    //
    srandom(time(nullptr)); // current time as seed
    auto engine = &random;  // random() in the C library as engine
    auto distro = [] (auto& some_engine) {
        // get an unsigned random integer from engine,
        // and "distribute" it in [-10,10]
        return some_engine() % 21 - 10;
    };

    // 2. Random number generator in C++
    //
    // random_device rd;
    // random_device::result_type seed;
    // seed = (rd.entropy() > 0) ? rd() : time(nullptr);
    // default_random_engine engine { seed };
    // uniform_int_distribution<> distro { -10, 10 };

    map<int,int> m;
    for (int i = 0; i < 1'000'000; ++i) {
        int x = distro(engine);
        ++m[x];
    }
    for (const auto& [x, frequency] : m) {
        cout << setw(4) << x << '|' << frequency << '\n';
    }
}
