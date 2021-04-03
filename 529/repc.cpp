#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	std::string s;
	std::cin>>s;
	std::string t;
	int ct = 1;
	for(int i=0;i<n; )
	{
		t += s[i];
		for(int j=0;j<ct;j++)
		i++;
		ct++;	
	}	
	std::cout<<t<<"\n";
	return 0;
}