#include <bits/stdc++.h>

std::string s[100001];
std::map<int, int> ctx;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>s[i];
	for(int i=0;i<n;i++)
	{
		std::stack<int> Z;
		for(int j=0,k=(int)s[i].size();j<k;j++)
		{
			if(s[i][j] == '(')
			Z.push(j);
			else
			{
				if(!Z.empty() && (s[i][Z.top()] == '(' && s[i][j] == ')'))
				Z.pop();
				else Z.push(j);	
			}	
		}
		if(Z.empty())
		ctx[0]++;
		else
		{	
			int pind = -1;
			int ct = 0;
			bool ok = 1;
			while(!Z.empty())
			{
				int ind = Z.top();
				Z.pop();
				if((pind != -1) && (s[i][ind] != s[i][pind]))
				{
					ok = 0;
					break;
				}
				else
				{
					if(s[i][ind] == '(')
					ct++;
					else ct--;
					pind = ind;
				}
			}	
			if(ok)
			ctx[ct]++;
		}		
	}	
	int pv = 0;
	for(std::map<int, int>::iterator it = ctx.begin();it != ctx.end();it++)
	{
		if(it->first > 0)
		break;
		else
		{
			if(it->first == 0)
			pv += (it->second/2);
			else 
			{
				std::map<int, int>::iterator jt = ctx.find(-it->first);
				if(jt != ctx.end())
				pv += std::min(it->second, jt->second);
			}	
		}	
	}
	std::cout<<pv<<"\n";
	return 0;
}