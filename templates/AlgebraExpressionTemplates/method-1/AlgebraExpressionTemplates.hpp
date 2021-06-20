#ifndef Expr_HEAD
#define Expr_HEAD


#include<iostream>
#include<memory>


// message to print during evaluation, in order to track the evaluation path.
#define msg std::cout<<typeid(*this).name()<<std::endl;


struct BaseExpression{
    BaseExpression()=default;
    virtual double evaluate()const =0 ;
};

template<typename subExpr>
struct GenericExpression:BaseExpression{
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


class Expression: public GenericExpression<Expression>{
    public:
    std::unique_ptr<BaseExpression> baseExpr;

    Expression()=default;
    // Expression(const Expression &E){baseExpr = (E.baseExpr ;};
    // Expression(Expression *E){baseExpr = E->baseExpr;};

    double evaluate() const {msg;  return baseExpr->evaluate();}


    template<typename subExpr>
    void assign(const GenericExpression<subExpr> &RH){
        baseExpr = std::make_unique<subExpr>(new subExpr(RH.self()));
    }

};




#endif