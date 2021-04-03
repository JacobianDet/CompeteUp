#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

ll arr[100001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	ll sx = 0, mx = 0;
	for(int i=0;i<n;i++)
	{	
		std::cin>>arr[i];
		sx += arr[i];
		if(mx < arr[i])
		mx = arr[i];
	}		
	if(!(sx & 1) && 2*mx <= sx)
	std::cout<<"YES\n";
	else std::cout<<"NO\n";
	return 0;	
}		