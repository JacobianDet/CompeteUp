#include <bits/stdc++.h>

int main(void)
{
	int l,r;
	std::cin>>l>>r;
	if(abs(l - r) > 1 || (!l && !r))
	std::cout<<"NO\n";
	else std::cout<<"YES\n";
	return 0;	
}