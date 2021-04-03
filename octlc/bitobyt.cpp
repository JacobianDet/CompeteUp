#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::cin>>n;
		int ind = 0;
		if(!n || (n % 26))
		{	
			ind = n/26;
			n -= 26*ind;
		}
		else 
		{
			ind = n/26;
			ind--;
			n -= 26*ind;
		}	
		if(n <= 2)
		std::cout<<(1LL<<ind)<<" 0 0\n";
		else if(n > 2 && n <= 10)
		std::cout<<"0 "<<(1LL<<ind)<<" 0\n";
		else std::cout<<"0 0 "<<(1LL<<ind)<<"\n";	
	}
	return 0;
}