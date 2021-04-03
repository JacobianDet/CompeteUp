#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
int main()
{
  system("cls");
  float x{315.887867667788997655554433443333};
  std::streamsize ss=std::cout.precision();
  std::cout.setf(std::ios_base::fixed);
  std::cout<<std::setprecision(12)<<x<<std::endl;
  std::cout.unsetf(std::ios_base::fixed);
  std::cout.setf(std::ios_base::scientific);
  std::cout<<x<<std::endl;
  std::cout.unsetf(std::ios_base::scientific);
  std::cout<<std::setprecision(ss)<<x<<std::endl;
  system("pause");
  return 0;
}
