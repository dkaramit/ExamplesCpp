#include<iostream>
#include<cmath>

#include<TypeErasure.hpp>

#define msg std::cout<<typeid(*this).name()<<std::endl;

template<typename subExpr>
struct GenericExpression{
    const subExpr& self() const {return static_cast<const subExpr&>(*this);}
    subExpr& self() {return static_cast<subExpr&>(*this);}
    
    double evaluate() const { msg; return self().evaluate(); };
};


class Number: public GenericExpression<Number>{
    double val;
    public:
    Number()=default;

    Number(const double &x):val(x){}
    Number(const Number &x):val(x.evaluate()){}
    Number(Number *x):val(x->evaluate()){}
    
    double evaluate()const  { msg; return val;}
    double& evaluate() { msg; return val;}
};

template<typename leftHand,typename rightHand>
class Addition:public GenericExpression<Addition<leftHand,rightHand>>{
    const leftHand &LH;
    const rightHand &RH;

    public:
    Addition(const leftHand &LH, const rightHand &RH):LH(LH),RH(RH){}
    Addition(Addition *add):LH(add->LH),RH(add->RH){}

    double evaluate() const {msg; return LH.evaluate() + RH.evaluate();}
};

template<typename leftHand,typename rightHand>
Addition<leftHand,rightHand> 
operator+(const GenericExpression<leftHand> &LH, const GenericExpression<rightHand> &RH){
    return Addition<leftHand,rightHand>(LH.self(),RH.self()); 
}



using std::cout;
using std::endl;


int main(){
    Number x(5.3);
    Number y(-1.3);

    TypeErasedHolder Z = x;

    Z = x+y+y+y;

    // I want to do:
    // /*1.*/ Z=Z+x;
    // /*2.*/ Z.evaluate();

    return 0;
}