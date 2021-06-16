#ifndef Expr_HEAD
#define Expr_HEAD


#include<iostream>
#include<cmath>

#define msg std::cout<<typeid(*this).name()<<std::endl;


struct BaseExpression{
    BaseExpression()=default;
    virtual double evaluate()const =0 ;
    virtual BaseExpression* clone()const =0 ;
};

template<typename subExpr>
struct GenericExpression:BaseExpression{
    const subExpr& self() const {return static_cast<const subExpr&>(*this);}
    
    double evaluate() const { msg; return self().evaluate(); };
    
    GenericExpression* clone() const { return new GenericExpression(*this); }  

};


class Number: public GenericExpression<Number>{
    double val;
    public:
    Number()=default;

    Number(const double &x):val(x){}
    Number(const Number &x):val(x.evaluate()){}
    
    double evaluate()const  { msg; return val;}
    Number* clone() const { return new Number(*this); }  

};

template<typename leftHand,typename rightHand>
class Addition:public GenericExpression<Addition<leftHand,rightHand>>{
    const leftHand &LH;
    const rightHand &RH;

    public:
    Addition(const leftHand &LH, const rightHand &RH):LH(LH),RH(RH){}

    double evaluate() const {msg; return LH.evaluate() + RH.evaluate();}
    Addition* clone() const { return new Addition(LH,RH); }  
};

template<typename leftHand,typename rightHand>
Addition<leftHand,rightHand> 
operator+(const GenericExpression<leftHand> &LH, const GenericExpression<rightHand> &RH){
    return Addition<leftHand,rightHand>(LH.self(),RH.self()); 
}


class Expression: public GenericExpression<Expression>{
    BaseExpression *baseExpr;
    public:

    Expression()=default;
    Expression(const Expression &E){baseExpr = E.baseExpr->clone();};

    template<typename subExpr>
    void assign(const GenericExpression<subExpr> &expr){
        baseExpr = expr.clone();
    }

    double evaluate() const {msg;  return baseExpr->evaluate();}

    Expression* clone() { return new Expression(*this); }  
};




#endif