#include <bits/stdc++.h>

int arr[31];

int main(void)
{
    int T;
    std::cin>>T;
    while(T--)
    {
        int n,m;
        std::cin>>n>>m;
        for(int i=1;i<=n;i++)
        std::cin>>arr[i];
        int ctx = 0;
        for(int i=1;i<=n;i++)
        {
            if(!(arr[i]%m))
            ctx++;
        }
        std::cout<<((1<<ctx) - 1)<<"\n";
    }
    return 0;
}