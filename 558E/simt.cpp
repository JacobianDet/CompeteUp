#include <bits/stdc++.h>
#define MV 100001

int seg[4*MV][26], lazy[4*MV][26];

std::string izod;

class segtree
{
	public: void build(int i, int s, int d);
			void update(int i, int s, int d, int qs, int qd, int j, int v);
			int query(int i, int s, int d, int qs, int qd, int j);
			void get(int i, int s, int d, int j);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i][izod[s-1] - 'a'] = 1;
		lazy[i][izod[s-1] - 'a'] = -1;
		return;
	}	
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	for(int j=0;j<26;j++)
	{	
		seg[i][j] = seg[2*i][j] + seg[2*i+1][j];
		lazy[i][j] = -1;
	}	
	return;
}

void segtree::update(int i, int s, int d, int qs, int qd, int j, int v)
{
	if(lazy[i][j] != -1)
	{
		seg[i][j] = (d-s+1)*lazy[i][j];
		if(s < d)
		{
			lazy[2*i][j] = lazy[i][j];
			lazy[2*i+1][j] = lazy[i][j];
		}	
		lazy[i][j] = -1;
	}	
	if(s > qd || d < qs)
	return;
	if(qs <= s && d <= qd)
	{
		seg[i][j] = (d-s+1)*v;
		if(s < d)
		{
			lazy[2*i][j] = v;
			lazy[2*i+1][j] = v;
		}	
		return;
	}
	int m = (s + d)/2;
	update(2*i, s, m, qs, qd, j, v);
	update(2*i+1, m+1, d, qs, qd, j, v);
	seg[i][j] = seg[2*i][j] + seg[2*i+1][j];
	return;	
}

int segtree::query(int i, int s, int d, int qs, int qd, int j)
{
	if(lazy[i][j] != -1)
	{
		seg[i][j] = (d-s+1)*lazy[i][j];
		if(s < d)
		{
			lazy[2*i][j] = lazy[i][j];
			lazy[2*i+1][j] = lazy[i][j];
		}	
		lazy[i][j] = -1;
	}	
	if(s > qd || d < qs)
	return 0;	
	if(qs <= s && d <= qd)
	return seg[i][j];
	int m = (s + d)/2;
	int p1 = query(2*i, s, m, qs, qd, j);
	int p2 = query(2*i+1, m+1, d, qs, qd, j);
	seg[i][j] = seg[2*i][j] + seg[2*i+1][j];	
	return (p1 + p2);
}

void segtree::get(int i, int s, int d, int j)
{
	if(lazy[i][j] != -1)
	{
		seg[i][j] = (d-s+1)*lazy[i][j];
		if(s < d)
		{
			lazy[2*i][j] = lazy[i][j];
			lazy[2*i+1][j] = lazy[i][j];
		}	
		lazy[i][j] = -1;
	}	
	if(!seg[i][j])
	return;
	if(s == d)
	{
		izod[s-1] = j + 'a';
		return;
	}	
	int m = (s + d)/2;
	get(2*i, s, m, j);
	get(2*i+1, m+1, d, j);
	seg[i][j] = seg[2*i][j] + seg[2*i+1][j];
	return;
}

int main(void)
{
	int n,q;
	std::cin>>n>>q;
	std::cin>>izod;
	segtree T;
	T.build(1, 1, n);
	while(q--)
	{
		int l,r,k;
		std::cin>>l>>r>>k;
		int cnt[26];
		memset(cnt, 0, sizeof(cnt));
		for(int i=0;i<26;i++)
		cnt[i] = T.query(1, 1, n, l, r, i);
		int cx = 0;
		if(k)
		cx = l;
		else cx = r;
		for(int i=0;i<26;i++)
		{
			if(!cnt[i])
			continue;
			T.update(1, 1, n, l, r, i, 0);
			if(k)
			{
				T.update(1, 1, n, cx, cx + cnt[i] - 1, i, 1);
				cx += cnt[i];
			}	
			else
			{
				T.update(1, 1, n, cx - cnt[i] + 1, cx, i, 1);
				cx -= cnt[i];
			}	
		}	
	}
	for(int i=0;i<26;i++)
	T.get(1, 1, n, i);
	std::cout<<izod<<"\n";
	return 0;		
}


