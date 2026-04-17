#include <vector>
#include <forward_list>
#include <list>
#include <iostream>
#include <iterator>
using namespace std;

namespace c2cpp_simple {

    template <typename I>
    size_t MyDistance(I b, I e) {
        return e - b;
    }
}

namespace c2cpp_tag_dispatch {

    template <typename I>
    size_t __doMyDistance(I b, I e, random_access_iterator_tag) {
        return e - b;
    }

    template <typename I>
    size_t __doMyDistance(I b, I e, forward_iterator_tag) {
        size_t n = 0;
        while (b != e) {
            ++n;
            ++b;
        }
        return n;
    }

    template <typename I>
    size_t MyDistance(I b, I e) {
        // return __doMyDistance(b, e, typename I::iterator_category{});

        return __doMyDistance(b, e,
                     typename iterator_traits<I>::iterator_category{});
    }
}

namespace c2cpp_sfinae {

    template <typename I>
    std::enable_if<is_same_v<random_access_iterator_tag,
          typename iterator_traits<I>::iterator_category>, size_t>::type
    MyDistance(I b, I e) {
        return e - b;
    }

    template <typename I>
    std::enable_if<is_same_v<forward_iterator_tag,
          typename iterator_traits<I>::iterator_category>, size_t>::type
    MyDistance(I b, I e) {
        size_t n = 0;
        while (b != e) {
            ++n;
            ++b;
        }
        return n;
    }
}

namespace c2cpp_constexpr {

    template <typename I>
    size_t MyDistance(I b, I e) {
        if constexpr (is_base_of_v<random_access_iterator_tag,
                          typename iterator_traits<I>::iterator_category>) {
            return e - b;
        } else {
            size_t n = 0;
            while (b != e) {
                ++n;
                ++b;
            }
            return n;
        } 
    }
}

namespace c2cpp_concept {

    // template <forward_iterator I>
    template <typename I>
        requires forward_iterator<I>
    size_t MyDistance(I b, I e) {
        if constexpr (is_base_of_v<random_access_iterator_tag,
                          typename iterator_traits<I>::iterator_category>) {
            return e - b;
        } else {
            size_t n = 0;
            while (b != e) {
                ++n;
                ++b;
            }
            return n;
        } 
    }

    template <typename I>
    concept MyBidirectionalIterator =
        forward_iterator<I> &&
        derived_from<typename iterator_traits<I>::iterator_category,
                              bidirectional_iterator_tag> &&
        requires (I i) {
            { --i } -> std::same_as<I&>;
            { i-- } -> std::same_as<I>;
        };
}

int main() {
    // 1. Simply assuming random access iterator
    //
    // using namespace c2cpp_simple;
    // vector v { 100, 101, 102, 103, 104 };
    // forward_list v { 100, 101, 102, 103, 104 };
    // int v[5] { 100, 101, 102, 103, 104 };

    // 2. Tag dispatching
    //
    // using namespace c2cpp_tag_dispatch;
    // vector v { 100, 101, 102, 103, 104 };
    // forward_list v { 100, 101, 102, 103, 104 };
    // int v[5] { 100, 101, 102, 103, 104 };

    // 3. SFINAE
    //
    // using namespace c2cpp_sfinae;
    //vector v { 100, 101, 102, 103, 104 };
    //forward_list v { 100, 101, 102, 103, 104 };
    //int v[5] { 100, 101, 102, 103, 104 };
    //list v { 100, 101, 102, 103, 104 };

    // 4. if constexpr
    //
    // using namespace c2cpp_constexpr;
    // vector v { 100, 101, 102, 103, 104 };
    // forward_list v { 100, 101, 102, 103, 104 };
    // int v[5] { 100, 101, 102, 103, 104 };
    // cout << MyDistance("AAA"s, "BBB"s) << '\n';

    // 5. Using concepts to constrain type parameters
    //
    using namespace c2cpp_concept;
    // vector v { 100, 101, 102, 103, 104 };
    // forward_list v { 100, 101, 102, 103, 104 };
    //int v[5] { 100, 101, 102, 103, 104 };
    //cout << MyDistance("AAA"s, "BBB"s) << '\n';

    // auto b = ranges::begin(v);
    // auto e = ranges::end(v);
    // cout << "Number of elements: " << MyDistance(b, e) << '\n';

    // 6. Using concepts to constrain auto
    //
    // random_access_iterator auto b = ranges::begin(v);
    // random_access_iterator auto e = ranges::end(v);
    // cout << "Number of elements: " << MyDistance(b, e) << '\n';

    // 7. Defining a concept
    list v { 100, 101, 102, 103, 104 };
    MyBidirectionalIterator auto b = ranges::begin(v);
    MyBidirectionalIterator auto e = ranges::end(v);
    cout << "Number of elements: " << MyDistance(b, e) << '\n';
}
