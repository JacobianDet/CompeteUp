#include <bits/stdc++.h>
#define pb push_back

struct amma
{
	int a,ind;
}arr[101];

bool cmp(amma x, amma y)
{
	return (x.a < y.a);
}

int bs1(int x, int n)
{
	int lo = 0;
	int hi = n-1;
	while(lo < hi)
	{
		int mid = lo + (hi -lo)/2;
		if(arr[mid].a <= x)
		lo = mid + 1;
		else hi = mid;	
	}	
	if(arr[lo].a > x)
	return lo;
	else return -1;	
}

int main(void)
{
	int n,k;
	std::cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		std::cin>>arr[i].a;
		arr[i].ind = i+1;
	}	
	std::sort(arr, arr+n, cmp);
	int t = 0;
	std::vector<int> Z;
	for(int i=0;i<n;i++)
	{
		int px = bs1(t, n);
		if((px == -1) || ((int)Z.size() == k))
		break;
		else 
		{
			Z.pb(arr[px].ind);
			t = arr[px].a;
		}		
	}
	if((int)Z.size() == k)
	{
		std::cout<<"YES\n";
		for(int i=0,j=(int)Z.size();i<j;i++)
		std::cout<<Z[i]<<" ";
		std::cout<<"\n";	
	}	
	else std::cout<<"NO\n";
	return 0;
}