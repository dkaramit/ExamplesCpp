//This needs C++20

#include<iostream>
#include<type_traits>
using std::cout;
using std::is_same;

struct X{
    const long double value;
    constexpr X(long double value):value(value){}

};


template <X v>
struct C{constexpr static long double value=v.value;};


int main()
{
    cout<<is_same<C<4.5l>,C<4.4999999999999999l>>::value<<"\n";
    cout<<bool(4.5l==4.4999999999999999l)<<"\n";
 
    cout<<is_same<C<4.5>,C<4.4999999999999999>>::value<<"\n";
    cout<<bool(4.5==4.4999999999999999)<<"\n";


    cout<<C<12>::value<<"\n";
}
