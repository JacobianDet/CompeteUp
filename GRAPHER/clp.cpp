#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back

typedef long long ll;

std::vector<std::pair<ll, ll> > V;

bool cmpx(std::pair<ll, ll> A, std::pair<ll, ll> B)
{
	return (A.second < B.second);
}

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		ll x,w;
		std::cin>>x>>w;
		V.pb(mp(x-w, x+w));
	}	
	std::sort(V.begin(), V.end(), cmpx);
	int tot = 1, lx = 0;
	for(int i=1;i<n;i++)
	{
		if(V[i].first >= V[lx].second)
		{
			tot++;
			lx = i;
		}	
	}
	std::cout<<tot<<"\n";
	return 0;
}