#include <bits/stdc++.h>

std::string s;
int memo[200001][3];

int cix(int i, int sum)
{
	if(i == (int)s.size())
	{
		if(!sum)
		return 1;
		else return 0;	
	}	
	if(memo[i][sum] != -1)
	return memo[i][sum];
	int ans = 0;
	if(!(s[i] - '0') && !sum)	
	ans = 1 + cix(i+1, sum);
	else if(!sum && i)
	ans = std::max(1 + cix(i+1, (s[i] - '0')%3), cix(i+1, ((sum%3) + (s[i]-'0')%3)%3));
	else ans = std::max(cix(i+1, (((sum%3) + (s[i]-'0')%3)%3)), cix(i+1, (s[i] - '0')%3));
	memo[i][sum] = ans;
	return ans;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	std::cin>>s;
	int ans = cix(0, 0);
	std::cout<<ans<<"\n";
	return 0;
}