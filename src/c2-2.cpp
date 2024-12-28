
#include "c2-2.hpp"

int test() {

    B b;

    A* a_p = &b;
    //auto s = static_cast<B*>(a_p); 
    B* b_p = xdd::polymorphic_downcast<B*>(a_p);
    a_p->foo();
    b_p->foo();




    A& a_r = b;
    auto s_r = static_cast<B&>(a_r);
    B& b_r = xdd::polymorphic_downcast<B&>(a_r);

    a_r.foo();
    b_r.foo();


    return 0;
}