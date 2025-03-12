#include <type_traits>

template<bool a, bool... Args>
struct Logical_or
{
    static constexpr bool value = a || Logical_or_imp<Args...>::value;
};

template<bool a, bool... Args>
struct Logical_or_imp
{
    static constexpr bool value = a || Logical_or_imp<Args...>::value;
};

template<>
struct Logical_or_imp<false>
{
    static constexpr bool value = false;
};

template<>
struct Logical_or_imp<true>
{
    static constexpr bool value = true;
};

//---------------------------------------------


// template<bool a, bool... Args>
// struct Logical_and
// {
//     static constexpr bool value = a && Logical_and_imp<Args...>::value;
// };

// template<bool a, bool... Args>
// struct Logical_and_imp
// {
//     static constexpr bool value = a && Logical_and_imp<Args...>::value;
// };

// template<>
// struct Logical_and_imp<false>
// {
//     static constexpr bool value = false;
// };

// template<>
// struct Logical_and_imp<true>
// {
//     static constexpr bool value = true;
// };

//---------------------------------------------

struct Ttrue{
    static constexpr bool value = true;
};

struct Tfalse{
    static constexpr bool value = false;
};

template<bool a, bool... Args>
struct Logical_and : std::conditional_t<a, Logical_and<Args...>, Tfalse>
{
};

template <>
struct Logical_and<true>: Ttrue 
{};