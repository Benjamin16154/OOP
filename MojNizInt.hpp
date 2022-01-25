#pragma once
#include <initializer_list>
#include <algorithm>
#include <stdexcept>
class MojNizInt {
  
  int* ptr_{nullptr};
  int  pom_{0};
  int  kapacitet_{1};
  public:
   MojNizInt() {}


  MojNizInt( const std::initializer_list<int>& il ){
    pom_ = il.size();
    ptr_ = new int[pom_];
    kapacitet_=pom_;
    std::copy(il.begin(),il.end(),ptr_);
  }
  
  MojNizInt( const MojNizInt& drugi ) : ptr_{new int[drugi.size()]}, 
  pom_{drugi.pom_}{
                std::copy(drugi.ptr_, drugi.ptr_ + pom_, ptr_);
              }
  MojNizInt(MojNizInt&& drugi) : pom_{drugi.pom_}, ptr_{drugi.ptr_}{
  drugi.pom_ = 0;
  drugi.ptr_=nullptr;
  }

  ~MojNizInt(){delete[] ptr_;}

  void push_back( int value){
//  if(pom_!=kapacitet_){
  int* temp = new int[pom_+1];
  std::copy(ptr_, ptr_ + pom_, temp);
    *(temp + pom_)=value;
    delete[] ptr_;
    ptr_=temp;
    pom_++;
  //}
  // else{
  // kapacitet_=pom_*2;
  // int* temp= new int[kapacitet_];
  // std::copy(ptr_,ptr_+pom_,temp);
  // *(temp + pom_)=value;
  // delete[] ptr_;
  // ptr_=temp;
  // }
  }

  int& at( int i){
  if( i<0 || i>=pom_) throw std::invalid_argument{"Error"};
  return ptr_[i];
  }

  int size() const { return pom_;}
  int& operator[](size_t i){return ptr_[i];}

  MojNizInt& operator=( const MojNizInt& drugi){
  if(this!=&drugi){ 
    delete[] this->ptr_;
    ptr_=new int[drugi.size()];
    std::copy(drugi.ptr_,drugi.ptr_ +drugi.pom_,ptr_);
 }
 return *this;
  }
 
  MojNizInt& operator=(MojNizInt&& drugi){
  delete[] this->ptr_;
  this->pom_=drugi.pom_;
  this->ptr_=drugi.ptr_;
  drugi.pom_=0;
  drugi.ptr_=nullptr;
  return *this;
  }

  MojNizInt operator+=(const MojNizInt& drugi){
    if(pom_!=drugi.pom_)throw std::string{"Error"};
    for(int i=0;i<pom_; ++i)
      ptr_[i]+=drugi.ptr_[i];
    return *this;
  }
  friend MojNizInt operator+(MojNizInt lhs, const MojNizInt& rhs){
    if(lhs.pom_!=rhs.pom_) throw std::invalid_argument("Stop");
    lhs+=rhs;
    return lhs;
  }

  MojNizInt& operator++(){
    return *this;
  }
  MojNizInt operator++(int){
    MojNizInt old=*this;
    operator++();
    return old;
  }
};


