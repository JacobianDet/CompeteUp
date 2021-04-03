#include <bits/stdc++.h>
#define pb push_back

int main(void)
{
	int n;
	std::cin>>n;
	std::string s,t;
	std::cin>>s>>t;
	int ctx1[26], ctx2[26];
	memset(ctx1, 0, sizeof(ctx1));
	memset(ctx2, 0, sizeof(ctx2));
	for(int i=0;i<n;i++)
	{
		ctx1[s[i] - 'a']++;
		ctx2[t[i] - 'a']++;
	}	
	bool ok = 0;
	for(int i=0;i<26;i++)
	{
		if(ctx1[i] != ctx2[i])
		{
			ok = 1;
			break;
		}	
	}	
	if(ok)
	std::cout<<"-1\n";
	else
	{
		int vc = 0;
		std::vector<int> mv;
		for(int i=n-1;i>=0;i--)
		{
			int pos = -1;
			 for(int j=i;j>=0;j--)
			 {
			 	if(s[j] == t[i])
			 	{
			 		pos = j;
			 		break;
			 	}	
			 }	
			 for(int j=pos;j<i;j++)
			 {
			 	vc++;
			 	mv.pb(j+1);
			 	std::swap(s[j], s[j+1]);
			 }	
		}
		if(vc > 10000)
		std::cout<<"-1\n";
		else
		{
			std::cout<<vc<<"\n";
			for(int i=0;i<vc;i++)
			std::cout<<mv[i]<<" ";
			std::cout<<"\n";	
		}	
	}
	return 0;	
}