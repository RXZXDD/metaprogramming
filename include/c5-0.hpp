#include <boost/mpl/iterator_tags.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/distance.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/preprocessor/repetition.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>

using namespace boost;

struct tiny_tag {};
struct none{};

template<class T0 = none, class T1 = none, class T2 = none>
struct Tiny{
    typedef tiny_tag tag;
    typedef Tiny type;
    typedef T0 t0;
    typedef T1 t1;
    typedef T2 t2;

};

template<class Tiny, typename Pos>
struct Tiny_iterator{
    typedef mpl::random_access_iterator_tag category;
};

template<class Tiny, int N>
struct tiny_at;

template<class Tiny>
struct tiny_at<Tiny, 0>{
    typedef typename Tiny::t0 type;
};

template<class Tiny>
struct tiny_at<Tiny, 1>{
    typedef typename Tiny::t1 type;
};


template<class Tiny>
struct tiny_at<Tiny, 2>{
    typedef typename Tiny::t2 type;
};

template <class T0, class T1, class T2>
struct tiny_size : mpl::int_<3> {};

template <class T0, class T1>
struct tiny_size <T0,T1,none> : mpl::int_<2> {};

template <class T0>
struct tiny_size <T0,none,none> : mpl::int_<1> {};

// #define TINTY_print (z,n,data) __data_entrypoint
// #define TINY_size(z,n,unused)\
//     template <BOOST_PP_ENUM_PARAMS(n, class T)>\
//     struct tiny_size<\
//         BOOST_PP_ENUM_PARAMS(n,T)\
//         BOOST_PP_COMMA_IF(n)\
//         BOOST_PP_ENUM(\
//                 BOOST_PP_SUB(TINY_MAX_SIZE,n), TINTY_print, none)\
//     >\
//         : mpl::int_<n>{};

// BOOST_PP_REPEAT(TINY_MAX_SIZE,TINY_size, ~)

// #undef TINY_size
// #undef TINY_print



namespace boost{ namespace mpl{

    template<class Tiny, class Pos>
    struct next<Tiny_iterator<Tiny, Pos>>{
        typedef Tiny_iterator<Tiny, typename mpl::next<Pos>::type> type;
    };

    template<class Tiny, class Pos>
    struct prior<Tiny_iterator<Tiny,Pos>>{
        typedef Tiny_iterator<Tiny, typename mpl::prior<Pos>::type> type;
    };



    template<>
    struct at_impl<tiny_tag>{
        template<class Tiny, class N>
        struct apply: tiny_at<Tiny,N::value>{};
    };


    template <class Tiny, class Pos>
    struct deref<Tiny_iterator<Tiny, Pos>>: at<Tiny, Pos>{};

    template<class Tiny, class Pos, class N>
    struct advance<Tiny_iterator<Tiny, Pos>, N>
    {
        typedef Tiny_iterator<Tiny, typename mpl::plus<Pos,N>::type> type;
    };

    template<class Tiny, class Pos1, class Pos2>
    struct distance<
    Tiny_iterator<Tiny,Pos1>
    ,Tiny_iterator<Tiny, Pos2>> : mpl::minus<Pos2,Pos1>
    {};

    template<>
    struct begin_impl<tiny_tag>{
        template<class Tiny>
        struct apply{
            typedef Tiny_iterator<Tiny, mpl::int_<0>> type;
        };
    };


    template<>
    struct end_impl<tiny_tag>{
        template<class Tiny>
        struct apply{
            typedef Tiny_iterator<
                Tiny,
                typename tiny_size<typename Tiny::t0
                    ,typename Tiny::t1
                    ,typename Tiny::t2>::type
            > type;
        };
    };
}}