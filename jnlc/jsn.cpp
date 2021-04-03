#include <bits/stdc++.h>

/*0 = x
  1 = y
  2 = z*/

typedef long long ll;
typedef long double ld;

ll p[3], q[3], d[3], c[3];
ld a[3], b[3];

ld bs(ll r)
{
	ld lo = 0;
	ld hi = 1000000000;
	for(int i=0;i<100;i++)
	{
		ld mid = lo + (hi - lo)/2;
		for(int j=0;j<3;j++)
		b[j] = (ld)q[j] + d[j]*mid - p[j];
		ld B = sqrt(b[0]*b[0] + b[1]*b[1] + b[2]*b[2]);
		a[0] = (b[1]*(p[2] - c[2]) - b[2]*(p[1] - c[1]))/B;
		a[1] = (b[2]*(p[0] - c[0]) - b[0]*(p[2] - c[2]))/B;
		a[2] = (b[0]*(p[1] - c[1]) - b[1]*(p[0] - c[0]))/B;
		ld R = sqrt(a[0]*a[0] + a[1]*a[1] + a[2]*a[2]);
		if(R < r)
		lo = mid;
		else hi = mid;	
	}
	return lo;	
}

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		ll r;
		for(int i=0;i<3;i++)
		scanf("%lld", &p[i]);
		for(int i=0;i<3;i++)
		scanf("%lld", &q[i]);
		for(int i=0;i<3;i++)
		scanf("%lld", &d[i]);
		for(int i=0;i<3;i++)
		scanf("%lld", &c[i]);
		scanf("%lld", &r);
		ld t = bs(r);	
		printf("%.10Lf\n", t);
	}
	return 0;
}