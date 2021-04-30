#include<iostream>
#include<vector>
#include<conditional.hpp>


int main (){
    using T=double;

    using T1 = conditional<is_double<T>::value,double,int>::type;
    using T2 = conditional<is_int<T>::value,double,int>::type;

    
    std::cout<<typeid(T1).name()<<std::endl;
    std::cout<<typeid(T2).name()<<std::endl;

    return 0;
}