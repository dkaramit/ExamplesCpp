#ifndef VECTOR_HEAD
#define VECTOR_HEAD

/*I wrote this example after looking at https://www.modernescpp.com/index.php/expression-templates*/
/*You should check it out*/

#include<iostream>
#include<cmath>
#include<vector>

using unInt = unsigned int;

template<typename LD, typename Type= std::vector<LD> >
class Vector{
  Type elements;   

public:
    Vector()=default;
    Vector(const unInt n, const double value) : elements(n, value){}

    // Constructor for other Vector<Type>
    Vector(const Type& other) : elements(other){}

    // assign Vector to different Vector<LD,Type>. 
    // This will be used to assign a Vector + Vector to another Vector.
    // See how to implement operator+ in order to do this.
    template<typename otherLD, typename otherType>
    Vector& operator=(const Vector<otherLD, otherType>& other){
        for (unInt i = 0; i < elements.size(); ++i){elements[i] = other[i];}
        return *this;
    }

    // number of elements
    unInt size() const{ return elements.size(); }

    // get and set elements
    LD operator[](const unInt i) const{ return elements[i]; }
    LD& operator[](const unInt i){ return elements[i]; }

    const Type& getElements() const {return elements;} 
};


// Addition of vector 
template<typename LD, typename leftHand , typename rightHand>
class Addition{
    leftHand lh;
    rightHand rh;

    public:
    Addition(const leftHand& lh, const rightHand& rh): lh(lh), rh(rh){}

    LD operator[](const unInt i) const{ return lh[i] + rh[i];  }

    unInt size() const{ return lh.size(); }
};

// overload operator+ that returns an instance of Vector<LD, Addition>
// Defining operator+ in this way, we can assign the sum of two vectors to a new vector! 
template<typename LD, typename leftType, typename rightType>
auto operator+ (const Vector<LD, leftType>& lh, const Vector<LD, rightType>& rh){
  return 
  Vector<LD, Addition<LD, leftType, rightType> >(Addition<LD, leftType, rightType >
  (lh.getElements(), rh.getElements()));
}


template<typename LD, typename Type>
std::ostream& operator<<(std::ostream& os, const Vector<LD,Type>& v)
{
    os <<"(";
    for(unInt i=0; i<v.size(); ++i){
        os<<v[i];
        if(i<v.size()-1){os<<",";}else{os<<")";}
    }
    return os;
}


#endif