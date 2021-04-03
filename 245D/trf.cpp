#include <bits/stdc++.h>
#define mp std::make_pair

//SOURCE CODE BY usaxena95 

typedef long long ll;

ll pref[100001];
std::pair<ll, ll> pts[100001];

bool cmpx(std::pair<ll, ll> A, std::pair<ll, ll> B)
{
	return ((A.first < B.first) || ((A.first == B.first) && (A.second < B.second)));
}

ll dist(std::pair<ll, ll> A, std::pair<ll, ll> B)
{
	return ((A.first - B.first) * (A.first - B.first)) + ((A.second - B.second) * (A.second - B.second));
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	{
		std::cin>>pref[i];
		pref[i] += pref[i-1];
		pts[i] = mp(i, pref[i]);
	}	
	std::sort(pts+1, pts+n+1, cmpx);
	ll ans = 1000000000000001;
	std::set<std::pair<ll, ll> > X;
	int j=1;
	X.insert(mp(pref[1], 1));
	for(int i=2;i<=n;i++)
	{
		while((j < i) && (((i - j) * (i - j)) >= ans))
		{
			X.erase(mp(pref[j], j));
			j++;
		}	
		ll d = sqrt(double(ans));
		for(std::set<std::pair<ll, ll> >::iterator it = X.lower_bound(mp(pts[i].second - d, 0)); it != X.end(); it++)
		{
			if(it->first <= pts[i].second + d)
			ans = std::min(ans, dist(mp(it->second, it->first), pts[i]));
			else break;	
		}	
		X.insert(mp(pref[i], i));
	}	
	std::cout<<ans<<"\n";
	return 0;
}