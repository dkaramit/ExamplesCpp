#include<iostream>




class test_1 {
    public:
        int x;

    test_1(){this->x=0;};
    test_1(int x){this->x=x;};
    ~test_1(){};


    void func(){ std::cout<<this->x<<std::endl; }

    void friend add_2(test_1 &T){T.x  +=2; };
};


class test_2 : public test_1 {
    public:
    //this gets the constructors correctly (if you remove it the declaration test_2 T2(4); diesn't work) !
    using test_1::test_1;
};

int main(){
    test_1 T1(2);
    test_2 T2(4);


    T1.func();
    add_2(T1);
    T1.func();

    T2.func();
    add_2(T2);
    T2.func();



    return 0;
}