#include<iostream>
#include<cmath>
#include<vector>

using std::cout;
using std::endl;


#include<GeneralExpressionTemplates.hpp>



int main(){

    Vector x(std::vector<double>{1,2,5,0});

    Vector y(x);
    y.evaluate(3)=6.23;

    cout<<x<<endl;
    cout<<y<<endl;

    Vector u(x+y+x);
    cout<<u<<endl;
    cout<<cos(u)<<endl;


    return 0;
}