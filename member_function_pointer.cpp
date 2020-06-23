#include <iostream>
/*
This example shows how to use a function pointer of a member function. Since there is a difference in the 
sugnature of functions and member functions, the syntax is kind of different.

You can use a lambda expression to wrap a member function, but I think using a function pointer is a bit more clear from what I have seen.
*/

class Test {
    public:

    double f(double x) {
        return x*2.;
    }

    // double(Test::*Func)(double) is the signature of a member function.
    void res(   double(Test::*Func)(double)  ) ;
};


// both "typedef" and "using" should be equivalent here:
// typedef double(Test::*Func)(double);
using Func=double(Test::*)(double);



// Observe that you have to dereference the function first!
void Test::res(  Func F ){
    std::cout<< (this->*F)(5)  <<std::endl;
}
 

// if res is not a member function, you have to also pass an instance (a non-static member function needs an instance)
void res(Func F, Test &t){
    std::cout<< (t.*F)(5)  <<std::endl;
}


// normal pointer to function
using NFunc = double(*)(double) ;
double f(double x) {
    return x*2.;
}

int main() {
    Test T1;
    
    // you have to pass the pointer of Test::f 
    T1.res( &Test::f );

   
    // Notice that the a pointer to member is quite different than pointer to function. It is declared as:
    Func g=&Test::f;
    // And you call it like this. Still needs an instance (that's why we have Test().*g )
    std::cout<<(Test().*g)(5)<<std::endl;

    // remember that pointer to function can   be declared and called as both a "value" and a pointer
    NFunc Ng = &f ;
    std::cout<<(*Ng)(5)<<std::endl;

    NFunc _Ng = f ;
    std::cout<<_Ng(5)<<std::endl;



    res(&Test::f  , T1);

    return 0;
}