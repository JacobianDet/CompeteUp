#include <bits/stdc++.h>

typedef long long ll;

ll A[300001], B[300001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
	int n,m;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>A[i];
	std::cin>>m;
	for(int i=0;i<m;i++)
	std::cin>>B[i];
	int p1 = 0, p2 = 0;
	ll as = 0, bs = 0;
	int os = 0;
	while((p1 < n) && (p2 < m))	
	{
		if(A[p1] == B[p2])
		{	
			os++;
			p1++;
			p2++;
		}
		else
		{
			as = A[p1];
			bs = B[p2];
			p1++;
			p2++;
			while((as != bs) && (p1 < n) && (p2 < m))
			{
				if(as < bs)
				{
					as += A[p1];
					p1++;
				}
				else if(bs < as)
				{
					bs += B[p2];
					p2++;
				}	
			}
			if(as == bs)
			{
				os++;
				as = 0;
				bs = 0;
			}	
		}		
	}
	while((as < bs) && (p1 < n))
	{
		as += A[p1];
		p1++;
	}	
	while((as > bs) && (p2 < m))
	{
		bs += B[p2];
		p2++;
	}
	if(as == bs)
	{
		if(as)
		os++; 
	}
	else os = 0;		
	if(os)
	std::cout<<os<<"\n";
	else std::cout<<"-1\n";
	return 0;
}