#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>
#include <ranges>
using namespace std;

template <typename I, typename F>
void For_Each(I b, I e, F f) {
    while (b != e) {
        f(*b);
        ++b;
    }
}

void print_int(int x)  { cout << x << ' '; }

struct IntPrinter {
    void operator()(int x) const { cout << x << ' '; }
};

struct AddX {
    int x;
    AddX(int x) : x(x) {}
    int operator()(int y) const { return x + y; }
};

template <typename F>
struct OpX {
    F op;
    int x;
    OpX(F op, int x) : op(op), x(x) {}
    int operator()(int y) const { return op(x, y); }
};

int main() {
    vector<int> v1 { 100, 101, 102, 103, 104 };
    vector<int> v2;
    
    // 1. Function object (aka functor)
    //
    // copy(v1.begin(), v1.end(), back_inserter(v2));
    // For_Each(v2.begin(), v2.end(), &print_int);    cout << '\n';
    // For_Each(v2.begin(), v2.end(), IntPrinter{});  cout << '\n';

    // 2. Stateless functors
    //
    // copy(v1.begin(), v1.end(), back_inserter(v2));
    // For_Each(v2.begin(), v2.end(), negate<int>{});
    // transform(v1.begin(), v1.end(), back_inserter(v2),
    //         negate<int>{});
    // For_Each(v2.begin(), v2.end(), IntPrinter{});  cout << '\n';

    // 3. Stateful functors
    //
    // transform(v1.begin(), v1.end(), back_inserter(v2),
    //         AddX{300});
    // For_Each(v2.begin(), v2.end(), IntPrinter{});  cout << '\n';
    //
    // transform(v1.begin(), v1.end(), back_inserter(v2),
    //         OpX{plus<int>{}, 300});
    // For_Each(v2.begin(), v2.end(), IntPrinter{});  cout << '\n';
    //
    // transform(v1.begin(), v1.end(), back_inserter(v2),
    //         bind_front(plus<int>{}, 300));
    // For_Each(v2.begin(), v2.end(), IntPrinter{});  cout << '\n';

    // 4. Bind expressions
    //
    // transform(v1.begin(), v1.end(), back_inserter(v2),
    //         bind(plus<int>{}, 300, placeholders::_1));
    // For_Each(v2.begin(), v2.end(), IntPrinter{});  cout << '\n';
    //
    // transform(v1.begin(), v1.end(), back_inserter(v2),
    //         bind(plus<int>{}, 300,
    //             bind(negate<int>{}, placeholders::_1)));
    // For_Each(v2.begin(), v2.end(), IntPrinter{});  cout << '\n';

    // 5. Lambda expressions
    //
    // transform(v1.begin(), v1.end(), back_inserter(v2),
    //         [] (int x) {
    //             return 300 + -x;
    //         }
    // );
    // For_Each(v2.begin(), v2.end(), IntPrinter{});  cout << '\n';

    // 6. Closures
    //
    // int a = 2, b = 100;
    // auto lambda = [&a, b] (int x) {
    //     // a += 13;
    //     return a * x + b;
    // };
    // a = 4, b = 1'000'000;
    // transform(v1.begin(), v1.end(), back_inserter(v2), lambda);
    // For_Each(v2.begin(), v2.end(), IntPrinter{});  cout << '\n';

    // 7. Translating lambda to a class
    //
    struct L1 {
        int& a;
        int  b;
        L1(int& a, int b) : a(a), b(b) {}
        int operator()(int x) const { return a * x + b; }
    };
    int a = 2, b = 100;
    auto lambda = L1{a, b};
    a = 4, b = 1'000'000;
    transform(v1.begin(), v1.end(), back_inserter(v2), lambda);
    For_Each(v2.begin(), v2.end(), IntPrinter{});  cout << '\n';

    // 8. Ranges
    //
    // auto v1_view = ranges::transform_view{
    //     ranges::transform_view{v1, negate<int>{}},
    //     bind_front(plus<int>{}, 300)
    // };
    // ranges::copy(v1_view, back_inserter(v2));
    // ranges::for_each(v2, IntPrinter{});  cout << '\n';

    // auto v1_view = v1 | views::transform(negate<int>{})
    //                   | views::transform(bind_front(plus<int>{}, 300));
    // ranges::copy(v1_view, back_inserter(v2));
    // ranges::for_each(v2, IntPrinter{});  cout << '\n';

    // auto v3 = v1 | views::transform(negate<int>{})
    //              | views::transform(bind_front(plus<int>{}, 300))
    //              | ranges::to<vector<int>>();
    // ranges::for_each(v3, IntPrinter{});  cout << '\n';

    // auto v = views::iota(100)
    //          | views::take(5)
    //          | views::transform(negate<int>{})
    //          | views::transform(bind_front(plus<int>{}, 300))
    //          | views::filter([](int x) { return x % 2 == 0; });
    // ranges::for_each(v, IntPrinter{});  cout << '\n';
}
