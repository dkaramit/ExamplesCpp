#include<iostream>

/*
If you have a member function template (call it func<...>), 
and you need to call it inside another class (from an instance x),
you need to use "x.template func<...>(...)" instead of x.func<...>(...).
*/

/*this is an example that makes things more clear*/


class Print{
    public:
    template <int num>
    auto print(){  std::cout<<num<<std::endl;  }
};



template<typename T>
class Class{
    public:
    T X;


    template <int num>
    auto evaluate(){  X.template print<num>();  }
    
    /*This does not compile*/
    // template <int num>
    // auto evaluate(){  X.print<num>();  }
};

int main(){
    Class<Print> test;
    Print p;

    // here you can do both...
    test.evaluate<5>();
    test.template evaluate<5>();
    
    p.print<5>();
    p.template print<5>();
    
    return 0;
}