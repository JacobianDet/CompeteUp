#include <bits/stdc++.h>

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n,k;
    std::cin>>n>>k;
    int ctx = 0;
    for(int i=0;i<n;i++)
    {
        int t;
        std::cin>>t;
        if(!(t%k))
        ctx++;
    }
    std::cout<<ctx<<"\n";
    return 0;
}