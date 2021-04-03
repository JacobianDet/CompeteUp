#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

struct x3
{
    int s,d;
    ll w;
}E[200001];

int arr[200001], rank[200001];
std::map<ll, std::vector<int> > X;

class dsu
{
    public: int root(int x);
            void find_union(int x, int y);
};

int dsu::root(int x)
{
    return (x == arr[x]) ? x : (arr[x] = root(arr[x]));
}

void dsu::find_union(int x, int y)
{
    int rx = root(x);
    int ry = root(y);
    if(rx == ry)
    return;
    if(rank[rx] < rank[ry])
    {
        int tmp = rx;
        rx = ry;
        ry = tmp;
    }
    arr[ry] = rx;
    if(rank[rx] == rank[ry])
    rank[rx]++;
    return;
}

bool cmpx(x3 A, x3 B)
{
    return (A.w < B.w);
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n,m;
    std::cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int s,d;
        ll w;
        std::cin>>s>>d>>w;
        E[i] = {s, d, w};
    }    
    for(int i=1;i<=n;i++)
    {
        arr[i] = i;
        rank[i] = 0;
    }
    dsu T;
    std::sort(E, E+m, cmpx);
    for(int i=0;i<m;i++)
    X[E[i].w].pb(i);
    ll op = 0;
    for(std::map<ll, std::vector<int> >::iterator it = X.begin();it != X.end();it++)
    {
        int nunz = 0, unz = 0;
        std::vector<int> R((it->second).begin(), (it->second).end());
        for(int i=0,j=(int)R.size();i<j;i++)
        {
            int s = E[R[i]].s;
            int d = E[R[i]].d;
            if(T.root(s) == T.root(d))
            unz++;   
        }
        for(int i=0,j=(int)R.size();i<j;i++)
        {
            int s = E[R[i]].s;
            int d = E[R[i]].d;
            if(T.root(s) != T.root(d))
            {
                nunz++;
                T.find_union(s, d);
            }    
        }
        int tot = (int)R.size();
        op += (tot - unz - nunz);
    }
    std::cout<<op<<"\n";
    return 0;
}