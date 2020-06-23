#include <iostream>

using namespace std;
//A void pointer can point to objects of any data type! So it may be useful.

void  func1(){
    cout<<"void"<<endl;
//this does not work
//    double l=0.3;
//    return l;
};

//void pointers enable void functions to return something. You can use void* return values to return multiple types of variables (like void* variables).
void *func2(){
    cout<<"void*"<<endl;
//this works
    static double p=3.3; //static so it would not change unexpectedly.
    return &p;
};


int main(){
cout<<"=======Begin=======\n"<<endl;

void *vp;
int i=5;
double a=9.9;

vp=&i;
cout<<*(int*)vp<<endl;// if you want to use it, you need to tell the compiler what it is! So you first convert vp to int* (you are telling the compiler that it points to int) and then print it.

vp=&a;
cout<<*(double*)vp<<endl;//same here.

func1();
//cout<<(double)func1()<<endl; //use this to see what happens when you ask a void function to return something. SPOILER ALLERT: doesn't compile in the first place if you try to return to void.

cout<<*(double*)func2()<<endl;









cout<<"=======End=======\n"<<endl;
return 0;
}
