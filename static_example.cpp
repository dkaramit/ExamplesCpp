#include <iostream>

using namespace std;


// static variables are defined once.
// Then, they can just change their values
namespace Func{

    void f(double x)
    {
        static double Si=0;

        Si=Si+x;
        cout<<Si<<endl;
    }

}

// static variables in class are not bound to instances.
// A classic example is to count how many instances have been created.
    
namespace Cl
{
    class c
    {
      public:
        static int Ni;
        
        c(){  ++Ni;}
        static void NoInstances()
        {
        cout<<Ni<<endl;
        }
    };
    

int c::Ni=0;
}



int main()
{
    cout<<"running static variable in function:"<<endl;
    // When Func is called for the first time the compiler knows that Si exists (it is declared).
    // From that point, since Si is known, ther is no problem doing this:
    for(int i=0; i<=10 ; ++i)
    {
        Func::f(2);
        
    }
    cout<<"running static member variable and static member function:"<<endl;    
    Cl::c X;
    Cl::c::NoInstances();
    Cl::c Y;
    Cl::c::NoInstances();
    
    

}















