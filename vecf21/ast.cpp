#include <bits/stdc++.h>

typedef long long ll;

ll arr[200001];

int main(void)
{
	ll n,k;
	std::cin>>n>>k;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	for(int i=1;i<=n;i++)
	arr[i] += arr[i-1];
	ll sum = 0;
	for(int i=0;i<n-k+1;i++)
	sum += (arr[k+i] - arr[i]);
	long double ans = (long double)sum/(n-k+1);	
	printf("%.15Lf\n", ans);
	return 0;
}