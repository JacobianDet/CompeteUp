#include <bits/stdc++.h>

typedef long double ld;

ld memo[3000][3000];
bool vis[3000][3000];
ld p[3000];
int tot;

ld COINS(int n, int h)
{
	if(!n)
	{
		if(tot > 2*h)
		return 0;
		else return 1;	
	}
	if(vis[n][h])
	return memo[n][h];
	ld ans = 0;
	ans = (p[n] * COINS(n-1, h+1)) + ((1 - p[n]) * COINS(n-1, h));
	vis[n][h] = 1;
	memo[n][h] = ans;
	return ans;	
}

int main(void)
{
	memset(vis, 0, sizeof(vis));
	int n;
	scanf("%d", &n);
	tot = n;
	for(int i=1;i<=n;i++)
	scanf("%Lf", &p[i]);
	ld ans = COINS(n, 0);	
	printf("%.15Lf\n", ans);
	return 0;
}