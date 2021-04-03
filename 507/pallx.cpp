#include <bits/stdc++.h>

int arr[21];

int main(void)
{
	int n,a,b;
	std::cin>>n>>a>>b;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];	
	int ct = 0;
	bool ok = 1;
	for(int i=0;i<(n>>1);i++)
	{
		if(arr[i] == 2 && arr[n-1-i] == 2)
		{
			if(a < b)
			ct += (a<<1);
			else ct += (b<<1);	
		}	
		else if(arr[i] == 2)
		{
			if(arr[n-i-1] == 1)
			ct += b;
			else ct += a;	
		}	
		else if(arr[n-i-1] == 2)
		{
			if(arr[i] == 1)
			ct += b;
			else ct += a;	
		}	
		else if(arr[i] != arr[n-i-1])
		{
			ok = 0;
			break;
		}	
	}	
	if(!ok)
	std::cout<<"-1\n";
	else
	{
		if(n & 1)
		{
			if(arr[(n>>1)] == 2)
			{
				if(a < b)
				ct += a;
				else ct += b;	
			}	
		}	
		std::cout<<ct<<"\n";
	}	
	return 0;
}