#include <iostream>
#include <iomanip>

int main(void)
{
    int x;
    double y;
    std::cin>>x>>y;
    std::cout.setf(std::ios_base::fixed);
    if(x%5 || y < (double)x + 0.5)
    std::cout<<std::setprecision(2)<<y<<"\n";
    else std::cout<<std::setprecision(2)<<(y - x - 0.50)<<"\n";
    std::cout.unsetf(std::ios_base::fixed);
    return 0;
}
