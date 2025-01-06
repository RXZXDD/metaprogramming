#include <boost/static_assert.hpp>

template<unsigned long N>
struct binary
{
    
    static constexpr unsigned check() {
        //1 1%10 = 1
        //0 0%10 = 0
        //5 5%10 = 5
            BOOST_STATIC_ASSERT((
                    N%10 == 0 || N%10 == 1
            ));
            return binary<N/10>::value * 2 + N%10;
        }

    static unsigned const value = check();
};

template<>
struct binary<0> {
    static unsigned const value = 0;
};
