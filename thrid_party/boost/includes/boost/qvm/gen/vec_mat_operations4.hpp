#ifndef BOOST_QVM_GEN_VEC_MAT_OPERATIONS4_HPP_INCLUDED
#define BOOST_QVM_GEN_VEC_MAT_OPERATIONS4_HPP_INCLUDED

// Copyright 2008-2024 Emil Dotchevski and Reverge Studios, Inc.
// This file was generated by a program. Do not edit manually.
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/qvm/config.hpp>
#include <boost/qvm/deduce_vec.hpp>
#include <boost/qvm/enable_if.hpp>
#include <boost/qvm/mat_traits.hpp>
#include <boost/qvm/vec_traits.hpp>

namespace boost { namespace qvm {

template <class A,class B>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_OPERATIONS
typename lazy_enable_if_c<
    mat_traits<A>::rows==4 && mat_traits<A>::cols==4 &&
    vec_traits<B>::dim==4,
    deduce_vec2<A,B,4> >::type
operator*( A const & a, B const & b )
    {
    typedef typename mat_traits<A>::scalar_type Ta;
    typedef typename vec_traits<B>::scalar_type Tb;
    Ta const a00 = mat_traits<A>::template read_element<0,0>(a);
    Ta const a01 = mat_traits<A>::template read_element<0,1>(a);
    Ta const a02 = mat_traits<A>::template read_element<0,2>(a);
    Ta const a03 = mat_traits<A>::template read_element<0,3>(a);
    Ta const a10 = mat_traits<A>::template read_element<1,0>(a);
    Ta const a11 = mat_traits<A>::template read_element<1,1>(a);
    Ta const a12 = mat_traits<A>::template read_element<1,2>(a);
    Ta const a13 = mat_traits<A>::template read_element<1,3>(a);
    Ta const a20 = mat_traits<A>::template read_element<2,0>(a);
    Ta const a21 = mat_traits<A>::template read_element<2,1>(a);
    Ta const a22 = mat_traits<A>::template read_element<2,2>(a);
    Ta const a23 = mat_traits<A>::template read_element<2,3>(a);
    Ta const a30 = mat_traits<A>::template read_element<3,0>(a);
    Ta const a31 = mat_traits<A>::template read_element<3,1>(a);
    Ta const a32 = mat_traits<A>::template read_element<3,2>(a);
    Ta const a33 = mat_traits<A>::template read_element<3,3>(a);
    Tb const b0 = vec_traits<B>::template read_element<0>(b);
    Tb const b1 = vec_traits<B>::template read_element<1>(b);
    Tb const b2 = vec_traits<B>::template read_element<2>(b);
    Tb const b3 = vec_traits<B>::template read_element<3>(b);
    typedef typename deduce_vec2<A,B,4>::type R;
    BOOST_QVM_STATIC_ASSERT(vec_traits<R>::dim==4);
    R r;
    write_vec_element<0>(r,a00*b0+a01*b1+a02*b2+a03*b3);
    write_vec_element<1>(r,a10*b0+a11*b1+a12*b2+a13*b3);
    write_vec_element<2>(r,a20*b0+a21*b1+a22*b2+a23*b3);
    write_vec_element<3>(r,a30*b0+a31*b1+a32*b2+a33*b3);
    return r;
    }

namespace
sfinae
    {
    using ::boost::qvm::operator*;
    }

namespace
qvm_detail
    {
    template <int R,int C>
    struct mul_mv_defined;

    template <>
    struct
    mul_mv_defined<4,4>
        {
        static bool const value=true;
        };
    }

template <class A,class B>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_OPERATIONS
typename lazy_enable_if_c<
    mat_traits<B>::rows==4 && mat_traits<B>::cols==4 &&
    vec_traits<A>::dim==4,
    deduce_vec2<A,B,4> >::type
operator*( A const & a, B const & b )
    {
    typedef typename vec_traits<A>::scalar_type Ta;
    typedef typename mat_traits<B>::scalar_type Tb;
    Ta const a0 = vec_traits<A>::template read_element<0>(a);
    Ta const a1 = vec_traits<A>::template read_element<1>(a);
    Ta const a2 = vec_traits<A>::template read_element<2>(a);
    Ta const a3 = vec_traits<A>::template read_element<3>(a);
    Tb const b00 = mat_traits<B>::template read_element<0,0>(b);
    Tb const b01 = mat_traits<B>::template read_element<0,1>(b);
    Tb const b02 = mat_traits<B>::template read_element<0,2>(b);
    Tb const b03 = mat_traits<B>::template read_element<0,3>(b);
    Tb const b10 = mat_traits<B>::template read_element<1,0>(b);
    Tb const b11 = mat_traits<B>::template read_element<1,1>(b);
    Tb const b12 = mat_traits<B>::template read_element<1,2>(b);
    Tb const b13 = mat_traits<B>::template read_element<1,3>(b);
    Tb const b20 = mat_traits<B>::template read_element<2,0>(b);
    Tb const b21 = mat_traits<B>::template read_element<2,1>(b);
    Tb const b22 = mat_traits<B>::template read_element<2,2>(b);
    Tb const b23 = mat_traits<B>::template read_element<2,3>(b);
    Tb const b30 = mat_traits<B>::template read_element<3,0>(b);
    Tb const b31 = mat_traits<B>::template read_element<3,1>(b);
    Tb const b32 = mat_traits<B>::template read_element<3,2>(b);
    Tb const b33 = mat_traits<B>::template read_element<3,3>(b);
    typedef typename deduce_vec2<A,B,4>::type R;
    BOOST_QVM_STATIC_ASSERT(vec_traits<R>::dim==4);
    R r;
    write_vec_element<0>(r,a0*b00+a1*b10+a2*b20+a3*b30);
    write_vec_element<1>(r,a0*b01+a1*b11+a2*b21+a3*b31);
    write_vec_element<2>(r,a0*b02+a1*b12+a2*b22+a3*b32);
    write_vec_element<3>(r,a0*b03+a1*b13+a2*b23+a3*b33);
    return r;
    }

namespace
sfinae
    {
    using ::boost::qvm::operator*;
    }

namespace
qvm_detail
    {
    template <int R,int C>
    struct mul_vm_defined;

    template <>
    struct
    mul_vm_defined<4,4>
        {
        static bool const value=true;
        };
    }

} }

#endif
