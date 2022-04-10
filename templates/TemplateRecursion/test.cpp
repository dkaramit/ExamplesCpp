#include<iostream>
#include<vector>
#include<RecursiveTemplate.hpp>

using std::cout;
using std::endl;


int main (){

    std::cout<<rt::RecursiveSum(3,2,0.2465,6)<<"\n";
    std::cout<<rt::RecursiveProd(1,2,0.00002,33)<<"\n";

    std::cout<<rt::RecursiveProd(
        rt::RecursiveSum(3,2,0.2465,6),
        rt::RecursiveSum(3),
        rt::RecursiveSum(1,1,1)
        )<<"\n";



    return 0;
}