#include <bits/stdc++.h>

typedef long long ll;

ll p2[33], p5[16];

void pfind(void)
{
    p2[0] = 1;
    for(int i=1;i<=32;i++)
    p2[i] = 2*p2[i-1];
    p5[0] = 1;
    for(int i=1;i<=15;i++)
    p5[i] = 5*p5[i-1];
    return;
}

int main(void)
{
    pfind();
    int T;
    std::cin>>T;
    while(T--)
    {
        ll n;
        std::cin>>n;
        ll ct2 = 0, ct5 = 0;
        for(int i=1;i<=32;i++)
        {
            if(p2[i] > n)
            break;
            ct2 += n/p2[i];
        }
        for(int i=1;i<=15;i++)
        {
            if(p5[i] > n)
            break;
            ct5 += n/p5[i];       
        }
        std::cout<<std::min(ct2, ct5)<<"\n";
    }
    return 0;
}