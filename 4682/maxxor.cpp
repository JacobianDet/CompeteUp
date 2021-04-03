#include <bits/stdc++.h>

int arr[100001];

struct trieman
{
    bool vfx;
    trieman *next[2];
};

class triex
{
    public: trieman* create(void);
            void insert(trieman *root, int val);
            int dfs_visx(trieman* root, int val);
            void delx(trieman* root, int val);
            void freex(trieman* root);
};

trieman* triex::create(void)
{
    trieman *vz = new trieman;
    vz->vfx = 0;
    for(int i=0;i<2;i++)
    vz->next[i] = NULL;
    return vz;
}

void triex::insert(trieman *root, int val)
{
    trieman *vz = root;
    for(int i=30;i>=0;i--)
    {
        int btx = 0;
        if(val & (1<<i))
        btx = 1;
        if(!vz->next[btx])
        vz->next[btx] = create();
        vz = vz->next[btx];
    }
    vz->vfx = 1;
    return;
}

int triex::dfs_visx(trieman *root, int val)
{
    int res = 0;
    trieman *vz = root;
    for(int i=30;i>=0;i--)
    {
        int btx = 0;
        if((val & (1<<i)))
        btx = 1;
        if(vz->next[btx ^ 1])
        {
            res += (1<<i);
            vz = vz->next[btx ^ 1];
        }
        else vz = vz->next[btx];    
    }
    return res;
}

void triex::delx(trieman *root, int val)
{
    trieman *vz = root;
    for(int i=30;i>=0;i--)
    {
        int btx = 0;
        if(val & (1<<i))
        btx = 1;
        if(vz->next[btx])
        vz = vz->next[btx];
    }
    vz->vfx = 0;
    return;
}

void triex::freex(trieman *root)
{
    trieman *vz = root;
    for(int i=0;i<2;i++)
    {
        if(vz->next[i])
        freex(vz->next[i]);
    }    
    delete vz;
    return;
}

int main(void)
{
    int T;
    std::cin>>T;
    while(T--)
    {
        int n;
        std::cin>>n;
        for(int i=1;i<=n;i++)
        {
            int vl;
            std::cin>>vl;
            arr[i] = arr[i-1] ^ vl;
        }
        triex D;
        trieman *root = D.create();
        for(int i=0;i<=n;i++)
        D.insert(root, arr[i]);
        int maxx = 0;
        for(int i=0;i<=n;i++)
        maxx = std::max(maxx, D.dfs_visx(root, arr[i]));
        std::cout<<maxx<<"\n";
        D.freex(root);
    }
    return 0;
}