#include <bits/stdc++.h>
#define CHOR 1001
 
int k;
std::string s1,s2;
int memo[CHOR][CHOR];
 
int lcscn(int i, int j)
{
	if(!i || !j)
	return 0;
	if(memo[i][j] != -1)
	return memo[i][j];
	int r = 0, ans = 0;
	for(r=0;(((i-r-1) >= 0) && ((j-r-1) >= 0) && (s1[i-r-1] == s2[j-r-1]));r++)
	{	
		if(r >= k)	
		ans = std::max(ans, r+lcscn(i-r, j-r));	
	}	
	if(r >= k)
	ans = std::max(ans, r+lcscn(i-r, j-r));	
	ans = std::max(ans, std::max(lcscn(i-1, j), lcscn(i, j-1)));
	memo[i][j] = ans;
	return ans;
}
 
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::cin>>k;
	while(k)
	{	
		memset(memo, -1, sizeof(memo));
		std::cin>>s1>>s2;
		int n1 = (int)s1.size();
		int n2 = (int)s2.size();
		int ans = lcscn(n1, n2);
		std::cout<<ans<<"\n";
		std::cin>>k;
	}	
	return 0;
} 