#include <iostream>
#include <vector>
#include <algorithm>
using std::vector; using std::cin; using std::cout; using std::endl;

int main(void)
{
  vector<int> vec1;
  int i;
 cout<<"Enter a few numbers: "<<endl;
 while(cin>>i){
   vec1.push_back(i);
 }

for(int k=vec1.size()-1; k>=0; --k){
cout<<vec1.at(k)<<' ';

 }
cout<<'\n';
 sort(vec1.begin(),vec1.end());
 auto j=vec1.size()-1;
cout<<"Najmanji: "<<vec1[0]<<endl;
cout<<"Najveci: "<<vec1[j]<<endl;



  return 0;
}
