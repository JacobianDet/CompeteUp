#include <bits/stdc++.h>

int main(void)
{
    int T;
    std::cin>>T;
    for(int i=0;i<T;i++)
    {
        int n,t;
        std::cin>>n;
        std::map<int,int> z;
        for(int j=0;j<n;j++)
        {
            std::cin>>t;
            z[t]++;
        }
        for(std::map<int,int>::iterator it = z.begin(); it != z.end(); it++)
        {
            if(it->second == 1)
            {
                std::cout<<it->first<<"\n";
                break;
            }
        }
    }
    return 0;
}
