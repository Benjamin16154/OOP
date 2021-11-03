#include <bitset>
#include <iostream>
void printBits(unsigned short reg) {
  std::bitset<16> bits(reg);
  std::cout << bits << std::endl;
}

int main() {
  
  int flag2=1;
  int reg_select;
  static int reg1=0;
  static int reg2=0;

  while(true){ 

  std::cout <<"Select register: "<<std::endl;
  std::cout <<"Register 1"<<std::endl;
  std::cout <<"Register 2"<<std::endl;
  std::cout <<" ------ "<<std::endl;
  std::cin>>reg_select; 
  std::cout<<"Selection successful"<<std::endl;
  if(reg_select==1){
  
    while(flag2==1){

    std::cout << "1. Print register" << std::endl;
    std::cout << "2. Set bit in register" << std::endl;
    std::cout << "3. Reset bit in register" << std::endl;
    std::cout << "4. Switch register value"<<std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter option: ";
    int option;
    std::cin >> option;
    
      while(true) {
      if (option == 1) {
      printBits(reg1);
      break;
    
      }else if (option == 2) {
      int b=1;
      int c;
      std::cout<<"Enter bit number: "<<std::endl;
      std::cin>>c;
      reg1=reg1|(b<<c);
      printBits(reg1);
      std::cout<<"New register value: "<<reg1<<std::endl;
      std::cout<<" "<<std::endl;
      break;
      
      }else if (option == 3) {
      int b=1;
      int c;
      std::cout<<"Enter bit number: "<<std::endl;
      std::cin>>c;
      reg1=reg1^(b<<c);
      printBits(reg1);
      std::cout<<"New register value: "<<reg1<<std::endl;
      break;

      }else if (option == 5) {
      flag2=0;
      break;
    }

    std::cout << std::endl;
      }
    }
    std::cout<<"I am here"<<std::endl;
  }
  else if(reg_select==2){
    while(flag2==1){

    std::cout << "1. Print register" << std::endl;
    std::cout << "2. Set bit in register" << std::endl;
    std::cout << "3. Reset bit in register" << std::endl;
    std::cout << "4. Switch register value"<<std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter option: ";
    int option;
    std::cin >> option;
    
      while(true) {
      if (option == 1) {
      printBits(reg2);
      break;
    
      }else if (option == 2) {
      int b=1;
      int c;
      std::cout<<"Enter bit number: "<<std::endl;
      std::cin>>c;
      reg2=reg2|(b<<c);
      printBits(reg2);
     
      std::cout<<"New register value: "<<reg2<<std::endl;
      std::cout<<" "<<std::endl;
      break;

      }else if (option == 3) {
      int b=1;
      int c;
      std::cout<<"Enter bit number: "<<std::endl;
      std::cin>>c;
      reg2=reg2^(b<<c);
      printBits(reg2);
      std::cout<<"New register value: "<<reg2<<std::endl;
      break;

      }else if (option == 5) {
      flag2=0;
      break;
      }
    std::cout << std::endl;
      }
    }
    std::cout<<"I am here"<<std::endl;
  }
  }
  return 0;
}
