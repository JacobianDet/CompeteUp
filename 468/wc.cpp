#include <bits/stdc++.h>

int main(void)
{
	int n,a,b;
	std::cin>>n>>a>>b;
	int fl = -1;
	while(n)
	{
		fl++;
		n >>= 1;
	}	
	int i=1;
	int x = ceil((float)a/2);
	int y = ceil((float)b/2);
	while(x != y)
	{
		i++;
		x = ceil((float)x/2);
		y = ceil((float)y/2);
	}	
	if(i == fl)
	std::cout<<"Final!\n";
	else std::cout<<i<<"\n";
	return 0;	
}