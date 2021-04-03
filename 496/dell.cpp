#include <bits/stdc++.h>

int main(void)
{
	std::string a,b;
	std::cin>>a>>b;
	int i = (int)a.size()-1;
	int j = (int)b.size()-1;
	while((i != -1) && (j != -1) && (a[i] == b[j]))
	{
		i--;
		j--;
	}	
	std::cout<<i+j+2<<"\n";
	return 0;
}