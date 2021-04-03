#include <bits/stdc++.h>
#define mp std::make_pair

std::pair<int, int> arr[100001];
int eff[100001];

bool cmpx(std::pair<int, int> a, std::pair<int, int> b)
{
	return (a.first < b.first);
}

int bs1(int n, int val)
{
	int lo = 1;
	int hi = n;
	while(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		if(arr[mid].first >= val)
		hi = mid;
		else lo = mid + 1;	
	}
	return lo;
}

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		std::cin>>a>>b;
		arr[i] = mp(a, b);
	}	
	std::sort(arr+1, arr+n+1, cmpx);
	for(int i=2;i<=n;i++)
	{
		int pos = bs1(i, arr[i].first - arr[i].second);
		eff[i] = (i - pos) + eff[pos-1];	
	}	
	int mn = n;
	for(int i=n+1;i>1;i--)
	{	
		if(i == n+1)
		mn = std::min(mn, eff[i-1]);	
		else mn = std::min(mn, (n - i + 1) + eff[i-1]);
	}	
	std::cout<<mn<<"\n";
	return 0;
}