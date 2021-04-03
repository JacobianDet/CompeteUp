#include <bits/stdc++.h>

int main(void)
{
    int q;
    std::cin>>q;
    while(q--)
    {
        int l1,r1,l2,r2;
        std::cin>>l1>>r1>>l2>>r2;
        if(l1 != r2)
        std::cout<<l1<<" "<<r2<<"\n";
        else std::cout<<r1<<" "<<l2<<"\n";
    }
    return 0;
}