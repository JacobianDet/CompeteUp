#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

std::vector<int> r1;
std::vector<int> r2;
int arr[100001];
bool ctr[100001];

int bs1(int x)
{
	int lo = 0;
	int hi = (ll)r2.size()-1;
	while(lo < hi)
	{
		int mid = lo + (hi -lo)/2;
		if(r2[mid] <= x)
		lo = mid + 1;
		else hi = mid;	
	}	
	if(r2[lo] > x)
	return lo;
	else return -1;	
}

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	for(int i=1;i<=n;i++)
	{
		if(!ctr[arr[i]])
		{
			r1.pb(i);
			ctr[arr[i]] = 1;
		}	
	}	
	memset(ctr, 0, sizeof(ctr));
	for(int i=n;i>=1;i--)
	{
		if(!ctr[arr[i]])
		{
			r2.pb(i);
			ctr[arr[i]] = 1;
		}	
	}
	std::sort(r2.begin(), r2.end());
	int n1 = (int)r1.size();
	int n2 = (int)r2.size();
	ll px = 0;
	for(int i=0;i<n1;i++)
	{
		int p = bs1(r1[i]);
		if(p != -1)
		px += 1LL*(n2-p);	
	}	
	std::cout<<px<<"\n";
	return 0;
}