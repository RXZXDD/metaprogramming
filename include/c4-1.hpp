
#include <boost/mpl/identity.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/type_traits/is_scalar.hpp>
#include <boost/type_traits/is_class.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/add_const.hpp>

using namespace boost;

class c40{};

template<bool x>
struct bool_{
    static bool const value = x;
    typedef bool_<x>  type;
    typedef bool value_type;
    operator bool() const {return x;}
};

typedef bool_<true> Ltrue; 
typedef bool_<false> Lfalse; 
//----------------------------

template<bool C_, typename t1>
struct Logical_or_imp : Ltrue
{};

// template<typename t1, typename t2>
// struct Logical_or_imp : Logical_or_imp <false, t2>
// {};

template<>
struct Logical_or_imp<false, Lfalse> : Lfalse
{};


template <typename t1,typename t2>
struct Logical_or :Logical_or_imp<t1::value,t2>
{};
//--------------------------------------
template<bool C_, typename t1>
struct Logical_and_imp: Lfalse
{};


// template<typename t1, typename t2>
// struct Logical_and_imp : Logical_and_imp<true, t2>
// {};

template<>
struct Logical_and_imp<true,Ltrue> : Ltrue
{};

template<typename t1, typename t2>
struct Logical_and: Logical_and_imp<t1::value, t2>
{};

//------------------------------

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