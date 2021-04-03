#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

typedef long long ll;

std::map<int, int> ctx;
std::vector<ll> Z;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{
		ctx.clear();
		Z.clear();
		int n;
		std::cin>>n;
		for(int i=0;i<n;i++)
		{
			int t;
			std::cin>>t;
			ctx[t]++;
		}	
		bool ok = 0;
		for(auto xz : ctx)
		{
			if(xz.second >= 4)
			{
				std::cout<<xz.first<<" "<<xz.first<<" "<<xz.first<<" "<<xz.first<<"\n";
				ok = 1;
				break;
			} 
			else if(xz.second >= 2 && xz.second < 4)
			Z.pb(xz.first);
		}
		if(!ok)
		{
			std::pair<ll, ll> fmin = mp(Z[0], Z[1]);
			for(int i=1,j=(int)Z.size();i<j-1;i++)
			{
				std::pair<ll, ll> zmin = mp(Z[i], Z[i+1]);
				if((fmin.first + fmin.second) * (fmin.first + fmin.second) * (zmin.first * zmin.second) > (zmin.first + zmin.second) * (zmin.first + zmin.second) * (fmin.first * fmin.second))
				fmin = zmin;	
			}	
			std::cout<<fmin.first<<" "<<fmin.first<<" "<<fmin.second<<" "<<fmin.second<<"\n";
		}
	}
	return 0;
}