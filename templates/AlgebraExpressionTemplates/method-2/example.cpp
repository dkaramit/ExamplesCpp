#include<iostream>
#include<cmath>
#include<functional>


#include<AlgebraExpressionTemplates.hpp>


using std::cout;
using std::endl;




int main(){
    Number y(-2.);
    Number x(1.33);

    Expression z(y+x);
    Expression w(x+y+x);
    
    cout<<z.evaluate()<<endl;

    z =y+x+x+x;
    cout<<z.evaluate()<<endl;


    // Unkown Segfault 
    z =w+y+x+x;
    cout<<z.evaluate()<<endl;
    
    // Segfault due to recusion 
    z =z+x;
    cout<<z.evaluate()<<endl;

    return 0;
}