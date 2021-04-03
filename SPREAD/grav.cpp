#include <bits/stdc++.h>
#define MV 1000001

typedef long long ll;

ll BIT[MV];

class fentree
{
    public: void build(int n);
            void update(int i, int n, ll val);
            ll query(int i);
};

void fentree::build(int n)
{
    for(int i=1;i<=n;i++)
    BIT[i] = 0;
    return;
}

void fentree::update(int i, int n, ll val)
{
    for( ;i<=n;i+=(i & (-i)))
    BIT[i] += val;
    return;
}

ll fentree::query(int i)
{
    ll sum = 0;
    for( ;i>0;i-=(i & (-i)))
    sum += BIT[i];
    return sum;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
    int n,m;
    ll c;
    std::cin>>n>>m>>c;
    fentree T;
    T.build(n);
    while(m--)
    {
        char x;
        std::cin>>x;
        if(x == 'Q')
        {
            int p;
            std::cin>>p;
            std::cout<<(c+T.query(p))<<"\n";
        }
        else
        {
            int u,v;
            ll k;
            std::cin>>u>>v>>k;
            T.update(u, n, k);
            if(v < n)
            T.update(v+1, n, -k);
        }    
    }
    return 0;
}