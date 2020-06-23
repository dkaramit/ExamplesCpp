#include <iostream>

using namespace std;
#define OVERLOAD_EQUAL



/*
A copy constructor sets the rule of copying an object (which variables it should copy when you assign an object to be equal to the same kind of object).
You might need to set these rules so that, when the destructor is called, pointers are deleted as well.
*/

class Test{


    public:

        int x;
        int* a;
        int _size=5;
        int* ar;
        Test(){ ar=new int[_size]; };        //Normal constructor, it defines ar[_size].
        ~Test(){};                          //Normal destructor


        Test(const Test &T){                    //Copy constructor, works for initialization i.e. Test obj2=obj1. If obj2 is already initialized, then the equals operator (=) takes charge.
                                                //This means that this operator should be overloaded if I want to avoid this (comment out the #definr OVERLOAD_EQUAL to see this).
            this->x=T.x;
            this->a=new int;                     //it defines a new memory cell for a
            *this->a=*T.a;                          //copies the value of T.a to a
            (this->ar)=new int[_size];            //it defines (_size) new memory cells for ar
            for (int i=0; i<_size ;i++ )          //copies the values of T.ar to ar
            {
                this->ar[i]=T.ar[i];
            }
        };
#ifdef OVERLOAD_EQUAL
        Test operator=(const Test&);
#endif // OVERLOAD_EQUAL

};
#ifdef OVERLOAD_EQUAL
Test Test::operator=(const Test& T){
    Test temp=T;
    return temp;

}
#endif // OVERLOAD_EQUAL




int main(){
cout<<"=======Begin=======\n"<<endl;
Test T1;

T1.x=5;
T1.a=&(T1.x);
T1.ar[0]=5;
T1.ar[1]=55;
T1.ar[2]=555;
T1.ar[3]=5555;
T1.ar[4]=55555;

cout<<"copying at initialization"<<endl;
Test T2=T1;


cout<<&T1<<endl;
cout<<&T2<<endl;
cout<<endl;
cout<<T1.a<<endl;
cout<<T2.a<<endl;
cout<<endl;
cout<<T1.ar<<endl;
cout<<T2.ar<<endl;


cout<<endl<<endl;


//If I use T2=T1 after initialization they are the same!
cout<<"copying after initialization"<<endl;
Test T3;
T3=T1;

cout<<&T1<<endl;
cout<<&T3<<endl;
cout<<endl;
cout<<T1.a<<endl;
cout<<T3.a<<endl;
cout<<endl;
cout<<T1.ar<<endl;
cout<<T3.ar<<endl;













cout<<"=======End=======\n"<<endl;
return 0;
}
