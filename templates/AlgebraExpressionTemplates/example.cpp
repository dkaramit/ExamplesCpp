#include<iostream>
#include<cmath>
#include<vector>


#include<AlgebraExpressionTemplates.hpp>


using std::cout;
using std::endl;


int main(){
    Number x(3.2);
    Number y(-2.3);
    Expression z,w;

    // works fine!
    // z.assign(x);
    // cout<<z.evaluate()<<endl;

    // works fine!
    // z.assign(x+y);
    // cout<<z.evaluate()<<endl;

    // works fine!
    // z.assign(y+x+x+x+x);
    // cout<<z.evaluate()<<endl;

    
    // works fine!
    // w.assign(z+y);
    // cout<<w.evaluate()<<endl;

    // Segmentation fault of z.evaluate() infinite recursion in between
    // LH.evaluate() (in Addition<Expression,Number>::evaluate()) and 
    // baseExpr->evaluate() (in Expression::evaluate())
    // z.assign(z+x);
    // cout<<z.evaluate()<<endl;

    // Uknown Segmentation fault!
    // z.assign(y+x+x+x+x);
    // w.assign(z+y+z);
    // cout<<w.evaluate()<<endl;

    return 0;
}