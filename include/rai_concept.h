#pragma once

#include <boost/concept_check.hpp>

// stl containers: https://en.cppreference.com/w/cpp/container
// RandomAccessIterator: https://en.cppreference.com/w/cpp/named_req/RandomAccessIterator
// BCCL Docs: https://www.boost.org/doc/libs/1_60_0/libs/concept_check/creating_concepts.htm

namespace rai_concept {
    template <typename T>
    struct RandomAccessIteratorCheck {
        using IT = T;
        BOOST_CONCEPT_USAGE(RandomAccessIteratorCheck) {
            int n = 10;
            r += n;
        }
    private:
        IT r;
    };
}
