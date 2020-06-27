#include<iostream>
#include <iomanip>
#include<chrono>
#include<random>

// define these to simplify the code
#define Now() (std::chrono::high_resolution_clock::now())
#define Duration(t0,t1)(  ((std::chrono::duration<long double>)(t1-t0)).count() )



using std::cout;
using std::endl;


int main(){    
    // let's time different ways to get random numbers 
    std::ranlux48 RandEng1;
    std::mt19937_64 RandEng2;
    std::random_device RandDiv;

    // seed the random engines (random_device returns a random integer, and can be used to seed)
    RandEng1.seed( RandDiv() );
    RandEng2.seed( RandDiv() );

    // uniform distribution in (-3 , 3)
    std::uniform_real_distribution<double> UnDist( -3. , 3. );

    auto t0 =Now(), t1 =Now();

    t0 =Now();
    for(int i=0 ; i<1e5 ; ++i){ UnDist(RandEng1); }
    t1=Now();
    cout <<  Duration(t0,t1) << endl;
    
    
    t0 =Now();
    for(int i=0 ; i<1e5 ; ++i){ UnDist(RandEng2); }
    t1=Now();
    cout <<  Duration(t0,t1) << endl;
    
    t0 =Now();
    for(int i=0 ; i<1e5 ; ++i){ RandDiv(); }
    t1=Now();
    cout <<  Duration(t0,t1) << endl;
    

    int p=10;
    cout << std::setprecision(p);
    cout<<std::right;
    cout << std::setfill( ' ' );
    t0 =Now();
    for (size_t i = 0; i < 10; ++i){
        cout << std::setw(p+5) << UnDist(RandEng1)<< std::setw(p+5) << UnDist(RandEng2)<< std::setw(p+5) << RandDiv() <<endl; 
    }
    t1=Now();
    cout <<  Duration(t0,t1) << endl;
    
    
    return 0;
}