#include <bits/stdc++.h>
#define MV 100001

struct mnx
{
    int mn,mx;
}seg[4*MV];

int arr[MV];

class segtree
{
    public: void build(int i, int s, int d);
            mnx merger(mnx left, mnx right);
            mnx query(int i, int s, int d, int qs, int qd);
};

void segtree::build(int i, int s, int d)
{
    if(s == d)
    {
        seg[i].mn = arr[s];
        seg[i].mx = arr[s];
        return;
    }
    int m = (s + d)/2;
    build(2*i, s, m);
    build(2*i+1, m+1, d);
    seg[i] = merger(seg[2*i], seg[2*i+1]);
    return;
}

mnx segtree::merger(mnx left, mnx right)
{
    mnx res;
    res.mn = std::min(left.mn, right.mn);
    res.mx = std::min(left.mx, right.mx);
    return res;
}

mnx segtree::query(int i, int s, int d, int qs, int qd)
{
    if(s > qd || d < qs)
    return {1000000000, 0};
    if(qs <= s && d <= qd)
    return seg[i];
    int m = (s + d)/2;
    mnx p1 = query(2*i, s, m, qs, qd);
    mnx p2 = query(2*i+1, m+1, d, qs, qd);
    return merger(p1, p2);
}

int main(void)
{
    int n,m,l;
    std::cin>>n>>m>>l;
    for(int i=1;i<=n;i++)
    std::cin>>arr[i];

}