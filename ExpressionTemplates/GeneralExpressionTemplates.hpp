#include<iostream>
#include<cmath>
#include<vector>


using unInt = unsigned int;

/*

*/

template<typename Type>
class Expression{
    public:
    // This allows us to convert any expression to its sub-expressions, giving us access to their members. 
    // inline const Type& subExpression() const {return  *static_cast<const Type*>(this);} 
};

// this is the vector class. It will be used to define vectors that can be added and multiplied.
class Vector: public Expression<Vector>{
    using Type =  std::vector<double>;

    std::vector<double> elements;
    unInt length;

    public:

    // the standard constructor for a vector
    Vector(const Type &v): elements(v),length(v.size()){}
    Vector(unInt size): elements(size), length(size){}

    Vector(const Vector &v){

        for(unInt i=0; i<v.size(); ++i){
            elements.push_back(v.evaluate(i));
        }

        length=elements.size();
    }


    // constructor that takes any Expression and makes it a vector
    Vector& operator=(const Vector &v){
        
        for(unInt i=0; i<length; ++i){
            elements[i]=v.evaluate(i);
        }
        return *this;
    }


    // get the size of the vector
    unInt size() const {return length;}


    // get elements
    double evaluate(unInt i) const {return elements[i];}
    double& evaluate(unInt i){return elements[i];}//this is useful in order to reassign v[i].


    // printing 
    friend std::ostream& operator<<(std::ostream& os, Vector v){
        os<<'(';
        for(unInt i=0; i<v.size(); ++i){
            if(i!=v.size()-1){os << v.evaluate(i)<<',';}
            if(i==v.size()-1){os << v.evaluate(i)<<')';}
        }
        
        return os;
    }

};



// Define a generic operator that takes two expressions (these are called binary operators)
template<typename Operator, typename leftHand, typename rightHand>
class binaryOperator: public Expression< binaryOperator<Operator,leftHand,rightHand> >{
    unInt length;
    const leftHand &LH;
    const rightHand &RH;
    public:
    
    binaryOperator(const leftHand &LH, const rightHand &RH) :LH(LH),RH(RH){}

    unInt size() const {return  LH.size();}//LH.size and RH.size should be equal
    double evaluate(unInt i) const {return Operator::evaluate(LH, RH, i); } 


    // printing 
    friend std::ostream& operator<<(std::ostream& os, binaryOperator v){
        os<<'(';
        for(unInt i=0; i<v.size(); ++i){
            if(i!=v.size()-1){os << v.evaluate(i)<<',';}
            if(i==v.size()-1){os << v.evaluate(i)<<')';}
        }
        
        return os;
    }
};

// you can then use this generic operator to simply get the sum
template<typename leftHand, typename rightHand>
class Addition{
    public:
    static double evaluate (const leftHand &LH, const rightHand &RH, unInt i) {
        return LH.evaluate(i)+RH.evaluate(i);
    }
};

// definition of sum through the generic biniaryOperator
template<typename leftHand, typename rightHand>
binaryOperator<Addition<leftHand,rightHand>,leftHand,rightHand> operator+(const leftHand &LH, const rightHand &RH){
    return binaryOperator<Addition<leftHand,rightHand>,leftHand,rightHand>(LH,RH);
}


/*-------------------------------*/
// in the same way you can define operators that take one expression (unaryOperators)

// Define a generic operator that takes two expressions (these are called binary operators)
template<typename Operator, typename Expr>
class unaryOperator: public Expression< unaryOperator<Operator,Expr> >{
    unInt length;
    const Expr &V;
    public:
    
    unaryOperator(const Expr &V) :V(V){}

    unInt size() const {return  V.size();}
    double evaluate(unInt i) const {return Operator::evaluate(V, i); } 


    // printing 
    friend std::ostream& operator<<(std::ostream& os, unaryOperator v){
        os<<'(';
        for(unInt i=0; i<v.size(); ++i){
            if(i!=v.size()-1){os << v.evaluate(i)<<',';}
            if(i==v.size()-1){os << v.evaluate(i)<<')';}
        }
        
        return os;
    }
};

// For example, define the Cos of a vector to be:
// Cos(V)={cos(V[0]),cos(V[1]),cos(V[2]),...}
template<typename Expr>
class Cos{
    public:
    static double evaluate (const Expr &V, unInt i) {
        return std::cos(V.evaluate(i)) ;
    }
};

// definition of cos through the generic uniaryOperator
template<typename Expr>
unaryOperator<Cos<Expr>,Expr> cos(const Expr &V){
    return unaryOperator<Cos<Expr>,Expr>(V);
}
