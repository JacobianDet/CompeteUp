#include <bits/stdc++.h>

int main(void)
{
	int n,k;
	std::cin>>n>>k;
	while(k--)
	{
		if(n % 10)
		n--;
		else n /= 10;	
	}	
	std::cout<<n<<"\n";
	return 0;
}