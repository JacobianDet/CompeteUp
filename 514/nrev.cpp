#include <bits/stdc++.h>
#define mp std::make_pair

typedef long double ld;
typedef long long ll;

std::pair<ll, ll> arr[100001];

ld bs1(int n)
{
	for(int i=0;i<n;i++)
	arr[i].second = abs(arr[i].second);	
	ld lo = 0;
	ld hi = 10000000000000001;
	for(int t=0;t<100;t++)
	{
		ld mid = (lo + hi)/2;
		bool ok = 1;
		ld xl = -10000000000000001;
		ld xr = 10000000000000001;
		for(int i=0;i<n;i++)
		{
			ld D = ((2 * arr[i].second * mid) - (arr[i].second * arr[i].second));
			if(D < 0)
			{
				ok = 0;
				break;
			}	
			else
			{
				xl = std::max(xl, (arr[i].first - (ld)sqrt((ld)D)));
				xr = std::min(xr, (arr[i].first + (ld)sqrt((ld)D)));
				if(xl > xr)
				{
					ok = 0;
					break;
				}	
			}
		}	
		if(!ok)
		lo = mid;
		else hi = mid;	
	}
	return lo;	
}

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		ll x,y;
		std::cin>>x>>y;
		arr[i] = mp(x, y);
	}	
	int nc = 0;
	int pc = 0;
	for(int i=0;i<n;i++)
	{
		if(arr[i].second > 0)
		pc++;
		else nc++;	
	}	
	if(pc && nc)
	std::cout<<"-1\n";
	else
	{
		ld ans = bs1(n);
		printf("%.10Lf\n", ans);
	}	
	return 0;
}