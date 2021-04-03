#include <bits/stdc++.h>
#define ll long long
#define CHOR 100001

int ctr[CHOR];
ll memo[CHOR];
//Top-Down
/*ll maxpt(int n)
{
	if(n == -1)
	return 0;
	if(memo[n] != -1)
	return memo[n];	
	ll ans = 0;
	int pos = -1;
	for(int i=n+2;i<CHOR;i++)
	{
		if(ctr[i])
		{
			pos = i;
			break;
		}	
	}	
	ans = std::max(ans, 1ll*n*ctr[n]+maxpt(pos));
	if(pos+1 != CHOR && ctr[pos+1])
	ans = std::max(ans, 1ll*n*ctr[n]+maxpt(pos+1));
	memo[n] = ans;
	return ans;	
}*/

int main(void)
{
	memset(ctr,0,sizeof(ctr));
	memset(memo,-1,sizeof(memo));
	int n;
	std::cin>>n;
	int t;
	for(int i=0;i<n;i++)
	{	
		std::cin>>t;
		ctr[t]++;
	}	
	ll ans = 0;
	//int pos = 0;
	//Bottom-Up
	memo[1] = ctr[1];
	memo[2] = 2*ctr[2];
	memo[3] = memo[1] + 3*ctr[3];
	for(int i=4;i<CHOR;i++)
	{
		/*if(ctr[i])
		{	
			pos = i;
			break;
		}*/
		memo[i] = 1ll*i*ctr[i] + std::max(memo[i-2],memo[i-3]);		
	}
	/*ans = std::max(ans,maxpt(pos));
	if(pos+1 != CHOR && ctr[pos+1])
	ans = std::max(ans,maxpt(pos+1));*/	
	std::cout<<std::max(memo[CHOR-1],memo[CHOR-2])<<"\n";
	return 0;
}