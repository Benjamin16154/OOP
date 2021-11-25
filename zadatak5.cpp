#include <iostream>
#include <math.h>

using namespace std;

int main(void)
{
  int entry_number; 
  cout<<"Enter a number: "<<endl;
  cin>>entry_number;

  for(auto c=1; c<=entry_number; c++){
    for(auto b=1; b<=entry_number; b++){
      for(auto a=1; a<=entry_number; a++){
          if(a*a+b*b==c*c && a>b)
            cout<<a<<" , "<<b<<" , "<<c<<endl;
          continue;
      }
    }
  }

  return 0;
}
