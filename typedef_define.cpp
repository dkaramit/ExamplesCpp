#include <iostream>

//define defines a behavior.
#define O(EX)cout << #EX <<":"<< EX << endl;
//where #EX is the name of the variable.







using namespace std;
int main (){
//typedef defines type. Say intP instead of int*.
typedef int* intP;

int x=20;
intP i=&x;


cout<<i<<endl;

cout<<x<<endl;

cout<<"=========================== \n";

O(x);
O(i)
O(*i)




return 0;
}
