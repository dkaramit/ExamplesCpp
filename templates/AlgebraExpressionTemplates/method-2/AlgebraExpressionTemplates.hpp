#ifndef Expr_HEAD
#define Expr_HEAD


#include<iostream>
#include<functional>


// message to print during evaluation, in order to track the evaluation path.
#define msg std::cout<<typeid(*this).name()<<std::endl


class Expression{
    public:
    std::function<double(void)> evaluate;
    
    template<typename T>
    Expression(const T &RH){evaluate = RH.evaluate;}

    template<typename T>
    Expression& operator=(const T &RH){evaluate = RH.evaluate; return *this;}
};




class Number{ 
    double val;
    public:
    Number()=default;

    std::function<double()> evaluate;

    Number(const double &x):val(x){ evaluate = [this](){msg; return this->val;};  }
    Number(const Number &x):val(x.evaluate()){ evaluate = [this](){msg; return this->val;}; }
};

template<typename leftHand,typename rightHand>
class Addition{ 
    const leftHand &LH;
    const rightHand &RH;

    public:
    std::function<double()> evaluate;

    Addition(const leftHand &LH, const rightHand &RH):LH(LH),RH(RH)
    {evaluate = [this](){msg; return this->LH.evaluate() + this->RH.evaluate();};}
};

template<typename leftHand,typename rightHand>
auto operator+(const leftHand &LH, const rightHand &RH){return Addition<leftHand,rightHand>(LH,RH); }





#endif