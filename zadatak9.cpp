#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main(void)
{
 int r;  
 string s{"\342\230\272"};
 cout<<"Enter number of rows: "<<endl;
 cin>>r;
 if(r<=0){
   cout<<"Wrong input mate!"<<endl;
   return 1;
 }

   for(int j=1; j<=r ; j++){
    for(int k=1; k<=j; k++){
     cout<<s;
    }
   cout<<'\n';
  }

  return 0;
}
