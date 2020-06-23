#include "headers.h"


/*
By the way, this is the use of void pointers
*/

//declare a function that gets an int (by reference)
void* F1::func(int &x)
{
    void* _x=(void*) &x; //conversts the location of the int to a location of a void ( &x is int*, (void*) &x is void*  )
    cout << "func1" << "\n";
    return _x; //returns the void pointer
}
