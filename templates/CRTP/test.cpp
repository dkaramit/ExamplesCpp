#include<iostream>
#include<vector>
#include<CRTP.hpp>

using std::cout;
using std::endl;

int main (){

    Variable<double> x(5.);
    Constant<double> c(-1.);

    cout<<(x+x).evaluate()<<endl;
    cout<<(x+c).evaluate()<<endl;
    cout<<(x+x).derivative().evaluate()<<endl;
    cout<<(x+c).derivative().evaluate()<<endl;

    Expression<double> z(x+c);

    return 0;
}