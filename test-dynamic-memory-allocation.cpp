#include <iostream>
#include <stdlib.h>//for malloc. malloc is for C. new is better!
using namespace std;
/*
Some basics first. There are two compartments in memory (it is good to know it).
--The stack: All variables declared inside the function will take up memory from the stack.
--The heap: This is unused memory of the program and can be used to allocate the memory dynamically when program runs.
*/





/*
Note: If you are creating such things in functions, you have to delete them before the
function ends, because it does not do this automatically.
*/

class Test{
    public:
        Test(){cout<<"creating object"<<endl; };
        ~Test(){cout<<"deleting object"<<endl;};
        int a;

};



Test* New_Test();


int main (){


/*The memory may not have been allocated successfully, if the free store had been used up.
So it is good practice to check if new operator is returning NULL pointer and take appropriate action as below:
*/




double* pvalue  = NULL;
if( !(pvalue  = new double ))
{
   cout << "Error: out of memory." <<endl;
   return 1;

}


delete pvalue; // Release memory pointed to by pvalue




//And arrays
char* pcvalue  = NULL;   // Pointer initialized with null
pcvalue  = new char[20]; // Request memory for the variable

delete [] pcvalue;        // Delete array pointed to by pvalue



//you can see what happens from the constructors and destructor
Test* p1; //this does not call the constructor (it's not an instance)!
p1=new Test;// this calls it

p1->a=90;

cout<<p1->a<<endl;

/*Remember that delete and delete[] call the destructor as well, while free doesn't.*/

delete p1;//this calls the destructor !








//malloc

Test* p;
p=New_Test();


p->a=55;

cout<< p->a <<endl;
free(p);




return 0;
}






Test* New_Test(){
Test* P= (Test*)malloc(sizeof *P);

}

