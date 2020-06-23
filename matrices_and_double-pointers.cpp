#include <iostream>
using namespace std;

void fill_units(int*, int );





template<typename T>
void fill_with(T** Array, int n ,int m, T x){

    for(int i=0; i<n;i++ ){
        for(int j=0; j<m;j++ ){
            Array[i][j]=x;}
        }
};


template<typename T>
void print_Matrix(T** Array, int n ,int m){
    for(int i=0; i<n;i++ ){
        for(int j=0; j<m;j++ ){cout<<Array[i][j]<<endl;}
        }
};

template<typename T1, typename T2,typename T3>
void add_Matrices(T1** Array1, T2** Array2 ,int n ,int m, T3** Array3){
    for(int i=0; i<n;i++ ){
        for(int j=0; j<m;j++ ){
                Array3[i][j]=Array1[i][j]+Array2[i][j];
                }
        }
};



int main(){
    int n,m;



    n=5;
    int* Ar1= new int[n];
    fill_units(Ar1,n);
    for(int i=0 ; i<n;i++){
        cout<<Ar1[i]<<endl;
    }

    delete [] Ar1;



    n=3;
    m=11;
    double** Ar3= new double*[n];
    for(int i=0;i<n;i++){
        Ar3[i]=new double[m];
    }

    int** Ar4= new int*[n];
    for(int i=0;i<n;i++){
        Ar4[i]=new int[m];
    }

    double** Ar5= new double*[n];
    for(int i=0;i<n;i++){
        Ar5[i]=new double[m];
    }



    fill_with( Ar3,n,m,52.1215);
    fill_with( Ar4,n,m,-33);
    add_Matrices(Ar3,Ar4,n,m,Ar5);
    print_Matrix(Ar5,n,m);

    for(int i=0;i<n;i++){delete Ar3[i];}
    delete [] Ar3;
    for(int i=0;i<n;i++){delete Ar4[i];}
    delete [] Ar4;
    for(int i=0;i<n;i++){delete Ar5[i];}
    delete [] Ar5;

cout<<"-------------------------------------"<<endl;











return 0;
}







void fill_units(int* Array, int Dim){//1D
int* tmp_Ar= new int [Dim];

for(int i=0 ; i<Dim;i++){
    tmp_Ar[i]=1;
}

for(int i=0 ; i<Dim;i++){
    Array[i]=(*tmp_Ar +1);
}

delete [] tmp_Ar;
}
