
#include <boost/mpl/identity.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/type_traits/is_scalar.hpp>
#include <boost/type_traits/is_class.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/add_const.hpp>
#include <boost/mpl/bool.hpp>


using namespace boost;

class c40{};

template<typename a, typename b>
struct Logical_and{
    static constexpr bool value = a::value && b::value;
};

template<typename a, typename b>
struct Logical_or{
    static constexpr bool value = a::value || b::value;
};

template<typename T>
struct ParamTypeOr : mpl::eval_if<
                            ::Logical_or<is_scalar<T>, is_same<T,::c40>>,
                            mpl::identity<T>,
                            add_const<T>
                                >
{};

template<typename T>
struct ParamTypeAnd : mpl::eval_if<
                    ::Logical_and<is_scalar<T>,is_same<T,int>>,
                            add_const<T>,
                            mpl::identity<T>
                                >
{};