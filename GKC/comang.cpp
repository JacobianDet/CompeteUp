#include <bits/stdc++.h>

int main(void)
{
	freopen("Q1.in","r",stdin);
	freopen("Q1.txt","w",stdout);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n;
		std::cin>>n;
		std::string s1, s2;
		std::cin>>s1>>s2;
		int ctx = 0;
		for(int i=0;i<n;i++)
		{
			int ctr1[26];
			memset(ctr1, 0, sizeof(ctr1));
			for(int j=1;j<=n-i;j++)
			{
				ctr1[(s1[i+j-1] - 65)]++;
				int p1 = 0, p2 = 0;
				int ctr2[26];
				memset(ctr2, 0, sizeof(ctr2));
				bool xok = 0;
				while(p2 < j)
				{	
					ctr2[(s2[p2] - 65)]++;
					p2++;
				}	
				while(p2 < n)
				{
					bool ok = 1;
					for(int k=0;k<26;k++)
					{
						if(ctr1[k] != ctr2[k])
						{
							ok = 0;
							break;
						}	
					}	
					if(ok)
					{
						xok = 1;
						break;
					}	
					else
					{
						ctr2[(s2[p2] - 65)]++;
						ctr2[(s2[p1] - 65)]--;
						p2++;
						p1++;
					}
				}
				if(!xok)
				{
					xok = 1;	
					for(int k=0;k<26;k++)
					{
						if(ctr1[k] != ctr2[k])
						{
							xok = 0;
							break;
						}	
					}
				}	
				if(xok)
				ctx++;	
			}	
		}
		std::cout<<"Case #"<<t<<": "<<ctx<<"\n";	
	}
	return 0;
}