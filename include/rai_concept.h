#pragma once

#include <boost/concept_check.hpp>

// stl containers: https://en.cppreference.com/w/cpp/container
// RandomAccessIterator: https://en.cppreference.com/w/cpp/named_req/RandomAccessIterator
// BCCL Docs: https://www.boost.org/doc/libs/1_60_0/libs/concept_check/creating_concepts.htm

// RandomAccessIterator <- BidirectionalIterator
// BidirectionalIterator <- ForwardIterator
// ForwardIterator <- InputIterator, DefaultConstructible
// InputIterator <- Iterator, EqualityComparable
// DefaultConstructible
// EqualityComparable

namespace rai_concept {
    // https://en.cppreference.com/w/cpp/named_req/EqualityComparable
    template<typename T>
    struct EqualityComparableCheck {
        BOOST_CONCEPT_USAGE(EqualityComparableCheck) {
            bool c = (a == b);
        }
    private:
        T a, b;
    };

    // https://en.cppreference.com/w/cpp/named_req/DefaultConstructible
    template<typename T>
    struct DefaultConstructibleCheck {

    };

    // https://en.cppreference.com/w/cpp/named_req/InputIterator
    template<typename T>
    struct InputIteratorCheck : EqualityComparableCheck<T> {

    };

    // https://en.cppreference.com/w/cpp/named_req/ForwardIterator
    template<typename T>
    struct ForwardIteratorCheck : InputIteratorCheck<T>, DefaultConstructibleCheck<T> {

    };

    // https://en.cppreference.com/w/cpp/named_req/BidirectionalIterator
    template<typename T>
    struct BidirectionalIteratorCheck : ForwardIteratorCheck<T> {

    };

    // https://en.cppreference.com/w/cpp/named_req/RandomAccessIterator
    template<typename T>
    struct RandomAccessIteratorCheck : BidirectionalIteratorCheck<T> {
        using IT = T;
        BOOST_CONCEPT_USAGE(RandomAccessIteratorCheck) {
            int n = 10;
            r += n;
        }

    private:
        IT r;
    };
}
