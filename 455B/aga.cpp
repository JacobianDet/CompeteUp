#include <bits/stdc++.h>

std::string P[100001];

struct xtrie
{
    bool en;
    xtrie *next[26];
};

class triex
{
    public: xtrie* create(void);
            void insert(xtrie *root, std::string key);
            bool dfs_vis1(xtrie *root, int vx);
            bool dfs_vis2(xtrie *root, int vx);
            void delx(xtrie *root, std::string key);
            void freex(xtrie *root);
};

xtrie* triex::create(void)
{
    xtrie *vfx = new xtrie;
    vfx->en = 0;
    for(int i=0;i<26;i++)
    vfx->next[i] = NULL;
    return vfx;
}

void triex::insert(xtrie *root, std::string key)
{
    xtrie *vfx = root;
    for(int i=0,j=(int)key.size();i<j;i++)
    {
        int ind = key[i] - 'a';
        if(!vfx->next[ind])
        vfx->next[ind] = create();
        vfx = vfx->next[ind];
    }
    vfx->en = 1;
    return;
}

bool triex::dfs_vis1(xtrie *root, int vx)
{
    bool ax = 0;
    if(!(vx & 1))
    ax = 1;
    for(int i=0;i<26;i++)
    {
        if(root->next[i])
        {
            if(vx & 1)
            ax |= dfs_vis1(root->next[i], vx+1);
            else ax &= dfs_vis1(root->next[i], vx+1);
        }
    }
    return ax;
}

bool triex::dfs_vis2(xtrie *root, int vx)
{
    bool ax = 1;
    if(!(vx & 1))
    ax = 0;
    for(int i=0;i<26;i++)
    {
        if(root->next[i])
        {
            if(vx & 1)
            ax |= dfs_vis2(root->next[i], vx+1);
            else ax &= dfs_vis2(root->next[i], vx+1);
        }
    }
    return ax;
}

void triex::delx(xtrie *root, std::string key)
{
    xtrie *vfx = root;
    for(int i=0,j=(int)key.size();i<j;i++)
    {
        int ind = key[i] - 'a';
        if(vfx->next[ind])
        vfx = vfx->next[ind];
    }
    vfx->en = 0;
    return;
}

void triex::freex(xtrie *root)
{
    for(int i=0;i<26;i++)
    {
        if(root->next[i])
        freex(root->next[i]);
    }
    delete root;
    return;
}

int main(void)
{
    int n,k;
    std::cin>>n>>k;
    for(int i=0;i<n;i++)
    std::cin>>P[i];
    triex D;
    xtrie *root = D.create();
    for(int i=0;i<n;i++)
    D.insert(root, P[i]);
    bool ax1 = D.dfs_vis1(root, 1);
    bool ax2 = D.dfs_vis2(root, 1);
    if(ax1 && ax2)
    std::cout<<"First\n";
    else if(!ax1)
    std::cout<<"Second\n";
    else
    {
        if(k & 1)
        std::cout<<"First\n";
        else std::cout<<"Second\n";
    }
    D.freex(root);
    return 0;
}