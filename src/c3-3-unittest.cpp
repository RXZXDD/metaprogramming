#include<gtest/gtest.h>
#include<c3exsample.hpp>
#include <boost/type_traits/add_pointer.hpp>
#include <boost/mpl/placeholders.hpp>


TEST(c33, t1) {
    namespace mpl = boost::mpl;
    using namespace mpl::placeholders;

    // typedef xdd::twice<
    // xdd::twice<boost::add_pointer<_1>, _2>,
    // int>::type T;
    typedef xdd::twice<boost::add_pointer<_1>, int>::type T1;
    typedef xdd::twice<boost::add_pointer<_1>, T1>::type T2;
    

    static_assert(std::is_same_v<T2, int****> == 1);

    ;
    // typedef xdd::twice<xdd::twice<boost::add_pointer<_1>, int>, >::type T3;
     typedef xdd::twice<boost::add_pointer<_1>, xdd::twice<boost::add_pointer<_1>, int>::type>::type T3;
    

    static_assert(std::is_same_v<T3, int****> == 1);
}