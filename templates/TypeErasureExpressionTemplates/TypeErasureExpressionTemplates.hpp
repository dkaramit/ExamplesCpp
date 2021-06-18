#ifndef Expr_HEAD
#define Expr_HEAD


#include<iostream>
#include<cmath>


// message to print during evaluation, in order to track the evaluation path.
#define msg std::cout<<typeid(*this).name()<<std::endl;



template<typename subExpr>
struct GenericExpression{
    const subExpr& self() const {return static_cast<const subExpr&>(*this);}
    subExpr& self() {return static_cast<subExpr&>(*this);}
    
    double operator()() const { msg; return self()(); };
};


class Number: public GenericExpression<Number>{
    double val;
    public:
    Number()=default;

    Number(const double &x):val(x){}
    Number(const Number &x):val(x()){}
    
    double operator()()const  { msg; return val;}
    double& operator()() { msg; return val;}
};

template<typename leftHand,typename rightHand>
class Addition:public GenericExpression<Addition<leftHand,rightHand>>{
    const leftHand &LH;
    const rightHand &RH;

    public:
    Addition(const leftHand &LH, const rightHand &RH):LH(LH),RH(RH){}

    double operator()() const {msg; return LH() + RH();}
};

template<typename leftHand,typename rightHand>
Addition<leftHand,rightHand> 
operator+(const GenericExpression<leftHand> &LH, const GenericExpression<rightHand> &RH){
    return Addition<leftHand,rightHand>(LH.self(),RH.self()); 
}


class Expression: public GenericExpression<Expression>{
    public:

};




#endif