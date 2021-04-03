#include <bits/stdc++.h>
#define pb push_back

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::string s;
	std::cin>>s;
	int n = (int)s.size();
	std::set<int> zo;
	std::set<int> on;
	for(int i=0;i<n;i++)
	{
		if(s[i] == '0')
		zo.insert(i);
		else on.insert(i);	
	}	
	std::vector<std::vector<int> > V;
	bool rex = 1;
	while(!zo.empty())
	{
		std::vector<int> Z;
		int z = *zo.begin();
		zo.erase(z);
		Z.pb(z);
		bool ok = 1;
		while(1)
		{
			std::set<int>::iterator it;
			if((it = on.upper_bound(z)) != on.end())
			{
				z = *it;
				on.erase(z);
				Z.pb(z);
				ok = 0;
			}	
			else break;
			if((it = zo.upper_bound(z)) != zo.end())
			{
				z = *it;
				zo.erase(z);
				Z.pb(z);
				ok = 1;
			}	
			else break;
		}
		if(ok)
		V.pb(Z);
		else 
		{
			rex = 0;
			break;
		}	
	}	
	if(zo.empty() && !on.empty())
	rex = 0;	
	if(!rex)
	std::cout<<"-1\n";
	else
	{
		std::cout<<(int)V.size()<<"\n";
		for(int i=0,m=(int)V.size();i<m;i++)
		{
			std::cout<<(int)V[i].size()<<" ";
			for(int j=0,k=(int)V[i].size();j<k;j++)
			std::cout<<(V[i][j] + 1)<<" ";
			std::cout<<"\n";	
		}
	}	
	return 0;
}