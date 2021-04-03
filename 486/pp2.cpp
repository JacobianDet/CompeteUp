#include <bits/stdc++.h>
#define CHOR 200001
#define pb push_back

int arr[CHOR];

int bs1(int n, int x)
{
	int lo = 0;
	int hi = n-1;
	while(lo < hi)
	{
		int mid = lo + (hi -lo)/2;
		if(arr[mid] < x)
		lo = mid + 1;
		else hi = mid;	
	}	
	if(arr[lo] == x)
	return lo;
	else return -1;	
}

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	std::sort(arr, arr+n);
	int mlen = 0;
	std::vector<int> Z;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<32;j++)
		{
			int t1 = bs1(n, arr[i]+(1<<j));
			if(t1 != -1)
			{
				int t2 = bs1(n, arr[i]+(1<<(j+1)));
				if(t2 != -1)
				{
					mlen = 3;
					Z.clear();
					Z.pb(arr[i]);
					Z.pb(arr[i] + (1<<j));
					Z.pb(arr[i] + (1<<(j+1)));
				}
				if(mlen < 2)
				{
					mlen = 2;
					Z.clear();
					Z.pb(arr[i]);
					Z.pb(arr[i] + (1<<j));
				}	
			}
			if(mlen < 1)
			{
				mlen = 1;
				Z.clear();
				Z.pb(arr[i]);
			}	
		}	
	}
	std::cout<<mlen<<"\n";
	for(int i=0;i<mlen;i++)
	std::cout<<Z[i]<<" ";
	std::cout<<"\n";
	return 0;	
}