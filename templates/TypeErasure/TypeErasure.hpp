#ifndef TupeErasure_HEAD
#define TupeErasure_HEAD

// initial code from https://stackoverflow.com/questions/34815513/what-is-type-erasure-in-c

#include<iostream>
#include<memory>


class TypeErasedHolder{
  struct TypeKeeperBase{ virtual ~TypeKeeperBase(){}};

  template <class ErasedType>
  struct TypeKeeper : TypeKeeperBase{
    ErasedType storedObject;

    TypeKeeper(ErasedType&& object) : storedObject(std::move(object)) {}
  };


public:
  std::unique_ptr<TypeKeeperBase> held;
  template <class ErasedType>
  TypeErasedHolder(ErasedType objectToStore) : held(new TypeKeeper<ErasedType>(std::move(objectToStore))){}
};





#endif