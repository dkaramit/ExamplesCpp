#ifndef Expr_HEAD
#define Expr_HEAD


#include<iostream>
#include<functional>


// message to print during evaluation, in order to track the evaluation path.
#define msg std::cout<<typeid(*this).name()<<std::endl



template<typename subExpr>
struct GenericExpression{
    const subExpr& self() const {return static_cast<const subExpr&>(*this);}
    subExpr& self() {return static_cast<subExpr&>(*this);}

    // double evaluate() const { msg; return self().evaluate(); };
};


class Number: public GenericExpression<Number>{
    double val;
    public:
    Number()=default;

    std::function<double()> evaluate;

    Number(const double &x):val(x){ evaluate = [this](){msg; return this->val;};  }
    Number(const Number &x):val(x.evaluate()){ evaluate = [this](){msg; return this->val;}; }
};

template<typename leftHand,typename rightHand>
class Addition:public GenericExpression<Addition<leftHand,rightHand>>{
    const leftHand &LH;
    const rightHand &RH;

    public:
    std::function<double()> evaluate;

    Addition(const leftHand &LH, const rightHand &RH):LH(LH),RH(RH)
    {evaluate = [this](){msg; return this->LH.evaluate() + this->RH.evaluate();};}
};

template<typename leftHand,typename rightHand>
Addition<leftHand,rightHand> 
operator+(const GenericExpression<leftHand> &LH, const GenericExpression<rightHand> &RH){
    return Addition<leftHand,rightHand>(LH.self(),RH.self()); 
}


class Expression: public GenericExpression<Expression>{
    public:
    std::function<double(void)> evaluate;
    
    template<typename T>
    Expression(const GenericExpression<T> &RH){evaluate = RH.self().evaluate;}

    template<typename T>
    Expression& operator=(const GenericExpression<T> &RH){evaluate = RH.self().evaluate; return *this;}
};




#endif