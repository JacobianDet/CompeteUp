#include <bits/stdc++.h>

int mc[300001], mnc[300001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	mnc[i] = n+1;	
	for(int i=1;i<=n;i++)
	{
		int cx;
		std::cin>>cx;
		mc[cx] = std::max(mc[cx], i);
		mnc[cx] = std::min(mnc[cx], i);
	}	
	int mn1 = n+1, mn2 = n+1, mx1 = 0, mx2 = 0, en1 = 0, en2 = 0, ex1 = 0, ex2 = 0;
	for(int i=1;i<=n;i++)
	{
		if(mc[i])
		{
			if(mx1 < mc[i])
			{
				mx2 = mx1;
				ex2 = ex1;
				mx1 = mc[i];
				ex1 = i;
			}
			else if((mc[i] <= mx1) && (mx2 < mc[i]))
			{
				mx2 = mc[i];
				ex2 = i;
			}	
		}
		if(mnc[i] != n+1)
		{
			if(mn1 > mnc[i])
			{
				mn2 = mn1;
				en2 = en1;
				mn1 = mnc[i];
				en1 = i;
			}
			else if((mnc[i] >= mn1) && (mn2 > mnc[i]))
			{
				mn2 = mnc[i];
				en2 = i;
			}	
		}
	}
	if(ex1 != en1)
	std::cout<<(mx1 - mn1)<<"\n";
	else std::cout<<std::max(mx2 - mn1, mx1 - mn2)<<"\n";
	return 0;
}