#include "type_traits"
#include <string>

namespace xdd_w2 {
    static const char* literal_int= "int";
    static const char* literal_char= "char";
    static const char* literal_long= "long";
    static const char* literal_short= "short";
    static const char* literal_unkown= "unknown";

    template<typename Ty>
    std::string _type_descriptor(){
        
       return literal_unkown;
        
    }

    template<>
    std::string _type_descriptor<int>(){
        
       return literal_int;
        
    }

    template<>
    std::string _type_descriptor<char>(){
        
       return literal_char;
        
    }

    template<>
    std::string _type_descriptor<long>(){
        
       return literal_long;
        
    }

    template<>
    std::string _type_descriptor<short>(){
        
       return literal_short;
        
    }



    // template<typename Ret>
    // struct _type_descriptor_func{
    //       using return_type = void;

    //     //   using func = void
    // };

    // template<typename Ty>
    // struct _type_descriptor_func <Ty(*)()>{
    //       using return_type = Ty;
    //       //using func = Tp
    // };

    // template<>
    // const char* _type_descriptor<void>(){
        
    //    return literal_short;
        
    // }

    template<typename Ty>
    std::string type_descriptor(){
 //       std::string ret ="";
        if(std::is_pointer_v<Ty>){
            return "pointer to "+type_descriptor<std::remove_pointer_t<Ty>>();
        }
        else if (std::is_reference_v<Ty>)
        {
            return "reference to "+type_descriptor<std::remove_reference_t<Ty>>();
        }
        else if (std::is_const_v<Ty>) {
            return "const "+type_descriptor<std::remove_const_t<Ty>>();
        }
        else if (std::is_array_v<Ty>){
            return "array of "+type_descriptor<std::remove_extent_t<Ty>>();
        }
        // else if (std::is_function_v<Ty>) {
            
        //     return "function returning"+type_descriptor<_type_descriptor_func<Ty>::return_type>();
        // }
        
        return _type_descriptor<Ty>();
        
    }

}