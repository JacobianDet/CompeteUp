#include <bits/stdc++.h>

typedef long double ld;

int pref[5001];

int main(void)
{
	int n,k;
	scanf("%d %d", &n, &k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d", &pref[i]);
		pref[i] += pref[i-1];
	}	
	ld res = 0;
	for(int i=1;i<=n-k+1;i++)
	{
		for(int j=k+i-1;j<=n;j++)
		{
			ld px = (ld)((ld)pref[j] - pref[i-1])/(j-i+1);
			if(px > res)
			res = px;	
		}
	}
	printf("%.15Lf\n", res);
	return 0;	
}