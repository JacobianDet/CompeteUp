#include <bits/stdc++.h>

struct s4
{
	int e,g,m,h,sm,id;
}arr[1001];

bool cmpx(s4 u, s4 v)
{
	return (u.sm == v.sm) ? (u.id < v.id) : (u.sm > v.sm);
}

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		std::cin>>arr[i].e>>arr[i].g>>arr[i].m>>arr[i].h;
		arr[i].id = i+1;
		arr[i].sm = arr[i].e + arr[i].g + arr[i].m + arr[i].h;
	}	
	std::sort(arr, arr+n, cmpx);
	for(int i=0;i<n;i++)
	{
		if(arr[i].id == 1)
		{
			std::cout<<i+1<<"\n";
			break;
		}	
	}	
	return 0;
}