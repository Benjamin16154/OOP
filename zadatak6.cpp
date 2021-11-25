#include <iostream>
#include <string>

using std::cout; using std::cin; using std::string; using std::endl;

int main(void)
{
 string first;
 string second;

cout<<"Enter the first word: "<<endl;
cin>>first;
cout<<"Enter the second word: "<<endl;
cin>>second;

auto i=0;
auto counter=0;

while(first[i] !='\0')
{
  if(first[i] != second[i])
    counter++;

  i++;
}

cout<<counter<<endl;
cout<<first<<endl;
cout<<second<<endl;

  return 0;
}
