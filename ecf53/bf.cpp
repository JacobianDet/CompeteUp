#include <bits/stdc++.h>

typedef long long ll;

ll arr[200001], pref[200001];

int main(void)
{
	ll T;
	int n;
	std::cin>>n>>T;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	for(int i=1;i<=n;i++)
	pref[i] = pref[i-1] + arr[i];
	ll tc = 0;
	for(int i=n;i>=1;i--)
	{
		tc += (T/pref[i])*i;
		T %= pref[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(arr[i] <= T)
		{
			tc++;
			T -= arr[i];
		}	
	}	
	std::cout<<tc<<"\n";
	return 0;	
}