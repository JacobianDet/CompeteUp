#include <bits/stdc++.h>
#define pb push_back

std::vector<int> X[100001];
bool mark[100001];

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n,m;
    std::cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x;
        std::cin>>x;
        X[x].pb(i);
    }
    int sz = 100001;
    for(int i=1;i<=n;i++)
    sz = std::min(sz, (int)X[i].size());
    for(int i=0;i<sz;i++)
    {
        int mx = 0;
        for(int j=1;j<=n;j++)
        mx = std::max(mx, X[j][i]);
        mark[mx] = 1;
    }
    for(int i=1;i<=m;i++)
    std::cout<<mark[i];
    std::cout<<"\n";
    return 0;
}