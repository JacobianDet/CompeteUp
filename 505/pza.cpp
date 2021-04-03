#include <bits/stdc++.h>

int main(void)
{
	std::string s;
	std::cin>>s;
	int n = (int)s.size();
	int pz1 = 1;
	for(int i=1;i<n;i++)
	{
		if(s[i] != s[i-1])
		pz1++;
		else break;	
	}	
	int pz2 = 1;
	for(int i=n-2;i>=0;i--)
	{
		if(s[i] != s[i+1])
		pz2++;
		else break;	
	}
	int ovx = 1, imax = 1;
	for(int i=1;i<n;i++)
	{
		if(s[i] != s[i-1])
		imax++;	
		else
		{
			ovx = std::max(ovx, imax);
			imax = 1;
		}	
	}
	ovx = std::max(ovx, imax);	
	if(s[0] != s[n-1])
	{
		if(pz2 >= n - pz1)
		ovx = n;
		else ovx = std::max(ovx, pz1 + pz2);	
	}	
	std::cout<<ovx<<"\n";
	return 0;
}