#include <boost/mpl/size.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/iterator_tags.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/insert.hpp>

struct demension_tag{};

using namespace boost;

template<class T>
struct demension
{
    typedef T type;
    typedef demension_tag tag;
};

template<class T, class Pos>
struct demension_iterator{
    using category = mpl::bidirectional_iterator_tag;
};


template<class T>
struct myrank : mpl::int_<0>{};

// template<class T>
// struct myrank<T[]> :  mpl::int_<myrank<T>::value + 1>{

// };

template<class T,int N>
struct myrank<T[N]> : mpl::int_<myrank<T>::value + 1>{

};


template<class T>
struct Myrank : myrank<T>{};



template<class T>
struct demension_size;

template<class T>
struct demension_size<demension<T>> : Myrank<T>{};//std::rank<T>{};

template<class seq, int Pos, class T>
struct demension_insert;






namespace boost { namespace mpl{

    template<class T, int N>
struct demension_at;

template<class T, int D0>
struct demension_at<demension<T[D0]>,0> : mpl::int_<D0>{};


template<class T, int D0, int D1>
struct demension_at<demension<T[D0][D1]>,0> : mpl::int_<D1>{};

template<class T, int D0, int D1>
struct demension_at<demension<T[D0][D1]>,1> : mpl::int_<D0>{};

template<class T, int D0, int D1, int D2>
struct demension_at<demension<T[D0][D1][D2]>,0> : mpl::int_<D2>{};

template<class T, int D0, int D1, int D2>
struct demension_at<demension<T[D0][D1][D2]>,1> : mpl::int_<D1>{};

template<class T, int D0, int D1, int D2>
struct demension_at<demension<T[D0][D1][D2]>,2> : mpl::int_<D0>{
    using AT = T;
};

// template<class seq, class T>
// struct demension_push_back;


    template<>
    struct size_impl<demension_tag>
    {
        template<class demension>
        struct apply :  demension_size<demension>{};

    };

    template<>
    struct at_impl<demension_tag>
    {
        template<class demension, class N>
        struct apply: demension_at<demension, N::value>{};
    };

    // template<>
    // struct push_back_impl<demension_tag>{
    //     template<class seq, class T>
    //     struct apply: demension_push_back<seq, T>{};
    // };

    template<>
    struct insert_impl<demension_tag>{
        template<class seq, class Pos, class T>
        struct apply: demension_insert<seq, Pos::value, T>{};
    };

    template<>
    struct begin_impl<demension_tag>{
        template<class seq>
        struct apply{
            using type = demension_iterator<seq, int_<0>>;
        };
    };

    template<>
    struct end_impl<demension_tag>{
        template<class seq>
        struct apply{
            using type = demension_iterator<seq,
                                         typename mpl::int_<
                                         mpl::size<seq>::value-1
                                         >
                                         >;
        };
    };


    template<class seq, class Pos>
    struct deref<demension_iterator<seq, Pos>> : demension_at<seq, Pos::value>{    };
}}