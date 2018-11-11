#include <boost/concept_check.hpp>
#include "rai_concept.h"

#include <vector>
#include <unordered_map>

int main() {
    // vector: random access iterator
    BOOST_CONCEPT_ASSERT((rai_concept::RandomAccessIteratorCheck<std::vector<int>::iterator>));

    // unordered_map: only forward iterator, not compiles
//    BOOST_CONCEPT_ASSERT((rai_concept::RandomAccessIteratorCheck<std::unordered_map<int, int>::iterator>));
    return 0;
}
