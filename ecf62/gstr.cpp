#include <bits/stdc++.h>

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::string s;
		std::cin>>n>>s;
		std::stack<int> S1, S2;
		for(int i=0;i<n;i++)
		{
			if(S1.empty())
			S1.push(i);
			else
			{
				if(s[S1.top()] == '>' && s[i] == '<')
				continue;
				else S1.push(i);	
			}	
		}
		for(int i=n-1;i>=0;i--)
		{
			if(S2.empty())
			S2.push(i);
			else
			{
				if(s[S2.top()] == '<' && s[i] == '>')
				continue;
				else S2.push(i);	
			}
		}
		int cl = 0, cg = 0;
		while(!S1.empty())
		{
			int id = S1.top();
			S1.pop();
			if(s[id] == '<')
			cl++;
		}
		while(!S2.empty())
		{
			int id = S2.top();
			S2.pop();
			if(s[id] == '>')
			cg++;	
		}
		std::cout<<std::min(cl, cg)<<"\n";
	}
	return 0;
}