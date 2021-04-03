#include <bits/stdc++.h>

int main(void)
{
	std::string s;
	std::cin>>s;
	std::stack<int> S;
	int n = (int)s.size();
	for(int i=0;i<n;i++)
	{
		if(S.empty() || (s[S.top()] == s[i]))
		S.push(i);
		else S.pop();
	}
	std::cout<<(n - (int)S.size())<<"\n";
	return 0;
}