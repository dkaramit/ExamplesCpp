#include <iostream>


template<size_t N>
auto pp(const auto a){
    if constexpr(N-1>0){
        std::cout<<N-1<<"\t";
        return pp<N-1>(a)+a[N-1];
    }else{
        std::cout<<N-1<<"\n";
        return a[N-1];
    }
}


int main(){
    constexpr double a[30]={1,2,3};

    std::cout<<pp<10>(a)<<"\n";
    
    //this works !!
    double b[30]={1,2,3};
    std::cout<<pp<10>(b)<<"\n";

    b[0]=33;
    std::cout<<pp<10>(b)<<"\n";

    return 0;
}