#include<iostream>
#include<array>
#include<random>
#include<chrono>

#include<test_class.hpp>


using std::cout;
using std::endl;


using arr=std::array<double,100000>;


// this uses the life of a variable to basically measure time inside a scope! 
class Timer{
    public:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::chrono::time_point<std::chrono::high_resolution_clock> finish;
    std::chrono::duration<double> dt;
    Timer(){
        start = std::chrono::high_resolution_clock::now();
    };
    ~Timer(){
        finish = std::chrono::high_resolution_clock::now();
        dt = finish - start;
        std::cout<<"dt="<<dt.count();
    };
};


int main(){
    std::uniform_real_distribution<double> UnDist( -3. , 3. );
    std::mt19937_64 RandEng;
    std::random_device RandDiv;
    RandEng.seed( RandDiv() );


    arr V1={0};
    for( auto i=V1.begin() ; i != V1.end() ; i++ ){ *i= UnDist(RandEng); }
    



    misc::Test<arr,double> T1{5,V1};
    misc::Test<arr,double> T2{T1};

    //by the way, look at the copy constructor
    #if 0
    cout<<T1.x<<endl;
    cout<<T2.x<<endl;
    for(double _v : T1.V){ cout<<_v<<"\t";  }cout<<endl;
    for(double _v : T2.V){ cout<<_v<<"\t";  }cout<<endl;
    #endif

    #if 0 //this doesn't work
    {
        Timer _;
        constexpr double s = T1.Random(); 
        cout<< s <<endl;
    }
    cout<<endl;
    #endif

    //these work and there is a (kind of) huge difference
    {
        Timer _;
        constexpr double s = T1.Sum(); 
        cout<< s <<endl;
    }
    cout<<endl;
    {
        Timer _;
        double s;
        s = T1.Sum();
        cout<< s <<endl;
    }
    cout<<endl;




    return 0;
}