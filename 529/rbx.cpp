#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::string s;
	std::cin>>n>>s;
	std::stack<int> S;
	for(int i=0;i<n;i++)
	{
		if(s[i] == '(')
		S.push(i);
		else if(s[i] == ')')
		{
			if(!S.empty())
			{
				if(s[S.top()] == s[i])
				S.push(i);
				else S.pop();	
			}
			else S.push(i);
		}	
	}
	if((int)S.size() == 2)
	{
		int a = S.top();
		S.pop();
		int b = S.top();
		S.pop();
		if(s[a] == s[b])
		{
			if(s[a] == '(')
			{
				int cx = 0;
				for(int i=a;i<n;i++)
				{
					if(s[i] == '(')
					cx++;	
				}
				std::cout<<cx<<"\n";
			}
			else
			{
				int cx = 0;
				for(int i=b;i>=0;i--)
				{
					if(s[i] == ')')
					cx++;	
				}
				std::cout<<cx<<"\n";
			}
		}
		else std::cout<<"0\n";
	}
	else std::cout<<"0\n";
}