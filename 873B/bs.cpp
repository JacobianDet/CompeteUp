#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	std::string s;
	std::cin>>s;
	int bal[n+1];
	memset(bal,0,sizeof(bal));
	for(int i=1;i<=n;i++)
	{
		if(s[i-1] == '0')
		bal[i] = bal[i-1]-1;	
		else bal[i] = bal[i-1]+1;
	}	
	int ans = 0;
	std::map<int, int> ind;
	for(int i=1;i<n+1;i++)
	{
		if(!ind[bal[i]] && bal[i])
		ind[bal[i]] = i;
		else ans = std::max(ans, i-ind[bal[i]]);	
	}	
	std::cout<<ans<<"\n";
	return 0;
}