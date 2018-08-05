#include <bits/stdc++.h>
#define MV 100001

typedef long long ll;

ll BIT1[MV], BIT2[MV];

class fentree
{
	public: void build(int n);
			ll query(int i);
			ll query(ll BIT[], int i);
			void update(int l, int r, int n, ll v);
			void update(ll BIT[], int i, int n, ll v);
};

void fentree::build(int n)
{
	for(int i=1;i<=n;i++)
	{
		BIT1[i] = 0;
		BIT2[i] = 0;
	}	
	return;
}

ll fentree::query(int i)
{
	return query(BIT1, i)*i - query(BIT2, i);
}

ll fentree::query(ll BIT[], int i)
{
	ll sum = 0;
	for( ;i>0;i-=(i & (-i)))
	sum += BIT[i];
	return sum;	
}

void fentree::update(int l, int r, int n, ll v)
{
	update(BIT1, l, n, v);
	if(r < n)
	update(BIT1, r+1, n, -v);
	update(BIT2, l, n, v*(l-1));
	if(r < n)
	update(BIT2, r+1, n, -v*r);
	return;	
}

void fentree::update(ll BIT[], int i, int n, ll v)
{
	for( ;i<=n;i+=(i & (-i)))
	BIT[i] += v;
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
		int n,c;
		std::cin>>n>>c;
		fentree D;
		D.build(n);
		while(c--)
		{
			int x;
			std::cin>>x;
			if(x)
			{
				int l,r;
				std::cin>>l>>r;
				std::cout<<(D.query(r) - D.query(l-1))<<"\n";
			}	
			else 
			{
				int l,r;
				ll val;
				std::cin>>l>>r>>val;
				D.update(l, r, n, val);
			}	
		}	
	}
	return 0;	
}