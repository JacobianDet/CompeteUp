#include <bits/stdc++.h>

int main(void)
{
	int n,k;
	std::cin>>n>>k;
	std::string s;
	std::cin>>s;
	std::string t;
	int op = 0, cp = 0;
	for(int i=0;i<n;i++)
	{
		if(s[i] == '(' && op < (k>>1))
		{
			t += '(';
			op++;
		}
		if(s[i] == ')' && cp < (k>>1))
		{
			t += ')';
			cp++;
		}	
	}	
	std::cout<<t<<"\n";
	return 0;
}