#include <bits/stdc++.h>

typedef long long ll;

ll arr[200001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,k;
	std::cin>>n>>k;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	std::string s;
	std::cin>>s;
	ll ans = 0;
	std::multiset<ll, std::greater<ll> > X;
	X.insert(arr[0]);
	for(int i=0;i<n-1;i++)
	{
		if(s[i] != s[i+1])
		{
			int sz = k;
			while(!X.empty() && sz)
			{
				//std::cout<<*X.begin()<<" ";
				ans += *X.begin();
				X.erase(X.begin());
				sz--;
			}
			X.clear();
			X.insert(arr[i+1]);
		}
		else X.insert(arr[i+1]);
	}
	int sz = k;
	while(!X.empty() && sz)
	{
		//std::cout<<*X.begin()<<" ";
		ans += *X.begin();
		X.erase(X.begin());
		sz--;
	}	
	std::cout<<ans<<"\n";
	return 0;
}	
