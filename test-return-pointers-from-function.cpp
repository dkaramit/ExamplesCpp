#include <iostream>


using namespace std;
//You can use this kind of functions to return the address of a variable (this means also arrays).



int * Func( )
{
  static int  r[10];//if you don't define it as static, as soon as the function closes, r will be (probably) deleted.


  for (int i = 0; i < 10; ++i)
  {
     r[i] = i*5;
    cout << r[i] << endl;
  }

  return r;
}






int main ()
{
   // a pointer to an int.
   int *p;

   p = Func();
   for ( int i = 0; i < 10; i++ )
   {
       cout << "*(p + " << i << ") : ";
       cout << *(p + i) << endl;
   }






   return 0;
}
