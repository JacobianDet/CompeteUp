#include <bits/stdc++.h>

typedef long long ll;

ll BIT[1000001], arr[1000001];
std::map<ll, ll> fb;
std::map<ll, ll> fe;

class fentree
{
	public: void build(int n);
			void update(ll i, int n);
			ll query(int i);
};

void fentree::build(int n)
{
	for(int i=1;i<=n;i++)
	BIT[i] = 0;
	return;	
}

void fentree::update(ll i, int n)
{
	for( ;i<=n;i+=(i & (-i)))
	BIT[i]++;
	return;	
}

ll fentree::query(int i)
{
	ll sum = 0;
	for( ;i>0;i-=(i & (-i)))
	sum += BIT[i];
	return sum;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	for(int i=1;i<=n;i++)
	fb[arr[i]]++;
	fentree T;
	T.build(n);
	ll iv = 0;	
	for(int i=n;i>0;i--)
	{
		fb[arr[i]]--;
		iv += T.query(fb[arr[i]]);
		fe[arr[i]]++;
		T.update(fe[arr[i]], n);
	}
	std::cout<<iv<<"\n";
	return 0;
}