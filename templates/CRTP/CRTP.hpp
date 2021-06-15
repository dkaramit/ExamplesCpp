#ifndef CRTP_HEAD
#define CRTP_HEAD



template<typename LD, typename subExpr>
class GenericExpression{
    public:
};

template<typename LD>
class Expression: public GenericExpression<LD,Expression<LD>>{
    LD value;
    public:

    template<typename subExpr>
    Expression(const GenericExpression<LD,subExpr> &expr):value( expr.evaluate() ){}
    

};



template<typename LD>
class Constant: public GenericExpression<LD,Constant<LD>>{
    LD value;
    public:
    using numType = LD;
    Constant()=default;
    Constant(const LD &x ):value(x) {}
    Constant(const Constant &c ):value(c.evaluate()) {}
    LD evaluate()  const {return value;}
    LD& evaluate()  {return value;}
    // auto derivative()const{return Constant<LD>(0);}
};

template<typename LD>
class Variable: public GenericExpression<LD,Variable<LD>>{
    LD value;
    public:
    using numType = LD;

    Variable()=default;
    Variable(const LD &x ):value(x) {}
    Variable(const Variable &x):value(x.evaluate()) {}

    LD evaluate()  const {return value;}
    LD& evaluate()  {return value;}

    // auto derivative()const{return Constant<LD>(1);}
};


template<typename LD, typename leftHand, typename rightHand>
class Addition:public GenericExpression<LD, Addition<LD,leftHand,rightHand>>{
    public:
    leftHand LH;
    rightHand RH;

    Addition(const leftHand &LH, const rightHand &RH):LH(LH),RH(RH){}

    LD evaluate()const{return LH.evaluate() + RH.evaluate();}

    // auto derivative()const{return LH.derivative() + RH.derivative();}
};

template<typename LD, typename leftHand, typename rightHand>
auto operator+(const GenericExpression<LD, leftHand> &LH, const GenericExpression<LD,rightHand> &RH){
    return Addition<LD,leftHand,rightHand>
                (*static_cast<const leftHand*>(&LH),*static_cast<const rightHand*>(&RH));
}



#endif