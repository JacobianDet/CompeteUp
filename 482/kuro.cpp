#include <bits/stdc++.h>
#define pb push_back
#define CHOR 100005

struct triex
{
    int mn;
    triex* next[2];
} *root[CHOR];

std::vector<int> dz[CHOR];
bool inarr[CHOR];

class trie
{
    public: triex* create();
            void add(int k, int u);
            int query(int x, int k, int s);
            void freex(triex* rx);
};

triex* trie::create(void)
{
    triex *vfx = new triex;
    vfx->mn = CHOR;
    for(int i=0;i<2;i++)
    vfx->next[i] = NULL;
    return vfx;
}

void trie::add(int k, int u)
{
    triex *vfx = root[k];
    vfx->mn = std::min(vfx->mn, u);
    for(int i=19;i>=0;i--)
    {
        if(!vfx->next[(u >> i) & 1])
        vfx->next[(u >> i) & 1] = create();
        vfx = vfx->next[(u >> i) & 1];
        vfx->mn = std::min(vfx->mn, u);
    }
    return;
}

int trie::query(int x, int k, int s)
{
    triex *vfx = root[k];
    if((x % k) || (vfx->mn + x > s))
    return -1;
    int res = 0;
    for(int i=19;i>=0;i--)
    {
        int v = (x >> i) & 1;
        if(vfx->next[(v ^ 1)] && (vfx->next[(v ^ 1)]->mn + x <= s))
        {
            res += ((v ^ 1) << i);
            vfx = vfx->next[(v ^ 1)];
        }
        else
        {
            res += (v << i);
            vfx = vfx->next[v];
        }
    }
    return res;
}

void trie::freex(triex* rx)
{
    for(int i=0;i<2;i++)
    {
        if(rx->next[i])
        freex(rx->next[i]);
    }
    delete rx;
    return;
}

int main(void)
{
    trie D;
    for(int i=1;i<CHOR;i++)
    {
        for(int j=i;j<CHOR;j+=i)
        dz[j].pb(i);
        root[i] = D.create();
    }
    int q;
    std::cin>>q;
    while(q--)
    {
        int t;
        std::cin>>t;
        if(--t)
        {
            int x,k,s;
            std::cin>>x>>k>>s;
            std::cout<<D.query(x, k, s)<<"\n";
        }
        else
        {
            int u;
            std::cin>>u;
            if(!inarr[u])
            {
                inarr[u] = 1;
                for(int i=0,j=(int)dz[u].size();i<j;i++)
                D.add(dz[u][i], u);
            }
        }
    }
    for(int i=1;i<CHOR;i++)
    D.freex(root[i]);
    return 0;
}