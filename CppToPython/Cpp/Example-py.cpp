#include<Example.hpp>



extern "C"{

    void* INIT(double x, double y){return new calcClass(x,y);}

    void DEL(void *inst){ delete static_cast<calcClass*>(inst); inst=nullptr;}

    double SUM(void* inst){return static_cast<calcClass*>(inst)->sum();}

    double MUL(void* inst){return static_cast<calcClass*>(inst)->mul();}

    double SUMWITH(void* inst, double z){ return static_cast<calcClass*>(inst)->sumWith(z);}

}