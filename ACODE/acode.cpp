#include <bits/stdc++.h>
#define ll long long int
ll memo[5001];
std::string s;

ll acx(int n)
{
	if(n == (int)s.size())
	return 1;
	if(memo[n] != -1)
	return memo[n];
	ll ans = 0;
	if(s[n] != '0')
	ans += acx(n+1);
	if((n+1 < (int)s.size()) && ((s[n] == '1') || ((s[n] == '2') && (s[n+1] >= '0') && (s[n+1] <= '6'))))
	ans += acx(n+2);	
	memo[n] = ans;
	return ans;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::cin>>s;
	while(s[0] != '0')
	{
		memset(memo, -1, sizeof(memo));
		ll ans = acx(0);
		std::cout<<ans<<"\n";
		std::cin>>s;
	}
	return 0;
}
