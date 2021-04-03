#include <bits/stdc++.h>

int X[100001];

int bs2(int n, int y)
{
	int lo = 0;
	int hi = n-1;
	while(lo < hi)
	{
		int mid = lo + (hi -lo + 1)/2;
		if(X[mid] > y)
		hi = mid - 1;
		else lo = mid;	
	}	
	if(X[lo] <= y)
	return lo+1;
	else return 0;	
}

int main(void)
{
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++)
    std::cin>>X[i];
    std::sort(X, X+n);
    int q;
    std::cin>>q;
    while(q--)
    {
        int m;
        std::cin>>m;
        std::cout<<bs2(n, m)<<"\n";
    }
    return 0;
}