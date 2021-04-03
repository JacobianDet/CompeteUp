#include <iostream>

int main(void)
{
    int n;
    std::cin>>n;
    int sx1 = 0, sx2 = 0;
    int ld = 0, man = 0;
    for(int i=0;i<n;i++)
    {
        int s,t;
        std::cin>>s>>t;
        sx1 += s;
        sx2 += t;
        if(sx1 - sx2 > ld)
        {
            ld = sx1 - sx2;
            man = 1;
        }
        else if(sx2 - sx1 > ld)
        {
            ld = sx2 - sx1;
            man = 2;
        }
    }
    std::cout<<man<<" "<<ld<<"\n";
    return 0;
}