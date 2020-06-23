#include <iostream>
#include "stdlib.h"//We need it for the exit() command.
#include <typeinfo>//We need it for the typrid() command.
using namespace std;

//You can't define both of them, since you can't overload classes this way.

#define ONE_T
//#define TWO_T





#ifdef ONE_T//How to use class with one template
template <class T>
class Vec{
    T x,y;
    public:
        Vec(T a , T b){
            //Do not allow characters.
            if(typeid(a)==typeid(char)){
                cout<< "A Vec can't have characters. ABORT!"<<endl;
                exit(55);
            }

            x=a;
            y=b;
        }

        T abs2V();
};

template <class T>
T Vec<T>::abs2V(){
    return x*x+y*y;
}













#endif




/*=====================================================*/

#ifdef TWO_T//class with  two templates
template <class T1 , class T2>
class Vec{
    T1 x;
    T2 y;
    public:
        Vec(T1 a , T2 b){
         //Do not allow characters.
            if(typeid(a)==typeid(char) or typeid(b)==typeid(char)){
                cout<< "A Vec can't have characters. ABORT!"<<endl;
                exit(55);
            }
            x=a;
            y=b;
        }
        double abs2V();
};

template <class T1 , class T2>
double Vec<T1 , T2>::abs2V(){
    return (double)(x*x+y*y);
}
#endif





//It is good to use namespaces when you use sich a thing.

int main(){
#ifdef ONE_T
Vec <int> r(2,1);
cout<<r.Vec<int>::abs2V()<<endl;

Vec <char> r2('a','s');

#endif


/*=====================================================*/


#ifdef TWO_T
Vec <int,double> r1(2,1.33);
cout<<r1.Vec<int,double>::abs2V()<<endl;

Vec <double,int> r2(2.33,1);
cout<<r2.Vec<double,int>::abs2V()<<endl;

Vec <double,char> r3(2.33,'d');
cout<<r3.Vec<double,char>::abs2V()<<endl;


//Vec <char,double> r3('d',2.33);
//cout<<r3.Vec<char,double>::abs2V()<<endl;



#endif




return 0;
}

