#include <bits/stdc++.h>
#define mp std::make_pair

typedef long long ll;

std::pair<ll, ll> arr[200001];
ll pref[200001], hp[200001];

bool cmpx(std::pair<ll, ll> a, std::pair<ll, ll> b)
{
	return ((a.first == b.first) ? (a.second < b.second) : (a.first < b.first));
}

int bs2(int i, int n, ll val)
{
	int lo = i;
	int hi = n-1;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		if(pref[mid] - pref[i] >= val)
		hi = mid - 1;
		else lo = mid;	
	}
	return lo;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	ll h;
	std::cin>>n>>h;
	for(int i=0;i<n;i++)
	{
		ll x,y;
		std::cin>>x>>y;
		arr[i] = mp(x, y);
	}	
	std::sort(arr, arr+n, cmpx);
	for(int i=0;i<n;i++)
	{
		if(!i)
		{	
			pref[i] = 0;
			hp[i] = (arr[i].second - arr[i].first);
		}	
		else 
		{
			pref[i] = pref[i-1] + (arr[i].first - arr[i-1].second);
			hp[i] = hp[i-1] + (arr[i].second - arr[i].first);
		}		
	}	
	ll mdist = 0;
	for(int i=0;i<n;i++)
	{
		int pos = bs2(i, n, h);
		ll dist = 0;
		if(i)
		dist = (hp[pos] - hp[i-1]);
		else dist = hp[pos];
		dist += h;
		mdist = std::max(mdist, dist);
	}	
	std::cout<<mdist<<"\n";
	return 0;
}