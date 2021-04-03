#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

typedef long long ll;

std::pair<int, int> E[100001];
int ecut[100001];
int arr[100001], rank[100001];
std::vector<std::pair<int, bool> > res;

bool cmpx(std::pair<int, bool> A, std::pair<int, bool> B)
{
	return (A.first < B.first);
}

struct qry
{
	int id, ty, a1, a2;
	ll tx;

	bool operator < (const qry& wx) const
	{
		return (tx > wx.tx);
	}
};

std::set<qry> MX;

class dsu
{
	public: int root(int x);
			void find_union(int x, int y); 
};

int dsu::root(int x)
{
	return (x == arr[x]) ? x : (arr[x] = root(arr[x]));
}

void dsu::find_union(int x, int y)
{
	int rx = root(x);
	int ry = root(y);
	if(rx == ry)
	return;
	if(rank[ry] > rank[rx])
	{
		int tmp = ry;
		ry = rx;
		rx = tmp;
	}	
	arr[ry] = rx;
	if(rank[rx] == rank[ry])
	rank[rx]++;	
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		std::cin>>s>>d;
		E[i] = mp(s, d);
	}	
	dsu T;
	for(int i=1;i<=n;i++)
	{
		arr[i] = i;
		rank[i] = 0;
	}
	int q;
	std::cin>>q;
	for(int i=0;i<q;i++)
	{
		int ty, a1, a2 = -1;
		ll tx;
		std::cin>>ty>>tx>>a1;
		if(ty == 2)
		std::cin>>a2;
		else 
		{
			a1--;
			ecut[a1]++;
		}	
		MX.insert({i, ty, a1, a2, tx});	
	}	
	for(int i=0;i<n-1;i++)
	{
		if(!ecut[i])
		T.find_union(E[i].first, E[i].second);	
	}
	for(auto u : MX)
	{	
		if(u.ty == 1)
		{	
			ecut[u.a1]--;
			if(!ecut[u.a1])
			T.find_union(E[u.a1].first, E[u.a1].second);
		}
		else
		{
			if(T.root(u.a1) == T.root(u.a2))
			res.pb(mp(u.id, 1));
			else res.pb(mp(u.id, 0));
		}	
	}
	std::sort(res.begin(), res.end(), cmpx);
	for(auto u : res)
	std::cout<<u.second<<"\n";
	return 0;	
}