#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/type_traits/add_pointer.hpp>

namespace mpl = boost::mpl;
using namespace mpl::placeholders;

template <class F, class X>
struct lambda_twice : mpl::apply<
                            F,
                            typename mpl::apply<F, X>::type
                        >
{};

typedef lambda_twice<boost::add_pointer<_1>, int>::type T1;

static_assert(std::is_same_v<T1, int**> ==1);