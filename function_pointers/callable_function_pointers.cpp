#include<iostream>
#include<functional>

// std::function<double(int,double)> can be any callable object with signature double (int,double)

using func = std::function<double(int,double)>;

// this function takes std::function<double(int,double)> and two numbers
void print(func f, int i, double x){
    std::cout<<f(i,x)<<std::endl;
}

// this function takes a pointer to std::function<double(int,double)> and two numbers
void print(func *f, int i, double x){
    std::cout<<(*f)(i,x)<<std::endl;
}

// you can see that it works with simple functions
double add(int i, double x){return i+x;}
double mul(int i, double x){return i*x;}

// it also works with static member functions and objecs with overloaded operatore() 
struct operations{
    static double div (int i, double x){ return i/x;}

    double c;
    operations(double c):c(c){}


    double operator()(int i, double x){ return c+i+x;}
};

int main()
{
    std::cout<<std::endl << "===========Begin==========="<<std::endl<<std::endl;

    std::cout<<"pass simple functions\n";
    print(add, 1,2);
    print(mul, 1,2);

    std::cout<<"pass function pointers\n";
    print(&add, 1,2);
    print(&mul, 1,2);

    std::cout<<"pass static member function\n";
    print(operations::div, 1,2);
    std::cout<<"pass pointer to static  member function\n";
    print(&(operations::div), 1,2);


    operations OP(3.);

    std::cout<<"pass  an object\n";
    print(OP, 1,2);
    // you can't do this, because the compiler sees the address of OP... 
    // print(&OP, 1,2);
    


    std::cout<<std::endl << "============End============"<<std::endl<<std::endl;
    return 0;
}
