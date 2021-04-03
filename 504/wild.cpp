#include <bits/stdc++.h>

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	std::string s,t;
	std::cin>>s>>t;
	bool isW = 0;
	int wp = -1;
	for(int i=0;i<n;i++)
	{
		if(s[i] == '*')
		{
			isW = 1;
			wp = i;
			break;
		}	
	}
	if(!isW)
	{
		if(s == t)
		std::cout<<"YES\n";
		else std::cout<<"NO\n";	
	}
	else
	{
		bool mc = 1;
		int mno = 0;
		if((wp > m) || (n-wp-1) > m)
		mc = 0;
		if(mc)
		{
			for(int i=0;i<wp;i++)
			{
				if(s[i] != t[i])
				{
					mc = 0;
					break;
				}	
				mno++;
			}
			if(mc)
			{	
				int p1 = n-1;
				int p2 = m-1;
				while((p1 > wp) && (p2 >= 0))
				{
					if(s[p1] != t[p2])
					{
						mc = 0;
						break;
					}	
					mno++;
					p1--;
					p2--;
				}
			}		
		}
		if(mno > m)
		mc = 0;	
		if(!mc)
		std::cout<<"NO\n";
		else std::cout<<"YES\n";	
	}
	return 0;
}