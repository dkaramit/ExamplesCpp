#ifndef VECTOR_HEAD
#define VECTOR_HEAD

/*I wrote this example after looking at https://www.modernescpp.com/index.php/expression-templates*/
/*You should check it out*/

#include<iostream>
#include<cmath>
#include<vector>

using unInt = unsigned int;

template<typename LD, typename Type=LD>
class Expression{
  Type value;   

public:
    Expression()=default;
    Expression(const LD value) : value(value){}

    // Constructor for other Expression<Type>
    Expression(const Type& other) : value(other){}

    /*assignment to another expression*/
    template<typename otherLD, typename otherType>
    Expression& operator=(const Expression<otherLD, otherType>& other){
        value()=other();
        return *this;
    }

    LD operator()(const unInt i) const{ return elements[i]; }
    LD& operator()(const unInt i){ return elements[i]; }
};


template<typename LD, typename Type>
std::ostream& operator<<(std::ostream& os, const Expression<LD,Type>& v)
{
    os <<v();
    return os;
}


#endif