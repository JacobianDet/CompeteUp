#include <bits/stdc++.h>
#define mp std::make_pair

std::pair<std::string, std::string> ZF[100001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		std::string w1,w2;
		std::cin>>w1>>w2;
		ZF[i] = mp(w1, w2);
	}
	for(int i=0;i<n;i++)
	{
		int ctr1[26], ctr2[26];
		memset(ctr1, 0, sizeof(ctr1));
		memset(ctr2, 0, sizeof(ctr2));
		for(int j=0,k=(int)ZF[i].first.size();j<k;j++)
		ctr1[ZF[i].first[j] - 'a']++;
		for(int j=0,k=(int)ZF[i].second.size();j<k;j++)
		ctr2[ZF[i].second[j] - 'a']++;
		bool ok = 1;	
		for(int j=0;j<26;j++)
		{
			if((ctr1[j] > ctr2[j]) || (!ctr1[j] && ctr2[j]) || (!ctr2[j] && ctr1[j]))
			{
				ok = 0;
				break;
			}	
		}
		if(ok)
		{
			int p1 = 0, p2 = 0;
			while(p1 < (int)ZF[i].first.size())
			{
				if(p2 < (int)ZF[i].second.size() && ZF[i].first[p1] == ZF[i].second[p2])
				{
					p1++;
					p2++;
				}	
				else if(p2)
				{
					if(ZF[i].second[p2-1] == ZF[i].second[p2])
					p2++;
					else
					{
						ok = 0;
						break;
					}	
				}	
				else
				{
					ok = 0;
					break;
				}
			}
			for( ;p2<(int)ZF[i].second.size();p2++)
			{
				if(ZF[i].second[p2] != ZF[i].first[p1-1])
				{
					ok = 0;
					break;
				}	
			}	
		}
		if(ok)
		std::cout<<"YES\n";
		else std::cout<<"NO\n";	
	}
	return 0;
}