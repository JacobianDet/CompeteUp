#include <bits/stdc++.h>

int main(void)
{
	std::string s = "181010110101181010110101181010110101191010110101",m;
	s += s;
	int n;
	std::cin>>n;
	int t=0;
	for(int i=0;i<n;i++)
	{
		std::cin>>t;
		m += (char)((t%10) + '0');
	}
	if(s.find(m) != std::string::npos)
	std::cout<<"YES\n";
	else std::cout<<"NO\n";
	return 0;	
}