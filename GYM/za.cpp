#include <bits/stdc++.h>
#define MV 100001

std::map<int, int> seg[4*MV];
int arr[MV];

class segtree
{
	public: void build(int i, int s, int d);
			std::map<int, int> merger(std::map<int, int> left, std::map<int, int> right);
			void update(int i, int s, int d, int x, int v);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i].clear();
		seg[i][arr[s]] = 1;
		return;
	}	
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i].clear();
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

std::map<int, int> segtree::merger(std::map<int, int> left, std::map<int, int> right)
{
	std::map<int, int> res;
	for(std::map<int, int>::iterator it = left.begin();it != left.end();it++)
	res[it->first] += it->second;
	for(std::map<int, int>::iterator it = right.begin();it != right.end();it++)
	res[it->first] += it->second;	
	return res;
}

void segtree::update(int i, int s, int d, int x, int v)
{
	if(s == d)
	{
		seg[i].erase(arr[s]);
		seg[i][v] = 1;
		return;
	}	
	int m = (s + d)/2;
	if(x <= m)
	{	
		update(2*i, s, m, x, v);
		seg[i][v]++;
		if(seg[i][arr[x]])
		seg[i][arr[x]]--;
		if(!seg[i][arr[x]])
		seg[i].erase(arr[x]);	
	}	
	else 
	{
		update(2*i+1, m+1, d, x, v);
		seg[i][v]++;
		if(seg[i][arr[x]])
		seg[i][arr[x]]--;
		if(!seg[i][arr[x]])
		seg[i].erase(arr[x]);		
	}	
	return;	
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
		int n,q;
		std::cin>>n>>q;
		for(int i=1;i<=n;i++)
		std::cin>>arr[i];
		segtree D;
		D.build(1, 1, n);
		while(q--)
		{
			int x;
			std::cin>>x;
			if(--x)
			std::cout<<seg[1].size()<<"\n";
			else
			{
				int p,v;
				std::cin>>p>>v;
				D.update(1, 1, n, p, v);
				arr[p] = v;
			}	
		}
	}
	return 0;
}