#ifndef real_included
#define real_included
#include <iostream>
#include <sstream>
#include <string>


/* you can use this to represent double numbers */

template<typename LD, int left, int right, int exp>
class Real{
    public:
    LD value;
    Real(){
        std::string  nString;
        nString=std::to_string(left)+"."+std::to_string(right)+"e"+std::to_string(exp);
        std::istringstream  sNumber(nString);
        sNumber >> value;
    }
};




#endif