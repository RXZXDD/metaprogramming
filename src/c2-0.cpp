#include "c2-0.hpp"
#include <iostream>

int test(){
     std::cout<<"is same : " <<  std::is_same<xdd::add_const_ref<char>::type, char const&>::value  <<std::endl;
     std::cout<<"is same : " <<  std::is_same<xdd::add_const_ref<char&>::type, char>::value  <<std::endl;
     return 0;
}