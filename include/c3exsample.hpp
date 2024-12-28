#include <boost/mpl/int.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/type_traits/add_pointer.hpp>

namespace xdd
{
    namespace mpl = boost::mpl;
    using namespace mpl::placeholders;

    typedef mpl::vector_c<int, 1, 0, 0, 0, 0, 0, 0> mass;
    typedef mpl::vector_c<int, 0, 1, 0, 0, 0, 0, 0> length;
    typedef mpl::vector_c<int, 0, 0,1,0,0,0,0> time;
    typedef mpl::vector_c<int, 0, 0,0,1,0,0,0> charge;
    typedef mpl::vector_c<int, 0, 0,0,0,1,0,0> temperature;
    typedef mpl::vector_c<int, 0, 0,0,0,0,1,0> intensity;
    typedef mpl::vector_c<int, 0, 0,0,0,0,0,1> amount_of_substance;
    
    typedef mpl::vector_c<int, 0, 1,-1,0,0,0,0> velocity;
    typedef mpl::vector_c<int, 0, 1,-2,0,0,0,0> acceleration;
    typedef mpl::vector_c<int, 1, 1,-1,0,0,0,0> momentum;
    typedef mpl::vector_c<int, 1, 1,-2,0,0,0,0> force;
    
    typedef mpl::vector_c<int, 0,0,0,0,0,0,0> scalar;




    template <class T, class Diemnsions>
    struct quantity
    {
        explicit quantity(T x) : m_value(x) {}

        T value() const { return m_value; }

        template<class OtherDimensions>
        quantity(quantity<T, OtherDimensions> const& rhs) 
        : m_value(rhs.value()){
            BOOST_STATIC_ASSERT((
                mpl::equal<Diemnsions,OtherDimensions>::type::value
            ));
        }

    private:
        T m_value;
    };

    quantity<float, mass> m(1.0f);
    quantity<float, length> l(1.0f);

    template <class T, class D>
    quantity<T, D> operator+(quantity<T, D> x, quantity<T, D> y)
    {
        return quantity<T, D>(x.value() + y.value());
    }

    template <class T, class D>
    quantity<T, D> operator-(quantity<T, D> x, quantity<T, D> y)
    {
        return quantity<T, D>(x.value() - y.value());
    }



    struct plus_f
    {
        template<class T1, class T2>
        struct apply
        {
            typedef typename mpl::plus<T1,T2>::type type;
        };
    };
    template<class T, class D1, class D2>
    quantity<T, typename mpl::transform<D1, D2, plus_f>::type>
    operator*(quantity<T, D1>x, quantity <T, D2>y) {
        typedef typename mpl::transform<D1, D2, plus_f>::type dim;
        return quantity<T,dim>(x.value() * y.value());
    };

    struct minus_f
    {
        template<class T1, class T2>
        struct apply
        : mpl::minus<T1,T2> {};
    };

    template<class D1, class D2>
    struct divide_dimensions
    : mpl::transform<D1,D2,mpl::minus<_1,_2>>::type
    {};

    template<class T, class D1, class D2>
    quantity<T, typename mpl::transform<D1, D2, mpl::minus<_1,_2>>::type>
    operator/(quantity<T, D1>x, quantity <T, D2>y) {
       // typedef typename mpl::transform<D1, D2, mpl::minus<_1,_2>>::type dim;
        return quantity<T,typename divide_dimensions<D1,D2>::type>(x.value() / y.value());
    };

    void test()
    {
        // m = l;
        quantity<float, mass> m(5.0f);
        quantity<float, acceleration> a(9.8f);

        quantity<float,force> f = m*a;
       // quantity<float,length> f1 = m*a;

       quantity<float,mass> m2 = f/a;
       float rounding_error = std::abs((m2-m).value());

        BOOST_STATIC_ASSERT((
            mpl::plus<
                mpl::int_<2>, mpl::int_<3>>::type::value == 5));
    }



    //////////////////////3.2

    // template <class F, class X>
    // struct twice
    // {
    //     typedef typename F::template apply<X>::type once; //f(x)
    //     typedef typename F::template apply<once>::type type //f(f(x))
    // };
    

    // template <class F, class X>
    // struct twice : F::template apply<
    //                     typename F::template apply<X>::type>
    // {
    // };

    template <class UnaryMetaFunctionClass, class Arg>
    struct apply1 
    : UnaryMetaFunctionClass::template apply<Arg>
    {};

    // template <class F, class X>
    // struct twice 
    // : apply1<F,
    //         typename apply1<F,X>::type 
    //         >
    // {    };


    template <class F, class X>
    struct twice 
    : apply1<typename mpl::lambda<F>::type,
            typename apply1<
                typename mpl::lambda<F>::type
            ,X>::type 
            >
    {    };
    struct add_pointer_f
    {
        template <class T>
        struct apply: boost::add_pointer<T>{};
    };

    void test2()
    {
        BOOST_STATIC_ASSERT((
            boost::is_same<
                twice<add_pointer_f,int>::type
                , int**
            >::value
        ));
    };
////////////////////////////////3.3

template <class X>
struct two_pointers
: twice<typename mpl::lambda<boost::add_pointer<_1>>::type,X>
{};


    void test3 ()
    {
        BOOST_STATIC_ASSERT((
            boost::is_same<
                two_pointers<int>::type
                , int**
            >::value
        ));

        BOOST_STATIC_ASSERT((
        boost::is_same<
                twice<add_pointer_f, int>::type
                , int**
            >::value
        ));

        
        BOOST_STATIC_ASSERT((
        boost::is_same<
                twice<boost::add_pointer<_1>, int>::type
                , int**
            >::value
        ));
    };

#include <boost/mpl/apply.hpp>

    template <class F, class X>
    struct twice2
    : mpl::apply<F,
            typename mpl::apply<F,X>::type >
    {    };

}