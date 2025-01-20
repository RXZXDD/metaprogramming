#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/plus.hpp>


    namespace mpl = boost::mpl;
    using namespace mpl::placeholders;

    typedef mpl::lambda<mpl::lambda<_1>>::type t1;
    
    // template<class T>
    // struct Test : mpl::lambda<mpl::lambda<_1>>::type
    // {};
    typedef mpl::apply<_1, int>::type t2;

    static_assert(std::is_same_v<int, t2> == true);

    typedef mpl::apply<_1, mpl::plus<_1,_2>>::type t3;

    template<class T, class X>
    struct sa : 
    {};
    // typedef mpl::apply<
    //                         mpl::lambda<_1>,
    //                         typename t3
    //                         >::type tt3;



   //static_assert(std::is_same_v<mpl::apply<t3, int,int>::type, int> == true);

  


