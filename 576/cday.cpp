#include <bits/stdc++.h>

int arr[100001];
int seg[400004];

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
	return std::min(left, right);
}

int segtree::query(int i, int s, int d, int qs, int qd)
{
	if(s > qd || d < qs)
	return 10000000001;
	else if(qs <= s && d <= qd)
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
	int n,x,y;
	std::cin>>n>>x>>y;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	int pos = -1;
	segtree T;
	T.build(1, 1, n);
	for(int i=1;i<=n;i++)
	{
		bool ok1 = 0, ok2 = 0;
		if(x && (i > 1) && (arr[i] < T.query(1, 1, n, std::max(1, i-x), i-1)))
		ok1 = 1;
		else if(!x || (i==1))
		ok1 = 1;	
		if(y && (i < n) && (arr[i] < T.query(1, 1, n, i+1, std::min(n, i+y))))
		ok2 = 1;	
		else if(!y || (i==n))
		ok2 = 1;	
		if(ok1 && ok2)
		{
			pos = i;
			break;
		}
	}
	std::cout<<pos<<"\n";
	return 0;	
}