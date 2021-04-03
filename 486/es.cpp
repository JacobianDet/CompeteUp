#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

int main(void)
{
	int k;
	std::cin>>k;
	std::vector<std::vector<int> > arr(k);
	for(int i=0;i<k;i++)
	{
		int n;
		std::cin>>n;
		for(int j=0;j<n;j++)
		{
			int t;
			std::cin>>t;
			arr[i].pb(t);
		}	
	}
	std::map<int, std::pair<int, int> > mze;
	std::map<int, std::pair<int, int> >::iterator it;
	bool ok = 0;
	for(int i=0;i<k;i++)
	{
		int s = 0;
		int n = (int)arr[i].size(); 
		for(int j=0;j<n;j++)
		s += arr[i][j];
		for(int j=0;j<n;j++)
		{
			it = mze.find(s-arr[i][j]);
			if(it != mze.end())
			{
				std::pair<int, int> p = it->second;
				if(p.first != i+1)
				{	
					std::cout<<"YES\n";
					std::cout<<i+1<<" "<<j+1<<"\n";
					std::cout<<p.first<<" "<<p.second<<"\n";
					ok = 1;
					break;
				}	
			}
			else 
			{
				std::pair<int, int> p = mp(i+1, j+1);
				mze[s-arr[i][j]] = p;
			}	
		}
		if(ok)
		break;	
	}
	if(!ok)
	std::cout<<"NO\n";
	return 0;	
}