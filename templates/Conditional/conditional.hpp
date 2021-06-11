#ifndef cond_included
#define cond_included


/* you can use the is_int class to check whether T is int */
// everything gives false
template<typename T>
class is_int{
    public:
    constexpr static bool value = false; 
};

// only int gives true
template<>
class is_int<int>{
    public:
    constexpr static bool value = true;
};
/*-------------------------------------------*/

/* you can use the is_int class to check whether T is double */
template<typename T>
class is_double{
    public:
    constexpr static bool value = false; 
};

template<>
class is_double<double>{
    public:
    constexpr static bool value = true;
};
/*-------------------------------------------*/


/* You can also use conditinals to assign types based on boolean values */
// assign conditional::type to T1
template<bool value, typename T1, typename T2>
class conditional{
    public:
    using type = T1;
};

// if value=true then assign conditional::type to T2
template<typename T1, typename T2>
class conditional<false,T1,T2>{
    public:
    using type = T2;
};

#endif