#include<iostream>

/*
Templates that cannot be "processed" are ignored if there is a valid one (I believe this is what SFINAE is about). 
Also, a specialization can redefine a default template argument. 

These two facts can be exploited in order to specialize templates for multiple types at once
*/


using std::cout;
using std::endl;


//these can be used to check types of arguments
template<class T> struct isDouble { static const bool value=false; };
template<> struct isDouble<double> { static const bool value=true; };

template<class T> struct isInt { static const bool value=false; };
template<> struct isInt<int> { static const bool value=true; };


// enable_if::type is only defined if B==true. So, if we ask for enable_if<false,T>::type we should get 
// a compiler error, unless it is used in the context of SFINAE.  
template<bool B, typename T> struct enable_if {};
template<typename T> struct enable_if<true, T> { using type=T; };


// You can use enable_if like this:
template<typename T1,typename T2, typename dummy=void>
struct classCheck{
    classCheck(){cout << typeid(T1).name() <<"\t"<< typeid(T2).name() <<endl;}  
};

// this replaces classCheck<int,double,void>, and ignored (it can't be compiled) in the other cases.
template<typename T1,typename T2>
struct classCheck<T1,T2, typename enable_if< isInt<T1>::value && isDouble<T2>::value, void>::type>{
    classCheck(){cout << "integer and double" <<endl;}
};





int main(){
    {classCheck<char,int> c;}
    {classCheck<int,double> c;}
    {classCheck<double, int> c;}
    {classCheck<double, double> c;}

    return 0;
}