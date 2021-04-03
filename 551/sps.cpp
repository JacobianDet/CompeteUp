#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::string s;
	std::cin>>n>>s;
	int op = 0, clo = 0;
	for(int i=0;i<n;i++)
	{
		if(s[i] == '(')
		op++;
		else if(s[i] == ')') 
		clo++;	
	}	
	int lp = 0, rp = 0;
	while(op + clo < n)
	{
		if(op < clo)
		{
			lp++;
			op++;
		}	
		else
		{
			rp++;
			clo++;
		}	
	}
	for(int i=0;i<n;i++)
	{
		if(s[i] == '(' || s[i] == ')') continue;
		if(lp > 0)
		{
			lp--;
			s[i] = '(';
		}	
		else if(rp > 0)
		{
			rp--;
			s[i] = ')';
		}
	}	
	int bal = 0;
	bool ok = 1;
	for(int i=0;i<n;i++)
	{
		if(s[i] == '(')
		bal++;
		else bal--;
		if(i < n-1)
		{
			if(bal <= 0)
			{	
				ok = 0;
				break;
			}	
		}
		else
		{
			if(bal != 0)
			{
				ok = 0;
				break;
			}
		}
	}
	if(!ok)
	std::cout<<":(\n";
	else std::cout<<s<<"\n";
	return 0;	
}