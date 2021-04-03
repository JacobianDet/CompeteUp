#include <bits/stdc++.h>

int pref[100001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,q;
	std::cin>>n>>q;
	std::string s;
	std::cin>>s;
	for(int i=2;i<=n;i++)
	{
		if(s[i-1] == 'C' && s[i-2] == 'A')
		pref[i]++;
		pref[i] += pref[i-1];	
	}	
	while(q--)
	{
		int l,r;
		std::cin>>l>>r;
		int pv = pref[r] - pref[l-1];
		if((l > 1) && s[l-1] == 'C' && s[l-2] == 'A')
		pv--;	
		std::cout<<pv<<"\n";
	}
	return 0;
}