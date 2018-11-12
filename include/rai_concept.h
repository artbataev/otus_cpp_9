#pragma once

#include <boost/concept_check.hpp>
#include <iterator>

// stl containers: https://en.cppreference.com/w/cpp/container
// RandomAccessIterator: https://en.cppreference.com/w/cpp/named_req/RandomAccessIterator
// BCCL Docs: https://www.boost.org/doc/libs/1_60_0/libs/concept_check/creating_concepts.htm

// RandomAccessIterator <- BidirectionalIterator
// BidirectionalIterator <- ForwardIterator
// ForwardIterator <- InputIterator, DefaultConstructible
// InputIterator <- Iterator, EqualityComparable
// DefaultConstructible
// EqualityComparable

namespace {
    template<typename T>
    void suppress_warning(T value) {}
}


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
        BOOST_CONCEPT_USAGE(DefaultConstructibleCheck) {
            T u;
            T u1{};
            T();
            suppress_warning(T{});
        }
    };

    // https://en.cppreference.com/w/cpp/named_req/InputIterator
    template<typename T>
    struct InputIteratorCheck : EqualityComparableCheck<T> {
        BOOST_CONCEPT_USAGE(InputIteratorCheck) {
            bool t = (i != j);
            *i;
            ++i;
            (void) i++;
            *i++;
        }

    private:
        T i, j;
    };

    // https://en.cppreference.com/w/cpp/named_req/ForwardIterator
    template<typename T>
    struct ForwardIteratorCheck : InputIteratorCheck<T>, DefaultConstructibleCheck<T> {
        BOOST_CONCEPT_USAGE(ForwardIteratorCheck) {
            i++;
            *i++;
        }

    private:
        T i;
    };

    // https://en.cppreference.com/w/cpp/named_req/BidirectionalIterator
    template<typename T>
    struct BidirectionalIteratorCheck : ForwardIteratorCheck<T> {
        BOOST_CONCEPT_USAGE(BidirectionalIteratorCheck) {
            --a;
            a--;
            *a--;
        }

    private:
        T a;
    };

    // https://en.cppreference.com/w/cpp/named_req/RandomAccessIterator
    template<typename T>
    struct RandomAccessIteratorCheck : BidirectionalIteratorCheck<T> {
        BOOST_CONCEPT_USAGE(RandomAccessIteratorCheck) {
            r += n;
            a + n;
            n + a;
            r -= n;
            i - n;
            b - a;
            i[n];
            bool _ = (a < b);
            _ = (a > b);
            _ = (a >= b);
            _ = (a <= b);
        }

    private:
        T r;
        T i, a, b;
        typename std::iterator_traits<T>::difference_type n;
    };
}
