#include<iostream>
#include<vector>
#include<Real.hpp>


int main (){
    Real<double,-1,5,2> x;
    Real<double,10,5,2> y;

    std::cout<<x.value<<"+"
    <<y.value<<"="
    <<x.value + y.value<<std::endl;

    return 0;
}