#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	int tx = n, c2 = 0;
	while(tx)
	{
		if((tx % 10) == 2)
		c2++;
		tx /= 10;	
	}
	std::cout<<c2<<"\n";
	return 0;
}