#include <bits/stdc++.h>
#define MV 20001

int arr[MV];
int seg[4*MV];

class segtree
{
	public: void build(int i, int s, int d);
			int merger(int left, int right);
			int query(int i, int s, int d, int qs, int qd);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i] = arr[s-1];
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
	return left & right;
}

int segtree::query(int i, int s, int d, int qs, int qd)
{
	if(s > qd || d < qs)
	return ((1 << 30) - 1);
	if(qs <= s && d <= qd)
	return seg[i];
	int m = (s + d)/2;
	int p1 = query(2*i, s, m, qs, qd);
	int p2 = query(2*i+1, m+1, d, qs, qd);
	return merger(p1, p2);	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{
		int n,k;
		std::cin>>n>>k;
		for(int i=0;i<n;i++)
		std::cin>>arr[i];
		segtree D;
		D.build(1, 1, n);
		for(int i=0;i<n;i++)
		{
			int ans = ((1 << 30) - 1);
			int x = i-k;
			int y = i+k;
			if(x < 0)
			ans &= (D.query(1, 1, n, (i%n - k%n + n)%n + 1, n) & D.query(1, 1, n, 1, i+1));
			else ans &= D.query(1, 1, n, x+1, i+1);
			if(y >= n)
			ans &= (D.query(1, 1, n, i+1, n) & D.query(1, 1, n, 1, (i%n + k%n)%n + 1));
			else ans &= D.query(1, 1, n, i+1, y+1);
			std::cout<<ans<<" ";	
		}
		std::cout<<"\n";	
	}	
	return 0;
}