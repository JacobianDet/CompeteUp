#include <bits/stdc++.h>

int main(void)
{
	int n,k;
	std::cin>>n>>k;
	if(k == 1 || k == n)
	std::cout<<(3*(n-1) + 2 + 1)<<"\n";
	else if(k-1 > n-k)
	std::cout<<(2*(n-k+1) + 2*(n-k) + 1 + 3*(k-2) + 2 + 1)<<"\n";
	else std::cout<<(2*k + 2*(k-1) + 1 + 3*(n-k-1) + 2 + 1)<<"\n";
	return 0; 
}