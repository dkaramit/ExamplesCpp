#include <iostream>
#include <vector>
using namespace std;


int main (){

/*like an array, but without specific size!*/ 
vector<int> v1;

int sz=10;

for(int i=0; i<sz;i++){
/*fill it*/	v1.push_back(i);
}
cout<<v1.size()<<endl;

for(int i=0; i<sz;i++){
	cout<<v1[i]<<"\t";
}
	cout<<"\n";

return 0;
}