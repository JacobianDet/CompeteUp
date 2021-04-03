#include <bits/stdc++.h>
#define pb push_back

std::vector<int> G[100001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}
	bool ok = 1;
	for(int i=1;i<=n;i++)
	{
		if(G[i].size() == 2)
		{
			ok = 0;
			break;
		}	
	}
	if(!ok)
	std::cout<<"NO\n";
	else std::cout<<"YES\n";
	return 0;	
}