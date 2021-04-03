#include <bits/stdc++.h>

typedef long double ld;

struct val
{
	int a,t;
}Q[1000000];

ld maxv(int n, int T)
{
	ld lo = 0;
	ld hi = 1e6;
	for(int i=0;i<100;i++)
	{
		ld mid = lo + (hi-lo)/2;
		ld w = 0, x = 0,t = 0;
		for(int j=0;j<n;j++)
		{
			if(mid > Q[j].a)
			{
				w += (Q[j].a * Q[j].t);
				x += Q[j].a;
			}	
			else
			{
				w += (mid * Q[j].t);
				x += mid;
			}	
		}	
		if(x)
		t = w/x;
		if(t > T)
		hi = mid;
		else lo = mid;	
	}
	return lo;
}

int main(void)
{
	int n,T;
	std::cin>>n>>T;
	for(int i=0;i<n;i++)
	std::cin>>Q[i].a;
	for(int i=0;i<n;i++)
	std::cin>>Q[i].t;
	ld ans = maxv(n, T);
	std::cout<<std::fixed<<std::setprecision(15)<<ans<<"\n";
	return 0;
}