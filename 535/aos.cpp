#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back

int arr[100001];
std::pair<int, int> Q[301];
int seg[400004], lazy[400004];

class segtree
{
    public: void build(int i, int s, int d);
            int merger(int left, int right);
            void update(int i, int s, int d, int qs, int qd, int val);
            int query(int i, int s, int d, int qs, int qd);
};

void segtree::build(int i, int s, int d)
{
    if(s == d)
    {
        seg[i] = arr[s];
        return;
    }
    int m = (s + d)/2;
    build(2*i, s, m);
    build(2*i+1, m+1, d);
    seg[i] = merger(seg[2*i], seg[2*i+1]);
    return;
}

int segtree::merger(int left, int right)
{
    return std::max(left, right);
}

void segtree::update(int i, int s, int d, int qs, int qd, int val)
{
    if(lazy[i] != 0)
    {
        seg[i] -= lazy[i];
        if(s < d)
        {
            lazy[2*i] += lazy[i];
            lazy[2*i+1] += lazy[i];
        }
        lazy[i] = 0;
    }
    if(qs > d || qd < s)
    return;
    if(qs <= s && d <= qd)
    {
        seg[i] -= val;
        if(s < d)
        {
            lazy[2*i] += val;
            lazy[2*i+1] += val;
        }
        return;
    }
    int m = (s + d)/2;
    update(2*i, s, m, qs, qd, val);
    update(2*i+1, m+1, d, qs, qd, val);
    seg[i] = merger(seg[2*i], seg[2*i+1]);
    return;
}

int segtree::query(int i, int s, int d, int qs, int qd)
{
    if(lazy[i] != 0)
    {
        seg[i] -= lazy[i];
        if(s < d)
        {
            lazy[2*i] += lazy[i];
            lazy[2*i+1] += lazy[i];
        }
        lazy[i] = 0;
    }
    if(qs > d || qd < s)
    return -100000000;
    if(qs <= s && d <= qd)
    return seg[i];
    int m = (s + d)/2;
    int p1 = query(2*i, s, m, qs, qd);
    int p2 = query(2*i+1, m+1, d, qs, qd);
    seg[i] = merger(seg[2*i], seg[2*i+1]);
    return merger(p1, p2);
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n,m;
    std::cin>>n>>m;
    for(int i=1;i<=n;i++)
    std::cin>>arr[i];
    for(int i=1;i<=m;i++)
    std::cin>>Q[i].first>>Q[i].second;
    int ans = -100000000;
    int idx = -1, cx = 0;
    segtree T;
    T.build(1, 1, n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int s = Q[j].first;
            int d = Q[j].second;
            if(i == s)
            {
                T.update(1, 1, n, s, d, 1);
                cx++;
            }
        }
        if(ans < T.query(1, 1, n, 1, n) - arr[i] + cx)
        {
            ans = std::max(ans, T.query(1, 1, n, 1, n) - arr[i] + cx);
            idx = i;
        }    
        for(int j=1;j<=m;j++)
        {
            int s = Q[j].first;
            int d = Q[j].second;
            if(i == d)
            {
                T.update(1, 1, n, s, d, -1);
                cx--;
            }
        }
    }
    std::vector<int> Z;
    std::cout<<ans<<"\n";
    for(int i=1;i<=m;i++)
    {
        if(Q[i].first <= idx && idx <= Q[i].second)
        Z.pb(i);
    }
    std::cout<<(int)Z.size()<<"\n";
    for(int i=0,j=(int)Z.size();i<j;i++)
    std::cout<<Z[i]<<" ";
    std::cout<<"\n";
    return 0;
}   