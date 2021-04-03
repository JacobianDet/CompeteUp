#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

int arr[2001], sze[2001];

ll modexp(ll a, ll n)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res = ((res%MOD) * (a%MOD))%MOD;
		a = ((a%MOD) * (a%MOD))%MOD;
		n >>= 1;	
	}
	return res;
}

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
	if(sze[ry] > sze[rx])
	{
		int tmp = ry;
		ry = rx;
		rx = tmp;
	}	
	arr[ry] = rx;
	sze[rx] += sze[ry];
	return;
}

int main(void)
{
	int n,m,k;
	std::cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		arr[i] = i;
		sze[i] = 1;
	}
	dsu T;
	for(int i=1;i<=n-k+1;i++)
	{
		for(int j=0;j<(k>>1);j++)
		T.find_union(i+j, i+k-1-j);
	}	
	std::set<int> X;
	for(int i=1;i<=n;i++)
	X.insert(T.root(i));
	ll ans = modexp(m, (int)X.size())%MOD;
	std::cout<<ans<<"\n";
	return 0;
}