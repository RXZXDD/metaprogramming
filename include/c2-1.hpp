namespace xdd {
     /// @brief end no pair
    /// @tparam c 
    /// @tparam x 
    /// @tparam y 
    template<typename c, typename x, typename y>
    struct _replace_type {
        using type = c;
    };

    /// @brief end replace
    /// @tparam c 
    /// @tparam y 
    template<typename c, typename y>
    struct _replace_type<c,c,y> {
        using type = y;

    };

    /// @brief recursive start
    /// @tparam c 
    /// @tparam y 
    /// @tparam x 
    template<typename c,typename x,  typename y>
    struct replace_type {
        using type = typename _replace_type<c,x,y>::type;
    };


    /// @brief pointer ver
    /// @tparam c 
    /// @tparam y 
    template<typename c, typename y>
    struct replace_type<c*, c, y> {
        using type = typename replace_type<c,c,y>::type *;
    };

        template<typename c, typename y>
    struct replace_type<c const *, c, y> {
        using type = typename replace_type<c,c,y>::type const *;
    };

    template<typename c, typename y>
    struct replace_type<c [], c, y> {
        using type = typename replace_type<c,c,y>::type [];
    };

    //     template<typename c, typename y>
    // struct replace_type<c &, c, y> {
    //     using type = replace_type<c,c,y>::type &;
    // };

    //         template<typename c, typename y>
    // struct replace_type<c &&, c, y> {
    //     using type = replace_type<c,c,y>::type &&;
    // };

    //         template<typename c, typename y>
    // struct replace_type<c const, c, y> {
    //     using type = replace_type<c,c,y>::type const;
    // };

    template<typename c, typename y>
    struct replace_type< c const, c, y> {
        using type = typename  replace_type<c,c,y>::type const;
    };
}

int test();