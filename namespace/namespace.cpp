#include "headers.h"


int main(){
cout<<"\n=======Begin=======\n"<<endl;
    int c=2;

    std::cout << * (int*) F1 :: func(c) <<endl;// F1::func(c) returns a void pointer, (int*) converts this void* to int*, * derefences the int* !


    F2 :: func();



cout<<"\n========End========\n"<<endl;
return 0;
}
