#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

template <typename Container>
struct IteratorThatPushes {
    Container& c;

    explicit IteratorThatPushes(Container& c) : c(c) {}
    IteratorThatPushes& operator*()     { return *this; }
    IteratorThatPushes& operator++()    { return *this; }
    IteratorThatPushes  operator++(int) { return *this; }

    IteratorThatPushes& operator=(const typename Container::value_type& x) {
        c.push_back(x);
        return *this;
    }
};

void print_int(int x)  { cout << x << ' '; }

int main() {
    // 1. std::copy() revisited
    //
    vector<int> v1 { 100, 101, 102, 103, 104 };
    vector<int> v2;

    copy(v1.begin(), v1.end(), v2.begin());

    for_each(v2.begin(), v2.end(), &print_int);

    // 2. vector initializers
    //
    // vector<int> v1 { 100, 101, 102, 103, 104 };
    // vector<int> v2(5);
    //
    // copy(v1.begin(), v1.end(), v2.begin());
    //
    // for_each(v2.begin(), v2.end(), &print_int);

    // 3. IteratorThatPushes
    //
    // vector<int> v1 { 100, 101, 102, 103, 104 };
    // vector<int> v2;
    //
    // copy(v1.begin(), v1.end(), IteratorThatPushes<vector<int>>{v2});
    //
    // Or use std::back_insert_iterator:
    // copy(v1.begin(), v1.end(), back_inserter(v2));
    //
    // for_each(v2.begin(), v2.end(), &print_int);

    // 4. ostream_iterator
    //
    // vector<int> v { 100, 101, 102, 103, 104 };
    //
    // ostream_iterator<int> oi {cout, "\n"};
    // copy(v.begin(), v.end(), oi);

    // 5. istream_iterator
    //
    // vector<int> v;
    // istream_iterator<int> iib {cin};
    // istream_iterator<int> iie {};
    //
    // copy(iib, iie, back_inserter(v));
    //
    // ostream_iterator<int> oi {cout, ","};
    // copy(v.begin(), v.end(), oi);

    cout << '\n';
}
