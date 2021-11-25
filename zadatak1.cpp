#include <iostream>
#include <string>
namespace Temperature{
  const double celsiusKelvinCoeff = 273.15;
  double celsiusToKelvin ( double C ){
    double K= C + 273
  double celsiusToFahrenheit ( double C ){
    double F=(9/5 * C) + 32;
    return F;
  }
  double fahrenheitToCelsius ( double F ){
    double C=5/9*( F - 32 );
    return C;
  }
  double kelvinToFahrenheit ( double K ){
    double F = K * 9/5 - 459.67;
    return F;
  }
  double fahrenheitToKelvin ( double F ){
    double K = (F + 459.67)*5/9;
    return K;
  }
}

namespace Speed{


}
namespace Lenght{


}

namespace Weight{


}

namespace Fuel{


}

int main(void)


{
  int option1,option2;
  double value,output;
  std::cout<<"Welcome to Unit converter. Please etner one of the following options:"<<std::endl;
  std::cout<<"\t 1. Temperature"<<std::endl;
  std::cout<<"\t 2. Speed"<<std::endl;
  std::cout<<"\t 3. Lenght"<<std::endl;
  std::cout<<"\t 4. Weight"<<std::endl;
  std::cout<<"\t 5. Fuel economy"<<std::endl;
  std::cin>>option1;
   
  if(option1 == 1){
    std::cout<<"Your choise :1"<<std::endl;
    std::cout<<"Please choose converter:"<<std::endl;
    std::cout<<"\t1. Celsius to Fahrenheit"<<std::endl;
    std::cout<<"\t2. Fahrenheit to Celsius"<<std::endl;
    std::cout<<"\t3. Celsius to Kelvin"<<std::endl;
    std::cout<<"\t4. Kelvin to Celsius"<<std::endl;
    std::cout<<"\t5. Farenheit to Kelvin"<<std::endl;
    std::cout<<"\t6. Fahrenheit to Fahrenheit"<<std::endl;
  }
  std::cin>>option2;
  if(option2==3){
   std::cout<<"Enter value in Celsius: "<<std::endl;
   std::cin>>value;
   if(value<-273.15)throw std::string("Celsius value too low");
   output=value+Temperature::celsiusKelvinCoeff;
   std::cout<<"Temperature in Kelvin equals: "<< output<<std::endl;
  }
  
















  return 0;
}
