#include <bits/stdc++.h>

typedef long double ld;
typedef long long ll;

ll arr[100001];

bool cmpx(ll X, ll Y)
{
	return (X > Y);
}

int main(void)
{
	int n,k,m;
	std::cin>>n>>k>>m;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	ld ans = 0;
	ll ov = 0;
	std::sort(arr, arr+n, cmpx);
	for(int i=0;i<n;i++)
	{
		 ov += arr[i];
		 if((m - (n - i - 1)) >= 0)
		 {
		 	ld zx = std::min((ld)m - ((ld)n - i - 1), (ld)k * (i + 1));
		 	ans = std::max(ans, ((ld)ov + zx)/(ld)(i + 1));	
		 }	
	}
	std::cout.setf(std::ios_base::fixed);
	std::cout<<std::setprecision(15)<<ans<<"\n";
	std::cout.unsetf(std::ios_base::fixed);
	return 0;
}