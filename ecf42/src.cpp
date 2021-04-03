#include <bits/stdc++.h>
#define pb push_back

int main(void)
{
	int n,a,b;
	std::cin>>n>>a>>b;
	std::string s;
	std::cin>>s;
	std::vector<int> cm;
	for(int i=0;i<n;i++)
	{
		if(s[i] == '.')
		cm.pb(i);	
	}	
	std::set<int> sz[2];
	for(int i=0,j=(int)cm.size();i<j;i++)
	{
		if(a > b && a > 0)
		{	
			if((i > 0 && (sz[0].find(cm[i]-1) == sz[0].end())) || !i)
			{	
				sz[0].insert(cm[i]);
				a--;
			}
			else if(b > 0)
			{
				sz[1].insert(cm[i]);
				b--;
			}	
		}	
		else if(b >= a && b > 0)
		{
			if((i > 0 && (sz[1].find(cm[i]-1) == sz[1].end())) || !i)
			{	
				sz[1].insert(cm[i]);
				b--;
			}
			else if(a > 0)
			{
				sz[0].insert(cm[i]);
				a--;
			}	
		}	
	}
	std::cout<<sz[0].size() + sz[1].size()<<"\n";
	return 0;	
}