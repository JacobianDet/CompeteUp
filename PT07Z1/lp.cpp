#include <bits/stdc++.h>
#define CHOR 10001

std::vector<std::vector<long long>> G(CHOR);
std::vector<long long> vis(CHOR, false);
long long max1 = 0,max2 = 0;

std::pair<long long, long long> dfs_dia(long long s)
{
    long long nmax1 = 0,nmax2 = 0,x = 0,y = 0;
    std::pair<long long, long long> p;
    vis[s] = true;
    for(long long i=0,j=G[s].size();i<j;i++)
    {
        if(!vis[G[s][i]])
        {
            p = dfs_dia(G[s][i]);
            x = p.first;
            y = p.second;
            if(i == 0)
            nmax1 = 1 + x;
            else if(1 + x > nmax1)
            {
                nmax2 = nmax1;
                nmax1 = 1 + x;
            }
            else if(1 + x <= nmax1 && 1 + x > nmax2)
            nmax2 = 1 + x;
            if(x + y > max1 + max2)
            {
                max1 = x;
                max2 = y;
            }
        }
    }
    if(s == 1 && max1 + max2 > nmax1 + nmax2)
    {
        nmax1 = max1;
        nmax2 = max2;
    }
    return std::make_pair(nmax1, nmax2);
}

int main(void)
{
    long long n,s,d;
    std::cin>>n;
    for(long long i=0;i<n-1;i++)
    {
        std::cin>>s>>d;
        G[s].push_back(d);
        G[d].push_back(s);
    }
    std::pair<long long, long long> dia = dfs_dia(1);
    std::cout<<dia.first + dia.second<<"\n";
    return 0;
}
