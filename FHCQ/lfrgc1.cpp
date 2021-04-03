#include <bits/stdc++.h>

int main(void)
{
	freopen("lfrgc1.in", "r", stdin);
	freopen("lfrgc1.txt", "w", stdout);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		std::string s;
		std::cin>>s;
		int n = s.size();
		int ac = 0, bc = 0;
		for(int i=0;i<n;i++)
		{
			if(s[i] == 'A')
			ac++;
			else if(s[i] == 'B')
			bc++;	
		}
		int fz = n/2;
		if((n==ac) || (n==bc+1) || (bc < fz))
		std::cout<<"Case #"<<t<<": N\n";
		else std::cout<<"Case #"<<t<<": Y\n";	
	}
	return 0;
}