
#include <iostream>
#include <vector>
#include <list>


#define printV(X) for( vector<int>::iterator itV=X.begin(); itV<X.end();itV++)\
{cout << *itV<< "\t";}cout<<endl;
/*use  "\" (without any spaces on the right) to change line*/

#define printL(X) for( list<int>::iterator itL=X.begin(); itL!=X.end();itL++)\
{cout << *itL<< "\t";}cout<<endl;


using std::cout;
using std::vector;
using std::list;
using std::endl;


int main (){
vector <int> iv;
list <int> il;

for(int i=0 ; i<10 ; i++){
iv.push_back(i*6);
il.push_back(i*4);
}


vector<int>::iterator itV;
list<int>::iterator itL;

//initialize the iterators.
itL=il.begin();
itV=iv.begin();

//move to position 2 of the vector. I can do this:
itV+=2;

//or itV++;  itV++; .

//move to position 2 of the list. I can't use itL+=2.
itL++ /*1*/; itL++ /*2*/;

//insert a value in the list and the vector. It inserts at the position of the iterator in the following\
way:
il.insert(itL,256);
iv.insert(itV,512);

printV(iv);
cout<<"=========================================================\n";

printL(il);
cout<<"=========================================================\n";







































return 0;
}
