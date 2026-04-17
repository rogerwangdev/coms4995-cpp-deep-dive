#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <iostream>
#include <iterator>
using namespace std;

// Pretty much the same as std::for_each
template <typename I, typename F>
void For_Each(I b, I e, F f) {
    while (b != e) {
        f(*b);
        ++b;
    }
}

void print_int(int x)  { cout << x << ' '; }

int main() {
    // 1. integer array
    //
    // int a[5] { 100, 101, 102, 103, 104 };
    // For_Each(a, a + 5, &print_int);

    // 2. std::vector
    //
    // vector<int> v { 100, 101, 102, 103, 104 };
    // For_Each(&v[0], &v[0] + 5, &print_int);
    // For_Each(v.begin(), v.end(), &print_int);

    // 3. std::list
    //
    // list<int> v { 100, 101, 102, 103, 104 };
    // For_Each(v.begin(), v.end(), &print_int);

    // 4. Looping using iterator
    //
    // list<int> v { 100, 101, 102, 103, 104 };
    // for (list<int>::iterator i = v.begin(); i != v.end(); ++i) {
    //     *i += 200;
    //     cout << *i << ' ';
    // }

    // 5. Looping using const_iterator
    //
    // const list<int> v { 100, 101, 102, 103, 104 };
    // for (list<int>::const_iterator i = v.begin(); i != v.end(); ++i) {
    
    //     cout << *i << ' ';
    // }

    // 6. Using auto instead of iterator type
    //
    // const list<int> v { 100, 101, 102, 103, 104 };
    // for (auto i = v.begin(); i != v.end(); ++i) {
    //     cout << *i << ' ';
    // }

    // 7. Range-based for loop
    //
    const list<int> v { 100, 101, 102, 103, 104 };
    for (auto& x : v) {
        cout << x << ' ';
    }

    cout << '\n';
}
