#include<iostream>


#define FRIEND



class test {
    public:
     int x;

    test(int x){this->x=x;};
    test(){this->x=0;};
    ~test(){};


    //this is the difference between a friend operator and an operator.
    //when an operator is friend, it does not have access to "this"
    
    #ifndef FRIEND
        int operator+(test T){ return  this->x+ T.x; }
    #endif
    
    #ifdef FRIEND
        friend int  operator+(test T1 ,test T2){ return  T1.x+ T2.x; }
    #endif

    // You can also see it from here. Since this function is a friend, it does not have access to this->x.
    // friend void  func(){ std::cout<<this->x<<std::endl; }
    
    //a friend function shoul be like this:
    friend void  func(test T){ std::cout<<T.x<<std::endl; }


};




int main(){
    test T1(2);
    test T2(55);

    test Tadd=T1+T2;

    func(Tadd);

    return 0;
}