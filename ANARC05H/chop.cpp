#include <bits/stdc++.h>

int pref[27],n;
int memo[27][27][27];

int chop(int i, int p1, int p2)
{
	if(i == n)
	return 1;
	if(memo[i][p1][p2] != -1)
	return memo[i][p1][p2];	
	int a = pref[p1] - pref[p2];
	int b = pref[i] - pref[p1];
	int ans = 0;
	if(a <= b)
	{
		if(b <= pref[n] - pref[i])
		ans = chop(i+1, p1, p2) + chop(i+1, i, p1);	
		else ans = 1;
	}	
	else ans = chop(i+1, p1, p2);
	memo[i][p1][p2] = ans;
	return ans;
}

int main(void)
{
	std::string s;
	std::cin>>s;
	int t=1;
	while(s != "bye")
	{
		memset(memo,-1,sizeof(memo));
		memset(pref,0,sizeof(pref));
		n = (int)s.size();
		for(int i=1;i<=n;i++)
		pref[i] = pref[i-1] + (int)(s[i-1]-'0');
		int ans = chop(1, 0, 0);
		std::cout<<t<<". "<<ans<<"\n";
		t++;
		std::cin>>s;	
	}	
	return 0;
}