#include <bits/stdc++.h>

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int a;
		std::cin>>a;
		std::cout<<(1<<(__builtin_popcount(a)))<<"\n";
	}
	return 0;
}