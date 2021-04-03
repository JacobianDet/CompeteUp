#include <bits/stdc++.h>

typedef long long ll;

ll modexp(ll a, ll n)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res = ((res%100) * (a%100))%100;
		a = ((a%100) * (a%100))%100;
		n >>= 1;	
	}
	return res;
}

ll arr[100001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,q;
	std::cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		std::cin>>arr[i];
		arr[i] += arr[i-1];
	}	
	while(q--)
	{
		int l1, r1, l2, r2, c;
		std::cin>>l1>>r1>>l2>>r2>>c;
		ll p1 = (arr[r1] - arr[l1-1]);
		ll p2 = (arr[r2] - arr[l2-1]);
		if((p2 == 0) || (p1 == 0 || p1 == 1) || ((p2 == 1) && (p1 >= 2 && p1 <= 9)) || ((p2 == 2) && (p1 >= 2 && p1 <= 3)) || ((p2 == 3) && (p1 == 2)))
		std::cout<<"No -1\n";
		else
		{
			ll zx = modexp((arr[r1] - arr[l1-1]), (arr[r2] - arr[l2-1]))%100;
			if((zx/10) != c)
			std::cout<<"No "<<(zx/10)<<"\n";	
			else std::cout<<"Yes "<<c<<"\n";
		}	
	}
	return 0;
}