#include <bits/stdc++.h>

typedef long long ll;

int arr[100001];

struct sextrie
{
    bool vzx;
    ll cw;
    sextrie *next[2];
};

class trix
{
    public: sextrie* create(void);
            void insert(sextrie* root, int val);
            ll dfs_visit(sextrie *root, int val, int k, int i);
            void delx(sextrie* root, int val);
            void freex(sextrie* root);
};

sextrie* trix::create(void)
{
    sextrie *vfx = new sextrie;
    vfx->vzx = 0;
    vfx->cw = 0;
    for(int i=0;i<2;i++)
    vfx->next[i] = NULL;
    return vfx;
}

void trix::insert(sextrie *root, int val)
{
    sextrie *vfx = root;
    for(int i=30;i>=0;i--)
    {
        int btx = 0;
        if(val & (1<<i))
        btx = 1;
        if(!vfx->next[btx])
        vfx->next[btx] = create();
        vfx->cw++;
        vfx = vfx->next[btx];
    }
    vfx->vzx = 1;
    return;
}

ll trix::dfs_visit(sextrie *root, int val, int k, int i)
{
    ll ctx = 0;
    int kbit = 0, vbit = 0;
    if(k & (1<<i))
    kbit = 1;    
    if(val & (1<<i))
    vbit = 1;    
    for(int j=0;j<2;j++)
    {
        if(root->next[j])
        {
            if((j ^ vbit) < kbit)
            ctx += (root->next[j]->cw);
            else if((j ^ vbit) == kbit)
            ctx += dfs_visit(root->next[j], val, k, i-1);    
        }    
    }   
    return ctx;
}

void trix::delx(sextrie *root, int val)
{
    sextrie *vfx = root;
    for(int i=30;i>=0;i--)
    {
        int btx = 0;
        if(val & (1<<i))
        btx = 1;
        if(vfx->next[btx])
        vfx->cw--;    
        vfx = vfx->next[btx];
    }
    vfx->vzx = 0;
    return;
}

void trix::freex(sextrie *root)
{
    for(int i=0;i<2;i++)
    {
        if(root->next[i])
        freex(root->next[i]);
    }
    delete root;
    return;
}

int main(void)
{
    int T;
    std::cin>>T;
    while(T--)
    {
        int n,k;
        std::cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            int vl;
            std::cin>>vl;
            arr[i] = arr[i-1] ^ vl;
        }
        trix Z;
        sextrie *root = Z.create();
        ll tc = 0;
        for(int i=0;i<=n;i++)
        {
            tc += Z.dfs_visit(root, arr[i], k, 30);
            Z.insert(root, arr[i]);
        }
        std::cout<<tc<<"\n";
        Z.freex(root);
    }
    return 0;
}
