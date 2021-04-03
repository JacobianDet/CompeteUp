#include <bits/stdc++.h>
#define CHOR 100001
#define pb push_back

int arr[CHOR];

int bs(int n)
{
	int lo = 1;
	int hi = 1000000000;
	int xct = 0;
	while(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		std::vector<int> pos;
		pos.pb(-1);
		for(int i=0;i<n;i++)
		{
			if(arr[i] >= mid)
			pos.pb(i);	
		}	
		pos.pb(n);
		int ict = 0;
		for(int i=0,j=(int)pos.size();i<j-1;i++)
		{
			if((pos[i+1] - pos[i]) > 1)
			ict++;	
		}	
		if(ict >= xct)
		{
			xct = ict;
			hi = mid;
		}
		else lo = mid + 1;
	}
	return lo;	
}

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];	
	int k = bs(n);
	std::cout<<k<<"\n";
	return 0;
}		