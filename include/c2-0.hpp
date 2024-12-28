namespace xdd {
    template<class _Ty>
    struct add_const_ref{
        using type = _Ty const &;
    };

    template<class _Ty>
    struct add_const_ref<_Ty&>{
        using type = _Ty;
    };
}

int test();