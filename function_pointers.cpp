#include<iostream>

using namespace std;

// This function takes as input an integer, and a function that gets T1 and returns nothing, and returns nothing.
//You can use it to call pass other functions inside this.
// it is used as func(x, func), and not func(x, &func) because functions are already "pointers".
template<class T1>
void func( int x, void (*function)(T1) ) {
    function(x);
}


void func1(int x){
    cout << "Hey from func1: "<<x << "\n";
}

void func2(int x){
    cout << "Hey from func2: "<<x << "\n";
}

//FUNC is a function pointer type (points to a functio that takes an integer and returns nothing).
// You can use it to "store" functions in variables.
typedef void (*FUNC)(int);


int main(int argc, char* argv[])
{
    cout<<endl << "===========Begin==========="<<endl<<endl;


    func(2,func1);
    func(5,func2);

    FUNC F;


    F=func1;
    func(2,F);

    F=func2;
    func(5,F);



    cout<<endl << "============End============"<<endl<<endl;
    return 0;
}
