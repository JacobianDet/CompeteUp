#include <bits/stdc++.h>

bool cond1[5000][5000], cond2[5000][5000];

int main(void)
{
	memset(cond1, 0, sizeof(cond1));
	memset(cond2, 0, sizeof(cond2));
	std::string s;
	std::cin>>s;
	for(int i=0,j=(int)s.size();i<j;i++)
	{
		int ctr=0;
		bool flag = 1;
		for(int k=i;k<j;k++)
		{
			if(s[k] == ')')
			ctr--;
			else ctr++;	
			if(ctr < 0)
			flag = 0;
			cond1[i][k] = flag;	
		}	
	}	
	for(int i=0,j=(int)s.size();i<j;i++)
	{
		int ctr=0;
		bool flag = 1;
		for(int k=i;k>=0;k--)
		{
			if(s[k] == '(')
			ctr--;
			else ctr++;	
			if(ctr < 0)
			flag = 0;
			cond2[k][i] = flag;	
		}	
	}	
	int ans = 0;	
	for(int i=0,j=(int)s.size();i<j;i++)
	{
		for(int k=i;k<j;k++)
		{
			if(cond1[i][k] && cond2[i][k] && !((k-i+1) & 1))
			ans++;	
		}	
	}	
	std::cout<<ans<<"\n";
	return 0;
}