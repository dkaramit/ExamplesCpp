#include<iostream>
#include<cmath>
#include<vector>


#include<AlgebraExpressionTemplates.hpp>


using std::cout;
using std::endl;


int main(){
    Variable x(5);
    Constant y(15);
    Expression<Constant> z(y);
    Expression<Constant> w(y);
    Expression<Variable> u(x);


    cout<<add(x,add(y,x)).evaluate()<<endl;
    cout<<z<<endl;

    z= u ;
    cout<<z<<endl;
    
    z= w+u+z ;
    cout<<z<<endl;

    cout<<x.derivative().evaluate()<<endl;
    cout<<y.derivative().evaluate()<<endl;
    
    
    return 0;
}