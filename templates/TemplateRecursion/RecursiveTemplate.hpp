#ifndef RecTemp_HEAD
#define RecTemp_HEAD
#include<functional>
#include<cmath>



namespace rt{


    int RecursiveSum() {return 0;}

    template <typename T, typename... Args>
    auto RecursiveSum(T first, Args... args){
        return first+RecursiveSum(args...);
    }

    int RecursiveProd() {return 1;}

    template <typename T, typename... Args>
    auto RecursiveProd(T first, Args... args){
        return first*RecursiveProd(args...);
    }


};

#endif