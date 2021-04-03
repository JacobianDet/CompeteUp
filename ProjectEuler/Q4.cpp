#include <bits/stdc++.h>

bool chekp(int n)
{
	int x = 0;
	int z = n;
	while(z)
	{
		x = 10*x + (z%10);
		z /= 10;
	}	
	return (n == x);
}

int main(void)
{
	int maxx = 0;
	for(int i=100;i<=1000;i++)
	{
		for(int j=100;j<=1000;j++)
		{
			if(chekp(i*j))
			maxx = std::max(maxx, i*j);
		}
	}
	std::cout<<maxx<<"\n";
	return 0;	
}