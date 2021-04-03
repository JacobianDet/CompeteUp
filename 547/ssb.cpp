#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

int arr[1501];
std::map<int, std::vector<std::pair<int, int> > > MX;
std::vector<std::pair<int, int> > res;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	{	
		std::cin>>arr[i];
		arr[i] += arr[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		MX[arr[j] - arr[i-1]].pb(mp(j, i));	
	}
	int mk = 0, ms = 0;	
	for(auto it = MX.begin(); it != MX.end(); it++)
	{	
		std::sort((it->second).begin(), (it->second).end());
		int k = 1;
		auto xv = (it->second)[0];
		std::vector<std::pair<int, int> > trx;
		trx.pb(mp(xv.second, xv.first));
		for(auto v : it->second)
		{
			if((v.second > xv.first) && (v != xv))
			{
				k++;
				xv = v;
				trx.pb(mp(xv.second, xv.first));
			}	
		}
		if(k > mk)
		{
			mk = k;
			ms = it->first;
			res.clear();
			for(auto u : trx)
			res.pb(u);	
		}
	}
	std::cout<<mk<<"\n";
	for(auto u : res)
	std::cout<<u.first<<" "<<u.second<<"\n";
	return 0;
}	