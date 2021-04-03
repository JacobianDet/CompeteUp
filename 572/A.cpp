#include <bits/stdc++.h>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::string s;
	std::cin>>n>>s;
	int c0 = 0, c1 = 0;
	for(int i=0;i<n;i++)
	{
		if(s[i] == '0')
		c0++;
		else c1++;	
	}	
	if(c0 != c1)
	std::cout<<"1\n"<<s<<"\n";
	else std::cout<<"2\n"<<s[0]<<" "<<s.substr(1)<<"\n";
	return 0;
}