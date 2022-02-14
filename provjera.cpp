#include <iostream>
using namespace std;
template <typename T>
class expected {
  public:
  T* ptr{nullptr};
  expected(){}
  expected(T i) : ptr{new T(i)}{};

  void print1(){
    std::  cout<<*ptr<<endl;
  }
  expected(const expected& drugi) : ptr{drugi.ptr}{}
  
  bool valid(){
  if(ptr!=nullptr) return true;
  else return false;
  }

  ~expected(){
  if(valid()==true)
  delete ptr;
  }
  // std::ostream& operator<<(std::ostream& o, const expected<T>& e) {
  //   if (e.valid())
  //     o << *e;
  //   else
  //     o << "Error";
  //   return o;
  //
  //  }
  expected& operator=(const expected& other){
  if(this==&other)
    return *this;

  ptr=other.ptr;
  return *this;
  }

  expected& operator=(expected&& other)
  {
   if(this==&other)
     return *this;
   delete ptr;
   ptr=other.ptr;
   return *this;
  }

  expected& operator*(){

    
    return *this;
  }
};


expected<double> divide(double f, double s){
  if(s==0.)return {};
  return f/s;
}
int main(void) {

  double f{5},s{5};
  auto e1 = divide(f,s);
  e1.print1();

  expected<double> e2;
  e2=e1;
  auto e3=move(e1);
  if(e3.valid()) *e3=9;
  e2.print1();
  e3.print1();




  return 0;
}
