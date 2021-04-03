#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

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

int prev[1000001], bpref[1000001], apref[1000001], BIT[1000001];

class fentree
{
	public: void build(int n);
			int query(int i);
			void update(int i, int n);
};

void fentree::build(int n)
{
    for(int i=1;i<=n;i++)
    BIT[i] = 0;
    return;
}

int fentree::query(int i)
{
	int res = 0;
	for( ;i>0;i-=(i & (-i)))
	res += BIT[i];
	return res;
}

void fentree::update(int i, int n)
{
	for( ;i<=n;i+=(i & (-i)))
	BIT[i]++;
	return;	
}

int main(void)
{
	freopen("clat.in", "r", stdin);
	freopen("clat.txt", "w", stdout);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		memset(prev, 0, sizeof(prev));
		memset(apref, 0, sizeof(apref));
		memset(bpref, 0, sizeof(bpref));
		int n,k;
		std::cin>>n>>k;
		std::string s;
		std::cin>>s;
		int px = -1;
		for(int i=0;i<n;i++)
		{
			if(s[i] == 'B')
			{
				bpref[i+1]++;
				prev[i] = px;
				px = i;
			}
			else apref[i+1]++;
		}	
		for(int i=1;i<=n;i++)
		{	
			apref[i] += apref[i-1];
			bpref[i] += bpref[i-1];
		}	
		fentree Z;	
		Z.build(n);
		ll cst = 0;
		int ptr = px;
		while((px != -1) && (ptr != -1))
		{
			int ac = apref[px+1] - apref[ptr];
			int bc = bpref[px+1] - bpref[ptr];
			int corr = Z.query(px+1) - Z.query(ptr);
			std::cout<<ptr<<" "<<px<<" "<<corr<<"\n";
			if(bc - ac - corr > k)
			{
				cst = ((cst%MOD) + (modexp(2, ptr+1)%MOD))%MOD;
				Z.update(ptr+1, n);
				if(px == ptr)
				px = prev[px];	
			}	
			ptr = prev[ptr];	
		}	
		std::cout<<"Case #"<<t<<": "<<cst<<"\n";
	}
	return 0;
}