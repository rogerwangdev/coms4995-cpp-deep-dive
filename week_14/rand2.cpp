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
    normal_distribution<> distro { 0.0, 3.5 };

    map<int,int> m;
    int maximum = 0;

    for (int i = 0; i < 1'000'000; ++i) {

        int x = lround( distro(engine) );

        // auto generator = 
            // bind(distro, engine);
            // bind(distro, ref(engine));
            // [distro, engine] () { return distro(engine); };           // (L1)
            // [distro, engine] () mutable { return distro(engine); };   // (L2)
            // [=] () mutable { return distro(engine); };                // (L3)
            // [&distro, &engine] () { return distro(engine); };         // (L4)
            // [&] () { return distro(engine); };                        // (L5)
        // int x = lround( generator() );

        int frequency = ++m[x];
        maximum = max(maximum, frequency);
    }

    int bar_scale = maximum / 50;
    for (const auto& [x, frequency] : m) {
        cout << setw(4) << x << '|'
             << setw(7) << frequency << '|'
             << string(frequency / bar_scale, '*') << '\n';
    }
}
