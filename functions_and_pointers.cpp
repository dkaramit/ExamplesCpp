#include <iostream>
using namespace std;


//-----Both of the following function do the same thing------//
// this function is used as func1(&x)
void func1(int*);

// this function is used as func2(x)
void func2(int&);
//--------------------------------------------------//

// this function can take anything and return (effectively) anything!!
template<typename T>
void* func3(T x){
    void* p;
    p=&x;
    return p;
};


// this function can take anything, return (effectively) anything, and it uses pointers!!
template<typename T>
void* func4(T* x){
    void* p;

    p=x;
    return p;
};







int main(){

    int c=5;
    cout<<c<<endl;
    cout<<"============="<<endl;


    func1(&c);
    cout<<c<<endl;
    cout<<"============="<<endl;

    func2(c);
    cout<<c<<endl;
    cout<<func3(c)<<endl;
    cout<<* (int*) func3(c)<<endl;
//    cout<<* func3(c)<<endl;//this does not compile (cannot return void).
    cout<<"============="<<endl;


    double k1;
    k1=5.01;
    cout<< * (double*) func3(k1)<<endl;
    cout<<"============="<<endl;



    double k2;
    k2=6.2515;
    cout<< * (double*) func4(&k2)<<endl;



    //Use a variable to "store" functions
    void* (*FUNC)(double);
    //(*FUNC) is a function (see below) that takes a double and returns void*.

    FUNC=func3;//I can use FUNC as func3!!
    cout<<FUNC(k1)<<endl;
    cout<<"============="<<endl;


    //anoter example
    void (*FUNCp)(int*);
    FUNCp=func1;
    c=0;
    FUNCp(&c);
    cout<<c<<endl;

    return 0;
}





void func1(int *x){
    *x=*x+1;
}


void func2(int &x){
    x=x+1;
}





