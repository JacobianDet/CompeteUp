#include <iostream>

int main(void)
{
    int T;
    std::cin>>T;
    while(T--)
    {
        int n;
        std::cin>>n;
        int cx = 0;
        for(cx=1;cx*cx <= n;cx++);
        std::cout<<(cx-1)<<"\n";
    }
    return 0;
}