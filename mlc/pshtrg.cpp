#include <bits/stdc++.h>
#define pb push_back
#define MV 100001
#define REQ 50

typedef long long ll;

struct trix
{
    ll peri;
    std::vector<int> vx;
}seg[4*MV];

int arr[MV];

class segtree
{
    public: void build(int i, int s, int d);
            trix merger(trix left, trix right);
            void update(int i, int s, int d, int x, int y);
            trix query(int i, int s, int d, int qs, int qd);
};

void segtree::build(int i, int s, int d)
{
    if(s == d)
    {
        seg[i].vx.clear();
        seg[i].vx.pb(arr[s]);
        seg[i].peri = 0;
        return;
    }
    int m = (s + d)/2;
    build(2*i, s, m);
    build(2*i+1, m+1, d);
    seg[i] = merger(seg[2*i], seg[2*i+1]);
    return;
}

trix segtree::merger(trix left, trix right)
{
    trix res;
    res.vx.clear();
    res.peri = 0;
    int n1 = (int)left.vx.size(), n2 = (int)right.vx.size();
    int i=0, j=0, n3 = 0;
    while(i != n1 && j != n2 && n3 < REQ)
    {
        if(left.vx[i] > right.vx[j])
        {
            res.vx.pb(left.vx[i]);
            i++;
            n3++;
        }
        else if(left.vx[i] < right.vx[j])
        {
            res.vx.pb(right.vx[j]);
            j++;
            n3++;
        }
        else
        {
            if(n3 == REQ-1)
            {
                res.vx.pb(left.vx[i]);
                i++;
                n3++;
            }
            else
            {
                res.vx.pb(left.vx[i]);
                res.vx.pb(right.vx[j]);
                j++;
                i++;
                n3+=2;
            }
        }
    }
    while(i != n1 && n3 < REQ)
    {
        res.vx.pb(left.vx[i]);
        i++;
        n3++;
    }
    while(j != n2 && n3 < REQ)
    {
        res.vx.pb(right.vx[j]);
        j++;
        n3++;
    }
    if(n3 >= 3)
    {
        for(i=0;i<n3-2;i++)
        {
            int x = res.vx[i];
            int y = res.vx[i+1];
            int z = res.vx[i+2];
            if((1LL*z + 1LL*y) > 1LL*x)
            {
                res.peri = (1LL*x + 1LL*y + 1LL*z);
                break;
            }
        }
    }
    return res;
}

void segtree::update(int i, int s, int d, int x, int y)
{
    if(s == d)
    {
        seg[i].vx.clear();
        seg[i].vx.pb(y);
        arr[x] = y;
        return;
    }
    int m = (s + d)/2;
    if(x <= m)
    update(2*i, s, m, x, y);
    else update(2*i+1, m+1, d, x, y);
    seg[i] = merger(seg[2*i], seg[2*i+1]);
    return;
}

trix segtree::query(int i, int s, int d, int qs, int qd)
{
    trix ans;
    ans.vx.clear();
    ans.peri = 0;
    if(s > qd || d < qs)
    return ans;
    if(qs <= s && d <= qd)
    return seg[i];
    int m = (s + d)/2;
    trix p1 = query(2*i, s, m, qs, qd);
    trix p2 = query(2*i+1, m+1, d, qs, qd);
    return merger(p1, p2);
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
    int n,q;
    std::cin>>n>>q;
    for(int i=1;i<=n;i++)
    std::cin>>arr[i];
    segtree T;
    T.build(1, 1, n);
    while(q--)
    {
        int t;
        std::cin>>t;
        if(--t)
        {
            int l,r;
            std::cin>>l>>r;
            std::cout<<(T.query(1, 1, n, l, r).peri)<<"\n";
        }
        else
        {
            int x,y;
            std::cin>>x>>y;
            T.update(1, 1, n, x, y);
        }
    }
    return 0;
}
