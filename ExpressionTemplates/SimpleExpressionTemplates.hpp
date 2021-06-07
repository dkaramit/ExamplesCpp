#include<iostream>
#include<cmath>
#include<vector>


using unInt = unsigned int;

/*
Let's see how expression templates work.

The idea is to express every calculation as expression objects so that the compiler writes and
optimizes the result symbolically, reducing numerical evaluation time. 
*/

// this is a class that defines an abstract expression (every expression inherits this class)
template<typename Type>
class Expression{
    public:
    // This allows us to convert any expression to its sub-expressions, giving us access to their members. 
    inline const Type& subExpression() const {return  *static_cast<const Type*>(this);} 

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

    template<typename ExprType>
    Vector(const Expression<ExprType> &other){
        const ExprType &v= other.subExpression();

        for(unInt i=0; i<v.size(); ++i){
            elements.push_back(v[i]);
        }

        length=elements.size();
    }


    // constructor that takes any Expression and makes it a vector
    template<typename ExprType>
    Vector& operator=(const Expression<ExprType> &other){
        const ExprType &v= other.subExpression();
        for(unInt i=0; i<length; ++i){
            elements[i]=v[i];
        }
        return *this;
    }


    // get the size of the vector
    unInt size() const {return length;}


    // get elements
    double operator[](unInt i) const {return elements[i];}
    double& operator[](unInt i){return elements[i];}//this is useful in order to reassign v[i].


    // printing 
    friend std::ostream& operator<<(std::ostream& os, Vector v){
        os<<'(';
        for(unInt i=0; i<v.size(); ++i){
            if(i!=v.size()-1){os << v[i]<<',';}
            if(i==v.size()-1){os << v[i]<<')';}
        }
        
        return os;
    }

};





// this is the addition operation (which is also an expression)
template<typename leftHand, typename rightHand>
class Addition: public Expression< Addition<leftHand, rightHand> >{
    unInt length;
    const leftHand &LH;
    const rightHand &RH;

    public:
    

    Addition(const leftHand &LH, const rightHand &RH) :LH(LH),RH(RH){}

    double operator[](unInt i) const {return LH[i] + RH[i]; } 

    unInt size() const {return  LH.size();}//LH.size and RH.size should be equal

    // printing 
    friend std::ostream& operator<<(std::ostream& os, Addition v){
        os<<'(';
        for(unInt i=0; i<v.size(); ++i){
            if(i!=v.size()-1){os << v[i]<<',';}
            if(i==v.size()-1){os << v[i]<<')';}
        }
        
        return os;
    }
};

// we can now define the addition
template<typename leftHand, typename rightHand>
Addition<leftHand,rightHand> operator+(const Expression<leftHand> &LH, const Expression<rightHand> &RH){
    return Addition<leftHand,rightHand>(LH.subExpression(),RH.subExpression());//this expands the addition if leftHand is another addition.
}



// this is the multiplication of vector with number
template<typename vecExpr>
class vecNumMul: public Expression< vecNumMul<vecExpr> >{
    unInt length;
    const vecExpr &V;
    const double &Num;

    public:
    

    vecNumMul(const vecExpr &V, const double &Num) :V(V),Num(Num){length=V.size();}

    double operator[](unInt i) const {return Num*V[i]; }

    unInt size() const {return  V.size();}



    // printing 
    friend std::ostream& operator<<(std::ostream& os, vecNumMul v){
        os<<'(';
        for(unInt i=0; i<v.size(); ++i){
            if(i!=v.size()-1){os << v[i]<<',';}
            if(i==v.size()-1){os << v[i]<<')';}
        }
        
        return os;
    }
};





// define the multiplication with a number
template<typename vecExpr>
vecNumMul<vecExpr> operator*(const Expression<vecExpr> &V, const double &Num){
    return vecNumMul<vecExpr>(V.subExpression(),Num);
}

// define the multiplication with a number
template<typename vecExpr>
vecNumMul<vecExpr> operator*(const double &Num,const Expression<vecExpr> &V){
    return vecNumMul<vecExpr>(V.subExpression(),Num);
}

// The inner product returns a number, so it is not an epression, but it takes expressions as arguments
template<typename leftHand, typename rightHand>
double dot(const Expression<leftHand> &LH, const Expression<rightHand> &RH){
    double product=0;
    leftHand lh=LH.subExpression();
    rightHand rh=RH.subExpression();
    for(unInt i=0; i<lh.size(); ++i){
        product+=lh[i]*rh[i];
    }
    return product;
}