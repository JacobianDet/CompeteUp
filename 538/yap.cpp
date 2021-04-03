#include <bits/stdc++.h>

typedef long long ll;

ll arr[200001];

int main(void)
{
	int n,m,k;
	std::cin>>n>>m>>k;
	std::multiset<ll, std::greater<ll> > Z;
	std::multiset<ll> gt;
	for(int i=0;i<n;i++)
	{
		ll t;
		std::cin>>t;
		arr[i] = t;
		Z.insert(t);
	}
	ll sx = 0;
	while(Z.size() > n-k*m)
	{
		sx += *Z.begin();
		gt.insert(*Z.begin());
		Z.erase(Z.begin());
	}
	std::cout<<sx<<"\n";
	int cc = 0, ct = 0;
	for(int i=0;i<n;i++)
	{
		if(gt.find(arr[i]) != gt.end())
		{	
			gt.erase(gt.find(arr[i]));
			cc++;
		}	
		if(cc == m)
		{
			cc = 0;
			std::cout<<i+1<<" ";
			ct++;
		}
		if(ct == k-1)
		break;	
	}	
	std::cout<<"\n";
	return 0;	
}