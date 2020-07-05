#ifndef Class_INCLUDE
#define Class_INCLUDE
#include<random>
#include<array>
#include<algorithm>

namespace  misc {
    using std::cout;
    using std::endl;
    using std::array;
    
    template<typename Array, typename LD>
    class Test{
        private:
        std::uniform_real_distribution<double> UnDist;
        std::ranlux48 RandEng;
        std::random_device RandDiv;

        public:

        LD x;
        Array V;

        Test(){};
        Test(LD x, Array V){
            UnDist = std::uniform_real_distribution<double> {-x,x};
            this->RandEng.seed( this->RandDiv() );
            this->x=x; 
            this->V=V;
        };
        
        //strange copy-constructor
        Test(const Test &T){
            this->x=0;
            this->V=T.V;
            this->RandEng.seed( this->RandDiv() );
            UnDist = std::uniform_real_distribution<double> {-x,x};
        };
        
        ~Test(){};

        //this does not work with constexpr (random numbers cannot be)
        constexpr LD Random(){
            LD s=0;
            for(int i=0 ; i<1e7 ;++i){s+=UnDist(RandEng);}
            return s;
        }

        constexpr LD Sum(){
            LD s=0;
            for(int i=0 ; i<1e6;++i){s+=1;}
            return s;
        }

    };

}



#endif