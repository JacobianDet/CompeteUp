#include <bits/stdc++.h>

int main(void)
{
	int n,m;
    scanf("%d %d", &n, &m);
	double a,b,mc=1e8;
	for(int i=0;i<n;i++)
	{
		scanf("%lf %lf", &a, &b);
		if(mc > (double)(a/b)*m)
		mc = (double)(a/b)*m;	
	}	
	printf("%.8lf\n", mc);
	return 0;
}