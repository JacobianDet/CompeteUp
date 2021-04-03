#include <bits/stdc++.h>
#define ll long long
#define MV 200001
#define INF 10000000

typedef long long ll;

int k;
ll arr[MV][6];

struct klx
{
	ll p1[6], p2[6];
}seg[4*MV];

class segtree
{
	public: void build(int i, int s, int d);
			klx merger(klx left, klx right);
            klx update(int i, int s, int d, int x, ll px[6]);
			klx query(int i, int s, int d, int qs, int qd);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		for(int j=1;j<=k;j++)
        {
            seg[i].p1[j] = arr[j];
            seg[i].p2[j] = arr[j];
        }
		return;
	}	
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

klx segtree::merger(klx left, klx right)
{
	
}	

void segtree::update(int i, int s, int d, int x, ll px[6])
{
	if(s == d)
	{	
		for(int j=1;j<=k;j++)
        {
            seg[i].p1[j] = arr[j];
            seg[i].p2[j] = arr[j];
        }
		return;
	}	
	if(x > d || x < s)
	return;
	ll m = (s + d)/2;
	if(x <= m)
	update(2*i, s, m, x, px);
	else update(2*i+1, m+1, d, x, px);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

klx segtree::query(int i, int s, int d, int qs, int qd)
{
	if(s > qd || d < qs)
	{
        klx dx;
        for(int j=1;j<=k;j++)
        {
            dx.p1[j] = INF;
            dx.p2[j] = -INF;
        }
        return dx;
    }
	if(qs <= s && d <= qd)
	return seg[i];
	ll m = (s + d)/2;
	klx p1 = query(2*i, s, m, qs, qd);
	klx p2 = query(2*i+1, m+1, d, qs, qd);
	return merger(p1, p2);
}

int main(void)
{
    int n;
    std::cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        std::cin>>arr[i][j];
    }
    segtree T;
    T.build(1, 1, n);
    int q;
    std::cin>>q;
    while(q--)
    {
        int x;
        std::cin>>x;
        if(--x)
        {
            int l,r;
            std::cin>>l>>r;
            
        }
    }
}