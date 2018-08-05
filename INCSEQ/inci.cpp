#include <bits/stdc++.h>
#define MOD 5000000

typedef long long ll;

ll BIT[10001][52];
ll ct[10001][52];
int arr[10001];
std::set<ll> Z;
std::map<ll, int> cord;

class fentree
{
	public: void build(void);
			void update(int i, int sz, ll val);
			ll query(int i, int sz);
};

void fentree::build(void)
{
	memset(BIT, 0, sizeof(BIT));
	return;
}

void fentree::update(int i, int sz, ll val)
{
	for( ;i<=10000;i+=(i & (-i)))
	BIT[i][sz] = ((BIT[i][sz]%MOD) + (val%MOD))%MOD;
	return;	
}

ll fentree::query(int i, int sz)
{
	ll sum = 0;
	for( ;i>0;i-=(i & (-i)))
	sum = ((sum%MOD) + (BIT[i][sz]%MOD))%MOD;
	return sum;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,k;
	std::cin>>n>>k;
	for(int i=1;i<=n;i++)
	{	
		std::cin>>arr[i];
		Z.insert(arr[i]);
	}	
	int x = 0;
	for(std::set<ll>::iterator it = Z.begin();it != Z.end();it++)
	{
		x++;
		cord[*it] = x;
	}	
	for(int i=1;i<=n;i++)
	arr[i] = cord[arr[i]];	
	fentree T;
	T.build();
	for(int i=1;i<=n;i++)
	{
		if(!ct[arr[i]][1])
		{	
			ct[arr[i]][1] = 1;
			T.update(arr[i], 1, 1);
		}	
		for(int j=2;j<=k;j++)
		{
			ll ans = 0;
			ans = T.query(arr[i]-1, j-1);
			ll tx = ((ans%MOD) - (ct[arr[i]][j]%MOD) + MOD)%MOD;
			ct[arr[i]][j] = ((ct[arr[i]][j]%MOD) + (tx%MOD))%MOD;
			T.update(arr[i], j, tx);
		}	
	}	
	ll ans = T.query(10000, k);
	std::cout<<ans<<"\n";
	return 0;
}