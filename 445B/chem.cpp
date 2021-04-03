#include <bits/stdc++.h>

typedef long long ll;

int arr[51], sze[51];

class dsu
{
    public: int root(int x);
            void find_union(int x, int y);
};

int dsu::root(int x)
{
    return ((arr[x] == x) ? x : (arr[x] = root(arr[x])));
}

void dsu::find_union(int x, int y)
{
    int rx = root(x);
    int ry = root(y);
    if(rx == ry)
    return;
    if(sze[ry] > sze[rx])
    {
        int tmp = ry;
        ry = rx;
        rx = tmp;
    }
    sze[rx] += sze[ry];
    arr[ry] = rx;
    return;
}

int main(void)
{
    int n,m;
    std::cin>>n>>m;
    dsu T;
    for(int i=1;i<=n;i++)
    {
        arr[i] = i;
        sze[i] = 1;
    }
    for(int i=0;i<m;i++)
    {
        int s, d;
        std::cin>>s>>d;
        T.find_union(s, d);
    }
    std::set<int> Z;
    for(int i=1;i<=n;i++)
    Z.insert(T.root(i));
    ll ans = 1;
    for(std::set<int>::iterator it = Z.begin();it != Z.end();it++)
    ans *= (1LL<<(sze[*it] - 1));
    std::cout<<ans<<"\n";
    return 0;
}