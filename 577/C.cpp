#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

ll arr[200001];
std::vector<ll> Z;

int bs1(ll k)
{
	int lo = 0;
	int hi = (int)Z.size()-1;
	while(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		if(Z[mid] <= k)
		lo = mid + 1;
		else hi = mid;	
	}
	return lo;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	ll k;
	std::cin>>n>>k;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	std::sort(arr+1, arr+n+1);
	if(n == 1)
	std::cout<<arr[1] + k<<"\n";
	else
	{
		int m = (n+1)/2;
		for(int i=m+1;i<=n;i++)
		{
			if(Z.empty())
			Z.pb(1LL*(i-m)*(arr[i] - arr[i-1]));
			else Z.pb(1LL*(i-m)*(arr[i] - arr[i-1])	+ Z[Z.size()-1]);
		}
		int pos = bs1(k);
		if(pos != Z.size()-1)
		std::cout<<arr[m+pos] + (k - (pos ? Z[pos-1] : 0))/(pos + 1)<<"\n";
		else if(Z[pos] > k)
		std::cout<<arr[m+pos] + (k - (pos ? Z[pos-1] : 0))/(pos + 1)<<"\n";	
		else std::cout<<arr[n] + (k - Z[Z.size()-1])/(n-m+1)<<"\n";
	}
	return 0;	
}		