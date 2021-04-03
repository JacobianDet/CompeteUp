#include <bits/stdc++.h>
#define mp std::make_pair

std::pair<int, int> obel[1001];
std::map<std::pair<int, int>, int> mpi;

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        std::cin>>x>>y;
        obel[i] = mp(x, y);
    }
    for(int i=0;i<n;i++)
    {
        int x,y;
        std::cin>>x>>y;
        for(int j=0;j<n;j++)
        mpi[mp(obel[j].first + x, obel[j].second + y)]++;
    }
    for(std::map<std::pair<int, int>, int>::iterator it = mpi.begin();it != mpi.end();it++)
    {
        if(it->second == n)
        {
            std::cout<<((it->first).first)<<" "<<((it->first).second)<<"\n";
            return 0;
        }
    }
    return 0;
}