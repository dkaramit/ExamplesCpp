#include <iostream>


using namespace std;

int main (){
int x;
int* xP;
xP=&x;
cout<<x<<endl;
cout<<xP<<" has :"<<*xP<<endl;
cout<<"==========================\n";
//we can delete x. We just have to delete the contents of the memory cell that contains x i.e. xP.\
So, we free memory
delete xP;
cout<<x<<endl;
cout<<xP<<" has :"<<*xP<<endl;
cout<<"==========================\n";
/* We can't declare x and xP again (compiler error).
int x;
int* xP;
xP=&x;
cout<<x<<endl;
cout<<xP<<" has :"<<*xP<<endl;
cout<<"==========================\n";
*/

return 0;
}
