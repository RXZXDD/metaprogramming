#include<gtest/gtest.h>
#include<c3-1.hpp>
#include <boost/mpl/plus.hpp>
#include<type_traits>


TEST(c31, t1) {
    namespace mpl = boost::mpl;
    using namespace mpl::placeholders;

    typedef mpl::vector_c<int ,2,3,4> seq2;

    typedef mpl::transform<mpl::vector_c<int,1,2,3>, mpl::vector_c<int,1,1,1>, mpl::plus<_1,_2>>::type seq1;
    static_assert(seq1::item0::value==seq2::item0::value);

    typedef mpl::vector_c<int ,1,4,9> seq4;

    typedef mpl::transform<mpl::vector_c<int,1,2,3>, mpl::vector_c<int,0,2,6>, mpl::plus<_1,_2>>::type seq3;
    static_assert(seq4::item0::value==seq3::item0::value);


}