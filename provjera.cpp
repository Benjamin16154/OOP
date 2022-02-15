#include <iostream>
using namespace std;
template <typename T>
class expected {
  public:
  T* ptr{nullptr};
  expected(){}
  expected(T i) : ptr{new T(i)}{};
  expected(const expected& drugi) : ptr{drugi.ptr}{}
  
  bool valid()const{
  if(ptr!=nullptr) return true;
  else return false;
  }

  ~expected(){
  if(valid()==true)
  delete ptr;
  }
  expected& operator=(const expected& other){
  if(this==&other)
    return *this;

  ptr=other.ptr;
  return *this;
  }

  expected& operator=(const expected&& other)
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
template<typename T>
 ostream& operator<<(ostream& o,const expected<T>& e) {
    if (e.valid())
      o << *e;
    else
      o << "Error";
    return o;

   }
int main(void) {

  double f{5},s{5};
  auto e1 = divide(f,s);

  expected<double> e2;
  e2=e1;
  auto e3=move(e1);
  if(e3.valid()) *e3=9;
  cout<<e3<<endl;


  return 0;
}
