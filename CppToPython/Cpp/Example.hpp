#ifndef class_HEAD
#define class_HEAD

class calcClass{
    double x,y;

    public:
    calcClass(double x, double y):x(x),y(y){}

    double sum(){return x+y;}
    
    double mul(){return x*y;}

    double sumWith(double z){return x+y+z;}
};

#endif