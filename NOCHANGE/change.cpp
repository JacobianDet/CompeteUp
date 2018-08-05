#include <bits/stdc++.h>

int coin[6];
int memo[100001][6];

bool ccm(int mon, int k)
{
	if(!mon)
	return 1;
	else if(mon < 0 || (mon > 0 && !k))
	return 0;
	if(memo[mon][k] != -1)
	return memo[mon][k];	
	bool ans = 0;
	ans |= (ccm(mon-coin[k], k) | ccm(mon-coin[k], k-1) | ccm(mon, k-1));
	memo[mon][k] = ans;	
	return ans;	
}

int main(void)
{
	memset(memo, -1, sizeof(memo));
	int mon,k;
	std::cin>>mon>>k;
	for(int i=1;i<=k;i++)
	{	
		std::cin>>coin[i];
		coin[i] += coin[i-1];
	}	
	bool ans = ccm(mon, k);
	if(ans)
	std::cout<<"YES\n";
	else std::cout<<"NO\n";
	return 0;	
}