
#include <boost/polymorphic_cast.hpp>
#include <iostream>


namespace xdd {

   template<typename T, typename Source>
    T polymorphic_downcast(Source* s){
        //using T = *Target;
       return static_cast<T>(s);

    }

    template<typename T, typename Source>
    T polymorphic_downcast(Source& s){
        //using T = *Target;
       return static_cast<T>(s);

    }
}

struct A { 
    virtual void foo(){std::cout <<"A"<<std::endl;}
    virtual ~A() {}};
struct B : A {
    void foo() override {std::cout <<"B"<<std::endl;} ;
};

int test();
