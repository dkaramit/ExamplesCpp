#include<iostream>
#include<cmath>
#include<vector>


#include<VectorExpressionTemplates.hpp>


using std::cout;
using std::endl;


int main(){
    Vector<double> x(std::vector<double>{1,2,5,0});
    Vector<double> y(std::vector<double>{555,-2,3,3.25});
    Vector<double> z(std::vector<double>{-30,55.22,0,-6.25});

    Vector<double> w(x.size(),0);

    // since Addition returns an instance of Vector (with Type=Addition<Vector,Vector>), we can do this
    // thanks to the overloading of operator=! 
    w=x+y+z;

    cout<<w<<endl;




    return 0;
}