#include <sys/ioctl.h>
#include <chrono>
#include <iostream>
#include <thread>
#include <string>
 using namespace std;
size_t broj_kolona() {
  winsize sz;
  ioctl(0, TIOCGWINSZ, &sz);
  return sz.ws_col;
}

void pauziraj(unsigned int msec) {
  std::flush(std::cout);
  std::this_thread::sleep_for(std::chrono::milliseconds{msec});
}

int main() {
auto a=broj_kolona();
auto c=a/3;
for(auto x=0; x<2; x++){

  for(auto i=0; i<c ;++i){
  cout<<"/";
  cout<<"\b";
  pauziraj(100);
  cout<<" ";
  cout<<"-";
  cout<<"\b";
  pauziraj(100);
  cout<<" ";
  cout<<"\\";
  cout<<"\b";
  pauziraj(100);
  cout<<" ";
}
 cout<<'\r';

}




    return 0;
}
