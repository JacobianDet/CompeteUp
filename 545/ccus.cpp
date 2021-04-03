#include <bits/stdc++.h>
#define pb push_back

int ctl[4], ace[4];

int main(void)
{
	int n;
	std::cin>>n;
	std::string s1, s2;
	std::cin>>s1>>s2;
	for(int i=0;i<n;i++)
	{
		if(s1[i] == '0' && s2[i] == '0')
		ctl[0]++;
		else if(s1[i] == '0' && s2[i] == '1')
		ctl[1]++;
		else if(s1[i] == '1' && s2[i] == '0')
		ctl[2]++;
		else ctl[3]++;	
	}
	int t = 0;
	bool ok1 = 0, ok2 = 0;
	for(int i=0;i<=ctl[0];i++)
	{
		t = n - 2*i - ctl[1] - ctl[3];
		ace[3] = ctl[1] + ctl[3] + i - n/2;
		if((0 <= t && t <= (ctl[1] + ctl[2])) && (0 <= ace[3] && ace[3] <= ctl[3]))
		{
			ace[0] = i;
			ok1 = 1;
			break;
		}	
	}
	if(ok1)
	{
		for(int i=0;i<=ctl[1];i++)
		{
			ace[2] = t - i;
			if(0 <= ace[2] && ace[2] <= ctl[2])
			{
				ace[1] = i;
				ok2 = 1;
				break;
			}	
		}
	}	
	if(!ok1 || !ok2)
	std::cout<<"-1\n";	
	else
	{
		std::vector<int> res;
		for(int i=0;i<n;i++)
		{
			if(s1[i] == '0' && s2[i] == '0')
			{
				if(ace[0] > 0)
				{
					ace[0]--;
					res.pb(i);
				}		
			}	
			else if(s1[i] == '0' && s2[i] == '1')
			{
				if(ace[1] > 0)
				{
					ace[1]--;
					res.pb(i);
				}
			}
			else if(s1[i] == '1' && s2[i] == '0')
			{
				if(ace[2] > 0)
				{
					ace[2]--;
					res.pb(i);
				}
			}
			else
			{
				if(ace[3] > 0)
				{
					ace[3]--;
					res.pb(i);
				}	
			}
		}
		for(auto u : res)
		std::cout<<u + 1<<" ";
		std::cout<<"\n";
	}
	return 0;		
}