#include <boost/mpl/transform.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/placeholders.hpp>



namespace xdd{
    namespace mpl =  boost::mpl;
    using namespace mpl::placeholders;
    typedef  mpl::vector_c<int, 1,2,3> t1;
    typedef  mpl::vector_c<int, 1,1,1> t2;

    template<typename DataType, class Type>
    struct scalor
    {
        using T = DataType;

        explicit scalor(T x) : _value(x){};

        T value() const {return _value;}

        template<typename OtherType>
        scalor(scalor<T, OtherType> const& rhs) : _value(rhs.value())
        {
            BOOST_STATIC_ASSERT((
                mpl::equal<OtherType, T>::type::value
            ));
        }

        private:
        T _value;
    };

    //scalor<int, t1> a(2);

    // template<typename DataType, typename T1, typename T2>
    // scalor<DataType, typename mpl::transform<T1,T2,mpl::plus<_1,_2>>::type>
    // turnTo(scalor<DataType, T1> x, scalor<DataType,T2> y )
    // {
    //     return
    // }

}