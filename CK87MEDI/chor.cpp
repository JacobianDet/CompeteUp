#include <bits/stdc++.h>

int main(void)
{
    int T;
    std::cin>>T;
    for(int i=0;i<T;i++)
    {
        int n,k;
        std::cin>>n>>k;
        std::vector<int> ar(n);
        for(int j=0;j<n;j++)
        std::cin>>ar[j];
        std::sort(ar.begin(),ar.end());
        std::cout<<ar[k+(n-k)/2]<<"\n";
    }
    return 0;
}
