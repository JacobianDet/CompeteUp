#include <bits/stdc++.h>

int main(void)
{
    int T;
    std::cin>>T;
    for(int i=0;i<T;i++)
    {
        long long n;
        std::cin>>n;
        int t;
        std::map<int,std::vector<long long>> x;
        for(long long j=1;j<=n;j++)
        {
            std::cin>>t;
            x[t].push_back(j);
        }
        std::cout<<(x.begin()->second)[0]<<std::endl;
    }
    return 0;
}
