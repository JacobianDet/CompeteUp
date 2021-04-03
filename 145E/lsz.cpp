#include <bits/stdc++.h>
#define MV 1000001

struct vza
{
    int c4, c7, s47, s74;
}seg[4*MV];

int lazy[4*MV];
std::string S;

class segtree
{
    public: void build(int i, int s, int d);
            vza merger(vza left, vza right);
            void update(int i, int s, int d, int qs, int qd);
};

void segtree::build(int i, int s, int d)
{
    if(s == d)
    {
        if(S[s-1] == '4')
        {
            seg[i].c4 = 1;
            seg[i].c7 = 0;
        }
        else
        {
            seg[i].c4 = 0;
            seg[i].c7 = 1;
        }
        seg[i].s47 = 1;
        seg[i].s74 = 1;
        return;
    }
    int m = (s + d)/2;
    build(2*i, s, m);
    build(2*i+1, m+1, d);
    seg[i] = merger(seg[2*i], seg[2*i+1]);
    return;
}

vza segtree::merger(vza left, vza right)
{
    vza res;
    res.c4 = left.c4 + right.c4;
    res.c7 = left.c7 + right.c7;
    res.s47 = std::max(left.s47, std::max(right.s47, std::max(left.c4 + right.s47, left.s47 + right.c7)));
    res.s74 = std::max(left.s74, std::max(right.s74, std::max(left.c7 + right.s74, left.s74 + right.c4)));
    return res;
}

void segtree::update(int i, int s, int d, int qs, int qd)
{
    if(lazy[i])
    {
        int tmp = seg[i].c4;
        seg[i].c4 = seg[i].c7;
        seg[i].c7 = tmp;
        tmp = seg[i].s47;
        seg[i].s47 = seg[i].s74;
        seg[i].s74 = tmp;
        if(s < d)
        {
            lazy[2*i] = (lazy[2*i] + lazy[i])%2;
            lazy[2*i+1] = (lazy[2*i+1] + lazy[i])%2;
        }
        lazy[i] = 0;
    }
    if(qs > d || qd < s)
    return;
    if(qs <= s && d <= qd)
    {
        int tmp = seg[i].c4;
        seg[i].c4 = seg[i].c7;
        seg[i].c7 = tmp;
        tmp = seg[i].s47;
        seg[i].s47 = seg[i].s74;
        seg[i].s74 = tmp;
        if(s < d)
        {
            lazy[2*i] = (lazy[2*i] + 1)%2;
            lazy[2*i+1] = (lazy[2*i+1] + 1)%2;
        }
        return;
    }
    int m = (s + d)/2;
    update(2*i, s, m, qs, qd);
    update(2*i+1, m+1, d, qs, qd);
    seg[i] = merger(seg[2*i], seg[2*i+1]);
    return;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n,q;
    std::cin>>n>>q;
    std::cin>>S;
    segtree T;
    T.build(1, 1, n);
    while(q--)
    {
        std::string x;
        std::cin>>x;
        if(x == "count")
        std::cout<<seg[1].s47<<"\n";
        else
        {
            int l,r;
            std::cin>>l>>r;
            T.update(1, 1, n, l, r);
        }
    }
    return 0;
}