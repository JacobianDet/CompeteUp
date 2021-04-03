#include <bits/stdc++.h>

int fexp(int a, int n)
{
	int res = 1;
	while(n)
	{
		if(n & 1)
		res *= a;
		a *= a;
		n >>= 1;	
	}	
	return res;
}

int main(void)
{
	int x;
	std::cin>>x;
	int maxi = 0;
	for(int i=2;i<10;i++)
	{
		for(int j=1;fexp(j, i)<=x;j++)
		maxi = std::max(maxi, fexp(j, i));
	}	
	std::cout<<maxi<<"\n";
	return 0;
}