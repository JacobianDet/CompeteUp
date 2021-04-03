#include <bits/stdc++.h>
#define pb push_back

int ld[300001];

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	std::set<int> s;
	std::vector<int> eman;
	for(int i=1;i<=n;i++)
	s.insert(i);
	for(int i=0;i<m;i++)
	{
		int l,r,z;
		std::cin>>l>>r>>z;
		std::set<int>::iterator it = s.lower_bound(l);
		while(it != s.end())
		{
			int val = *it;
			if(val > r)
			break;	
			if(val != z)
			{
				ld[val] = z;
				eman.pb(val);
			}	
			it++;
		}	
		for(int j=0,k=(int)eman.size();j<k;j++)
		s.erase(eman[j]);
		eman.clear();
	}
	for(int i=1;i<=n;i++)
	std::cout<<ld[i]<<" ";
	std::cout<<"\n";
	return 0;	
}