#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

int res[100001], arr[100001];
std::map<int, std::vector<int> > MX;
std::vector<std::pair<int, int> > ZF;
std::map<int, int> ctz;

bool cmpx(std::pair<int, int> A, std::pair<int, int> B)
{
	return (A.second > B.second);
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
		int n;
		std::cin>>n;
		for(int i=0;i<n;i++)
		std::cin>>arr[i];
		for(int i=0;i<n;i++)
		MX[arr[i]].pb(i);
		std::set<int> FX;
		int g = 0;
		for(auto u : MX)
		{
			FX.insert(g);
			g++;
			ctz[u.first] = u.second.size();
			ZF.pb(mp(u.first, u.second.size()));
		}	
		std::sort(ZF.begin(), ZF.end(), cmpx);
		bool ok = 1;
		for(int i=0,j=(int)ZF.size();i<j;i++)
		{
			for(auto u : MX[ZF[i].first])
			{
				auto it = FX.upper_bound(i);
				if(it == FX.end())
				it = FX.begin();
				if(*it == i)
				{
					ok = 0;
					break;
				}
				int ix = *it;
				FX.erase(it);
				res[u] = ZF[ix].first;
				ctz[ZF[ix].first]--;
				if(ctz[ZF[ix].first] > 0)
				FX.insert(ix);	
			}	
			if(!ok)
			break;	
		}
		if(!ok)
		std::cout<<"No\n";
		else 
		{
			std::cout<<"Yes\n";
			for(int i=0;i<n;i++)
			std::cout<<res[i]<<" ";
			std::cout<<"\n";	
		}	
		MX.clear();
		ZF.clear();
		ctz.clear();
	}
	return 0;
}