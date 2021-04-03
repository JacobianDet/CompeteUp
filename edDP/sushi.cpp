#include <bits/stdc++.h>

typedef long double ld;

bool vis[301][301][301];
ld memo[301][301][301];
int n,ctr[4];

ld SUSHI(int x1, int x2, int x3)
{
	if((x1 < 0) || (x2 < 0) || (x3 < 0))
	return 0;
	else if((x1 == 0) && (x2 == 0) && (x3 == 0))
	return 0;
	if(vis[x1][x2][x3])
	return memo[x1][x2][x3];
	ld ans = 0;
	ans = ((((ld)x1) * SUSHI(x1-1, x2, x3)) + (((ld)x2) * SUSHI(x1+1, x2-1, x3)) + (((ld)x3) * SUSHI(x1, x2+1, x3-1)) + ((ld)n))/((ld)(x1 + x2 + x3));
	vis[x1][x2][x3] = 1;
	memo[x1][x2][x3] = ans;
	return ans;	
}

int main(void)
{
	memset(vis, 0, sizeof(vis));
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d", &x);
		ctr[x]++;
	}	
	ld ans = SUSHI(ctr[1], ctr[2], ctr[3]);
	printf("%.15Lf\n", ans);
	return 0;
}