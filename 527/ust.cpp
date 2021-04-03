#include <bits/stdc++.h>

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    while(T--)
    {
        int n,k;
        std::cin>>n>>k;
        int mf = n/k;
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<mf;j++)
            std::cout<<(char)(i + 97);
        }
        if(n % k)
        {
            for(int i=0;i<(n%k);i++)
            std::cout<<"a";
            std::cout<<"\n";
        }
        else std::cout<<"\n";
    }
    return 0;
}