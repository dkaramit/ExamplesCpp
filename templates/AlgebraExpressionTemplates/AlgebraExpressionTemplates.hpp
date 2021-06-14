#ifndef Expr_HEAD
#define Expr_HEAD


#include<iostream>
#include<cmath>

using unInt = unsigned int;

class Constant{
    double value;

    public:
    Constant()=default;
    Constant(const double &x):value(x){}
    double evaluate()  const {return value;}
    double& evaluate()  {return value;}
    Constant derivative()  const {return Constant(0);}
};


class Variable{
    double value;

    public:
    Variable()=default;
    Variable(const double &x):value(x){}
    double evaluate()  const {return value;}
    double& evaluate()  {return value;}
    Constant derivative()  const {return Constant(1);}

};



template<typename leftHand , typename rightHand>
class Addition{
    leftHand LH;
    rightHand RH;

    public:
    Addition(const leftHand& LH, const rightHand& RH): LH(LH), RH(RH){}

    double evaluate() const{ return LH.evaluate()  + RH.evaluate() ;  }
    auto derivative()  const {return LH.derivative() +  RH.derivative();}
};

template<typename leftHand, typename rightHand>
auto add(const leftHand& LH, const rightHand& RH ){
    return Addition<leftHand,rightHand>(LH,RH);
}


template<typename Type>
class Expression{
    Type expr;
    public:
    Expression(const Type &expr):expr(expr){}

    template<typename otherType>
    Expression& operator=(const Expression<otherType> &expr){
        this->evaluate()=expr.evaluate();//need some kind of copying, in order to get the derivative member
        return *this;
    }

    double evaluate() const {return expr.evaluate();}
    double& evaluate() {return expr.evaluate();}
    
    auto derivative() {return expr.derivative();}

    const Type& getExpr() const {return expr;}
};



template<typename leftType, typename rightType>
auto operator+ (const Expression<leftType>& lh, const Expression<rightType>& rh){
  return 
  Expression<Addition<leftType, rightType> >(Addition<leftType, rightType >
  (lh.getExpr(), rh.getExpr()));
}




template<typename Type>
std::ostream& operator<<(std::ostream& os, const Expression<Type>& v){os <<v.evaluate(); return os;}


#endif