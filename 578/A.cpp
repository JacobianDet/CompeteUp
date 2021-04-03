#include <bits/stdc++.h>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	std::string s;
	std::cin>>s;
	std::set<int> A;
	std::set<int, std::greater<int> > B;
	for(int i=0;i<10;i++)
	{
		A.insert(i);
		B.insert(i);
	}	
	for(int i=0;i<n;i++)
	{
		if(s[i] == 'L')
		{
			B.erase(*A.begin());
			A.erase(*A.begin());
		}	
		else if(s[i] == 'R')
		{
			A.erase(*B.begin());
			B.erase(*B.begin());
		}
		else
		{
			A.insert(s[i] - '0');
			B.insert(s[i] - '0');
		}
	}
	bool vx[10];
	memset(vx, 1, sizeof(vx));
	for(auto u : A)
	vx[u] = 0;
	for(int i=0;i<10;i++)
	std::cout<<vx[i];
	std::cout<<"\n";
	return 0;	
}