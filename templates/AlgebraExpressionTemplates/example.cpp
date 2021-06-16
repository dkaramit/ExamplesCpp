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
    
    z.assign(x);
    // cout<<z.evaluate()<<endl;
    // z.assign(x+y);
    // cout<<z.evaluate()<<endl;

    // z.assign(z);
    // Segmentation fault (infinite recursion in expr->evaluation())
    // cout<<z.evaluate()<<endl;

    w.assign(z);
    cout<<w.evaluate()<<endl;

    return 0;
}