#include <bits/stdc++.h>

typedef long long ll;

int arr[100001],k;
ll A, B;

ll fun(int l, int r)
{
	ll vx = std::upper_bound(arr, arr+k, r) - std::lower_bound(arr, arr+k, l);
	if(!vx)
	return A;	
	if(l == r)
	return B * vx;
	ll ans = B * (r - l + 1) * vx;
	int m = l + (r - l)/2;
	ans = std::min(ans, fun(l, m) + fun(m + 1, r));	
	return ans;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n>>k>>A>>B;
	for(int i=0;i<k;i++)
	std::cin>>arr[i];
	std::sort(arr, arr+k);
	ll ans = fun(1, (1<<n));
	std::cout<<ans<<"\n";
	return 0;	
}