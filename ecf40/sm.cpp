#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	std::string s;
	std::cin>>s;
	if(n == 1 || n == 2 || n == 3)
	std::cout<<n<<"\n";
	else 
	{
		int i = 0;
		for(i=n/2;i>=2;i--)
		{
			if(s.substr(0,i) == s.substr(i,i))
			break;	
		}	
		std::cout<<n-i+1<<"\n";
	}	
	return 0;
}