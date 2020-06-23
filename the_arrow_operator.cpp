#include <iostream>

using namespace std;

class Obj{

    public:
        int i,j;
//As explained in the main, there is no difference between (*this). and this -> , because this is a pointer to an Obj instance.
        Obj(){(*this).i=0;(*this).j=0; }
        Obj(int i, int j){this -> i=i; this -> j=j;}
        ~Obj(){cout<<"Done"<<endl;}

        void None_F(){cout<<this->i<<this->j<<endl;}
};


int main (){

    Obj A;
    A.i=4;
    A.j=5;
    cout<< A.i<<"  "<< A.j <<endl;



    Obj * B=&A;
//If I define a pointer to A (B=&A), I can get the attribute "i" by dereferencing B and then asking for i, i.e. (*B).i.
    cout<< (*B).i<<"  "<< (*B).j <<endl;

//Another way is to use the arrow operator (->). The arrow operator, dereferences the poiter to an object and then
//gets the attribute.
    cout<< B->i<<"  "<< B->j <<endl;
// These mean that (*Pointer_to_instance).Attribute=Pointer_to_instance->Attribute

    A.None_F();
    B->None_F();
    (*B).None_F();

   ( ( Obj*) &A )->Obj::None_F() ;


    return 0;
}
