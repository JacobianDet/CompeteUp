#include <bits/stdc++.h>

typedef long long ll;

struct twx
{
	ll pr, ar;
}arr[101];

bool cmpx(twx A, twx B)
{
	return ((A.pr < B.pr) || ((A.pr == B.pr) && (A.ar < B.ar)));
}

int bs2(int n, ll b)
{
	int lo = 0;
	int hi = n-1;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		if(arr[mid].pr > b)
		hi = mid - 1;
		else lo = mid;	
	}
	return ((arr[lo].pr > b) ? -1 : lo);
}

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		ll b;
		std::cin>>n>>b;
		for(int i=0;i<n;i++)
		{
			ll w,h,p;
			std::cin>>w>>h>>p;
			arr[i].pr = p;
			arr[i].ar = h*w;
		}
		std::sort(arr, arr+n, cmpx);
		int pos = bs2(n, b);
		if(pos == -1)
		std::cout<<"no tablet\n";
		else 
		{
			ll ans = 0;
			for(int i=0;i<=pos;i++)
			ans = std::max(ans, arr[i].ar);
			std::cout<<ans<<"\n";
		}
	}
	return 0;
}