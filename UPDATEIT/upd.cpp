#include <bits/stdc++.h>
#define MV 10001

int BIT[MV];

class fentree
{
	public: void build(int n);
			void update(int i, int n, int val);
			int query(int i);
};

void fentree::build(int n)
{
	for(int i=1;i<=n;i++)
	BIT[i] = 0;	
}

void fentree::update(int i, int n, int val)
{
	for( ;i<=n;i+=(i & (-i)))
	BIT[i] += val;
	return;	
}

int fentree::query(int i)
{
	int sum = 0;
	for( ;i>0;i-=(i & (-i)))
	sum += BIT[i];
	return sum;
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
		int n,u;
		std::cin>>n>>u;
		fentree D;
		D.build(n);
		while(u--)
		{
			int l,r,val;
			std::cin>>l>>r>>val;
			l++;
			r++;
			D.update(l, n, val);
			if(r < n)
			D.update(r+1, n, -val);
		}	
		int q;
		std::cin>>q;
		while(q--)
		{
			int x;
			std::cin>>x;
			x++;
			std::cout<<D.query(x)<<"\n";
		}	
	}	
	return 0;
}