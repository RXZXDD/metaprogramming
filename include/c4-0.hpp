#include <boost/mpl/or.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/type_traits/is_scalar.hpp>
#include <boost/type_traits/is_class.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/add_const.hpp>

using namespace boost;

class c40{};

template<typename T>
struct ParamTypeOr : mpl::eval_if<
                            mpl::or_<is_scalar<T>, is_same<T,::c40>>,
                            mpl::identity<T>,
                            add_const<T>
                                >
{};

template<typename T>
struct ParamTypeAnd : mpl::eval_if<
                            mpl::and_<is_scalar<T>,is_same<T,int>>,
                            add_const<T>,
                            mpl::identity<T>
                                >
{};