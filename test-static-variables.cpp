#include <iostream>
using namespace std;


//like a global variable.
static int x=1;


void prindots(int);


int main (){



prindots(5);

prindots(20);











return 0;
}

void prindots(int n){

for (int i=0; i<n ; i++)
{
cout << ".";
}
cout  << endl;
x+=5;
cout << x << endl;
}
