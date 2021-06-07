#include<iostream>
#include<cmath>
#include<vector>

using std::cout;
using std::endl;


#include<SimpleExpressionTemplates.hpp>



int main(){

    Vector x(std::vector<double>{1,2,5,0});

    Vector y(x);
    y[3]=6.23;

    cout<<x<<endl;
    cout<<y<<endl;

    cout<<(x+y)[3]<<endl;
    // cout<<(x+y+x+y)[3]<<endl;
    // cout<<(x+x+x+x+x+x+x+x)[3]<<endl;


    cout<<(x+y+y+x).size()<<endl;
    // cout<<(x+y+x).size()<<endl;
    // cout<<(x+y+y+x+y+y+x).size()<<endl;
    

    Vector u(x+y);
    cout<<u<<endl;
    
    cout<<x+y<<endl;

    // cout<<4*x<<endl;
    // cout<<x*4<<endl;
    // cout<<2*x*2<<endl;


    cout<<dot(2*y+x*3,(y+x)*2)<<endl;


    return 0;
}