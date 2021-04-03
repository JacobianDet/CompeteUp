#include <iostream>
#include <cmath>

int main(void)
{
    int T;
    std::cin>>T;
    for(int i = 0;i<T;i++)
    {
        int n,v1,v2;
        std::cin>>n>>v1>>v2;
        float t1=(float)n*sqrt(2)/v1;
        float t2=(float)2*n/v2;
        if(t1 > t2)
        std::cout<<"Elevator"<<std::endl;
        else std::cout<<"Stairs"<<std::endl;
    }
    return 0;
}
