#include <string>

namespace xdd_w1 {

    template<typename Ty>
    struct typer {

        using type = Ty;
       inline static std::string value = "unknown";
    };

    template<typename Ty>
    struct typer <Ty*> {

        using type = typename typer<Ty>::type*;
        inline static std::string value = typer<Ty>::value + "*";
    };

        template<typename Ty>
    struct typer <Ty&> {

        using type = typename typer<Ty>::type&;
        inline static std::string value = typer<Ty>::value + "&";
    };

            template<typename Ty>
    struct typer <Ty const> {

        using type = typename typer<Ty>::type const;
        inline static std::string value = typer<Ty>::value + " const";
    };

    template<>
    struct typer<int> {

        using type = int;
        inline static std::string value = "int";
    };

        template<>
    struct typer<char> {

        using type = char;
        inline static std::string value = "char";
    };

        template<>
    struct typer<short> {

        using type = short;
        inline static std::string value = "short";
    };

        template<>
    struct typer<long> {

        using type = long;
        inline static std::string value = "long";
    };

    template<typename Ty>
    std::string type_descriptor () {
        return typer<Ty>::value;
    }


}