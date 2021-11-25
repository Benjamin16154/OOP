#include <iostream>
#include <math.h> 

using std::cin; using std::cout; using std::endl; using std::string;

int main(void)
{
  bool flag1=0;
  bool flag2=0;
  int a,b;
  char o;

  cout<<"Enter first number: "<<endl;
  if(!(cin>>a)){
    flag1=1;
    cin.clear();
    cin.ignore(10000,'\n');
  }
  cout<<"Enter the required operation: "<<endl;
  cin>>o;
  cout<<"Enter another number: "<<endl;
  if(!(cin>>b)){
    flag2=1;
    cin.clear();
   cin.ignore(10000,'\n');
  }
  if(flag1==1 && flag2==1)
  cout<<"Invalid input, a and b are letters."<<endl;
  
  else if(flag1==1)
    cout<<"a is not a number."<<endl;
    
  else if(flag2==1)
    cout<<"b is not a number."<<endl;
  else{

    switch(o){
    case '+':
      cout<<"a + b = "<<a+b<<endl;
      break;

    case '/':
      if(b==0)
        cout<<"Division with 0 is unhealthy"<<endl;
      else
      cout<<"a / b = "<<a/b<<endl;
      break;

    case '%':
      cout<<"a % b = "<<a%b<<endl;
      break;

    case '*':
      cout<<"a * b = "<<a*b<<endl;
      break;

    case '^':
      cout<<"a ^ b = "<<pow(a,b)<<endl;
      break;
  }
  } 
  return 0;
}
