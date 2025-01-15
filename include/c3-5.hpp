#include <boost/mpl/int.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/multiplies.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/type_traits/add_pointer.hpp>

namespace xdd35
{
    namespace mpl = boost::mpl;
    using namespace mpl::placeholders;

    typedef mpl::vector_c<int, 1, 0, 0, 0, 0, 0, 0> mass;
    typedef mpl::vector_c<int, 0, 1, 0, 0, 0, 0, 0> length;
    typedef mpl::vector_c<int, 0, 0, 1, 0, 0, 0, 0> time;
    typedef mpl::vector_c<int, 0, 0, 0, 1, 0, 0, 0> charge;
    typedef mpl::vector_c<int, 0, 0, 0, 0, 1, 0, 0> temperature;
    typedef mpl::vector_c<int, 0, 0, 0, 0, 0, 1, 0> intensity;
    typedef mpl::vector_c<int, 0, 0, 0, 0, 0, 0, 1> amount_of_substance;

    typedef mpl::vector_c<int, 0, 1, -1, 0, 0, 0, 0> velocity;
    typedef mpl::vector_c<int, 0, 1, -2, 0, 0, 0, 0> acceleration;
    typedef mpl::vector_c<int, 1, 1, -1, 0, 0, 0, 0> momentum;
    typedef mpl::vector_c<int, 1, 1, -2, 0, 0, 0, 0> force;

    typedef mpl::vector_c<int, 0, 0, 0, 0, 0, 0, 0> scalar;

    template <class T, class Diemnsions>
    struct quantity
    {
        explicit quantity(T x) : m_value(x) {}

        T value() const { return m_value; }

        template <class OtherDimensions>
        quantity(quantity<T, OtherDimensions> const &rhs)
            : m_value(rhs.value())
        {
            BOOST_STATIC_ASSERT((
                mpl::equal<Diemnsions, OtherDimensions>::type::value));
        }
        
    private:
        T m_value;
    };

    template <class T, class D>
        quantity<T, typename mpl::transform<D,
                                        mpl::plus<_1,_1>
                                        >::type>
        operator+(quantity<T, D> x, quantity<T, D> y)
        {
            return quantity<T, D>(x.value() + y.value());
        }


    template<class T, class D1, class D2>
    quantity<T, typename mpl::transform<D1, D2,
                                        mpl::multiplies<_1,_2>
                                        >::type
                                        >
    operator*(quantity<T,D1>x, quantity<T,D2>y){
        typedef mpl::transform<D1, D2,mpl::multiplies<_1,_2>>::type dim;
        return quantity<T,dim>(x.value()*y.value());

    }
}

