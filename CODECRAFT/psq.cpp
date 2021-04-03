#include <bits/stdc++.h>

int a[1000];
bool vx[1000001];

int b1(int n)
{
	int lo = 0;
	int hi = n-1;
	while(lo < hi)
	{
		int mid = lo + (hi-lo)/2;
		if(a[mid] < 0)
		lo = mid + 1;
		else hi = mid;
	}	
	return lo;
}

int bex(int ppv, int n, int val)
{
	int lo = ppv;
	int hi = n-1;
	while(lo < hi)
	{
		int mid = lo + (hi-lo)/2;
		if(a[mid] < val)
		lo = mid + 1;
		else hi = mid;	
	}	
	if(a[lo] != val)
	return -1;	
	else return lo;
}

int main(void)
{
	memset(vx,0,sizeof(vx));
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>a[i];
	std::sort(a, a+n);
	if(a[n-1] < 0)
	std::cout<<a[n-1]<<"\n";
	else
	{
		int ppv = b1(n);
		vx[0] = 1;
		for(int i=1; i*i <= a[n-1]; i++)
		{
			int ind = bex(ppv, n, i*i);
			if(ind != -1)
			vx[a[ind]] = 1;	
		}	
		bool flag = 0;
		for(int i=n-1;i>=ppv;i--)
		{
			if(!vx[a[i]])
			{	
				std::cout<<a[i]<<"\n";	
				flag = 1;
				break;
			}	
		}	
		if(!flag)
		std::cout<<a[ppv-1]<<"\n";	
	}	
	return 0;
}