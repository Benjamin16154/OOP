#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout; using std::cin; using std::endl;

int main(void)
{
 int i=0;
 int userNumber;
 bool flag=0;

 srand(time(0));                     //https://java2blog.com/random-number-between-1-and-10-cpp/<Paste>
 auto j=(rand()%100)+1;
 
 while(i<5){
   cout<<"Enter a number: "<<endl;
   cin>>userNumber;
   if(userNumber>j)
     cout<<"Too high"<<endl;
   else if(userNumber<j)
     cout<<"To low"<<endl;
   else if(userNumber==j){
     cout<<"Bingo!"<<endl;
     flag=1;
     break;
   }
   i++;
 }
if(flag==0)
  cout<<"More luck next time"<<endl;

  cout<<"The number was: "<<j;
  return 0;
}
