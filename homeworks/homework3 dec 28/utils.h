//
// Created by Vahe Aleksanyan on 25.01.23.
//

#ifndef HOMEWORK3_DEC_28_UTILS_H
#define HOMEWORK3_DEC_28_UTILS_H

#include <cstddef>

namespace Euclid
{
    template<size_t M, size_t N>
    struct gcd_impl
    {
        static constexpr size_t R = (N==0) ? 0 : (M % N);  // constexpr means evaluate the value of the function or variable at compile time.
        static constexpr size_t result = (R==0) ? N : gcd_impl<N, R>::result; // size_t unsigned integer type returned by the sizeof operator
    };

    template<size_t  M>
    struct gcd_impl<M ,0>
    {
        static  constexpr size_t result = M;
    };

    template<size_t N>
    struct gcd_impl<0, N>
    {
        static constexpr size_t result = 0;
    };

    template<>
    struct gcd_impl<0, 0>
    {
        static constexpr size_t result = 0;
    };

    template<size_t M, size_t N>
    struct gcd
    {
        static constexpr size_t value1 = (M > N) ? M :N;
        static constexpr size_t value2 = (M == value1) ? N :M;
        static constexpr size_t result = gcd_impl<value1, value2>::result;
    };
}


#endif //HOMEWORK3_DEC_28_UTILS_H


