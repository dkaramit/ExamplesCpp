#include<iostream>
#include<cmath>
#include<functional>
#include<vector>


#include<AlgebraExpressionTemplates.hpp>


using std::cout;
using std::endl;


inline Expression func (std::vector<Expression> x, int i){
    cout<<i<<endl;

    if (i==0){return static_cast<Expression>(x[0]);}    

    return static_cast<Expression>( x[i] + func(x,i-1) ) ;
};


int main(){
    Number y(-2.);
    Number x(1.33);

    Expression z(y+x);
    Expression w(x+y+x);
    
    // works
    z =x;
    cout<<z.evaluate()<<endl;
    cout<<(z+z+z+z).evaluate()<<endl;

    // Segfault due to recusion 
    // z =z+x;
    // cout<<z.evaluate()<<endl;

    // Unkown Segfault 
    // z = x+y ;
    // cout<<(z+z).evaluate()<<endl;
    // cout<<typeid(z+z).name()<<endl;

    // Unkown Segfault 
    // z = w+y+x+x;
    // cout<<z.evaluate()<<endl;

    
    
    // Unkown Segfault 
    // std::vector<Expression> X={x,y,x,y,x,y,x,y};

    // cout << typeid(func(X,X.size()-1)).name()  << endl;
    // cout << (func(X,X.size()-1)).evaluate()  << endl;
    return 0;
}