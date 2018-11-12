#include <boost/concept_check.hpp>
#include "rai_concept.h"

#include <vector>
#include <unordered_map>

template <typename T>
class DemoIteratorWithDeletedMethods: public std::vector<T>::iterator {
public:
//    template <typename U> bool operator==(U rhs) = delete; // EqualityComparableCheck will fail

//    DemoIteratorWithDeletedMethods() = delete; // DefaultConstructibleCheck will fail

//    T operator*() = delete; // InputIteratorCheck will fail

//    DemoIteratorWithDeletedMethods operator--() = delete; // BidirectionalIteratorCheck will fail

//    template <typename U> DemoIteratorWithDeletedMethods operator-=(U rhs) = delete; // RandomAccessIteratorCheck will fail
};

int main() {
    // vector: random access iterator
    BOOST_CONCEPT_ASSERT((rai_concept::RandomAccessIteratorCheck<std::vector<int>::iterator>));

    // unordered_map: only forward iterator, not compiles
//    BOOST_CONCEPT_ASSERT((rai_concept::RandomAccessIteratorCheck<std::unordered_map<int, int>::iterator>));

    BOOST_CONCEPT_ASSERT((rai_concept::RandomAccessIteratorCheck<DemoIteratorWithDeletedMethods<int>>));
    return 0;
}
