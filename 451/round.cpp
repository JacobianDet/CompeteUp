#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	int z = n%10;
	if(z < 5)
	n -= z;
	else n += (10-z);
	std::cout<<n<<"\n";
	return 0;	
}