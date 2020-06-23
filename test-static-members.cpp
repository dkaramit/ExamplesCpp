#include <iostream>
using namespace std;

/*==================================================================================================================================================================*/
/*
static member function is a member function independent of the variables of each instance. It can be called as a normal function even if no instances are created.
 These kind of functions can process only static variables (and global of course).
*/


/*
A static member variable is a variable independent of the variables of each instance. They are like global variables relevant to a class.
*/

//So, static members are great to keep statistics for different objects.
/*==================================================================================================================================================================*/






//a global variable
int P=0;

class Test
{
public:
    static int s;
    int S;
    Test();
    ~Test();
    static void add1();
//protected:
//private:
};
int Test::s=0;

void Test::add1(){

    s++; // This can be done because s is static.
    //S++; // This is not allowed because a static function does not work with instances (remember that S means this->S, which is not defined to a static function).
    P++;
};


int main (){
/*A sattic variable can be called from main and do whatever a normal variable ca do.*/
cout<<Test::s<<endl;
Test::s++;
cout<<Test::s<<endl;
//the same holds for the static function
Test::add1();
cout<<Test::s<<endl;

cout<<P<<endl;



return 0;
}
