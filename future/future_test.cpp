#include<iostream>
#include<future>
using std::cout;
using std::endl;

// Ok.. I get a strange behaviour. I'll come to this later

// a function that takes some time to return something
double f(double x){
    cout<<x<<endl;
    double y=x;
    for (int i = 0; i < (int)1e9; i++){
        y+=i;
    }


    return y;
}





int main(){
    int s=0;
    cout<<++s<<endl;
    auto run1=std::async(f,-100);
    cout<<++s<<endl;
    auto run2=std::async(f,100);



    cout<<++s<<endl;
    double x=run1.get();

    cout<<++s<<endl;
    f(500);

    cout<<++s<<endl;
    double y=run2.get();


    // std::cin.get();
    return 0;
}