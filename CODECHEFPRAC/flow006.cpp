#include <iostream>

int main(void)
{
    int T;
    std::cin>>T;
    while(T--)
    {
        int n;
        std::cin>>n;
        int tmp = n;
        int dig = 0;
        while(tmp)
        {
            dig += (tmp%10);
            tmp /= 10;
        }
        std::cout<<dig<<"\n";
    }
    return 0;
}