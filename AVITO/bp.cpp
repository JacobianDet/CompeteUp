#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

typedef long long ll;

std::vector<std::pair<ll, ll> > A;
std::vector<std::pair<ll, ll> > B;

bool cmp(std::pair<ll, ll> a, std::pair<ll, ll> b)
{
	return (a.first < b.first);
}

ll merger(ll n, ll m)
{
	ll i=0, j=0, ans = 0;
	while(i != n && j != m)
	{
		if(A[i].first < B[j].first)
		{	
			ans += A[i].second;
			i++;
		}	
		else if(A[i].first > B[j].first)
		{	
			ans += B[j].second;
			j++;
		}
		else
		{
			ans += std::max(A[i].second, B[j].second);
			i++;
			j++;
		}		
	}
	while(i != n)
	{
		ans += A[i].second;
		i++;
	}	
	while(j != m)
	{
		ans += B[j].second;
		j++;
	}
	return ans;	
}

int main(void)
{
	ll n;
	std::cin>>n;
	for(ll i=0;i<n;i++)
	{
		ll v,c;
		std::cin>>v>>c;
		A.pb(mp(v, c));
	}	
	ll m;
	std::cin>>m;
	for(ll i=0;i<m;i++)
	{
		ll v,c;
		std::cin>>v>>c;
		B.pb(mp(v, c));
	}
	std::sort(A.begin(), A.end(), cmp);
	std::sort(B.begin(), B.end(), cmp);	
	std::cout<<merger(n, m)<<"\n";
	return 0;
}