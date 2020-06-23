#include <iostream>
#include <vector>
using namespace std;

int main(){
cout<<"=======Begin=======\n"<<endl;
vector<int> v1;
v1.push_back(5);
v1.push_back(55);
v1.push_back(555);
v1.push_back(5555);

for (vector<int>::iterator it1=v1.begin(); it1!=v1.end() ; it1++ )
{
    int &c=*it1;
    int C=*it1;
    cout<<*it1<<"\t";
    cout<<c<<"\t";
    cout<<C<<endl;
}//Notice that when initializing a reference you enter the value of the variable not the memory location

int x=99;
int* px=&x;
int& rx=*px;
int& Rx=x;

cout<<x<<"\t"<<*px<<"\t"<<rx<<"\t"<<Rx<<endl;

cout<<&x<<"\t"<<px<<"\t"<<&rx<<"\t"<<&Rx<<endl;


cout<<"=======End=======\n"<<endl;
return 0;
}
