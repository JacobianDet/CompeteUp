#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	int k,n;
	std::cin>>n>>k;
	ll arr[n+1];
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	bool a2[n+1];
	for(int i=1;i<=n;i++)
	std::cin>>a2[i];
	ll ts = 0;
	ll pref1[n+1],pref2[n+1];
	memset(pref1,0,sizeof(pref1));
	memset(pref2,0,sizeof(pref2));
	for(int i=1;i<=n;i++)
	{
		pref1[i] = pref1[i-1] + arr[i];
		pref2[i] = pref2[i-1] + a2[i]*arr[i];
	}
	for(int i=1;i<=n-k+1;i++)
	ts = std::max(ts, pref2[i-1] + pref1[i+k-1]-pref1[i-1] + pref2[n]-pref2[i+k-1]);
	std::cout<<ts<<"\n";
	return 0;
}