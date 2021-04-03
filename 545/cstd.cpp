#include <bits/stdc++.h>

int lcp[500001];

int main(void)
{
	std::string s, t;
	std::cin>>s>>t;
	int n1 = (int)s.size();
	int n2 = (int)t.size();
	if(n1 < n2)
	std::cout<<s<<"\n";
	else
	{
		int sr0 = 0, sr1 = 0, tr0 = 0, tr1 = 0;
		for(int i=0;i<n1;i++)
		{
			if(s[i] == '0')
			sr0++;
			else sr1++;	
		}	
		for(int i=0;i<n2;i++)
		{
			if(t[i] == '0')
			tr0++;
			else tr1++;	
		}
		for(int i=1;i<n2;i++)
		{
			int j = lcp[i-1];
			while(j && (t[i] != t[j]))
			j = lcp[j-1];
			if(t[i] == t[j])
			j++;
			lcp[i] = j;	
		}
		if(sr0 < tr0 || sr1 < tr1)
		std::cout<<s<<"\n";
		else
		{
			std::cout<<t;
			sr0 -= tr0;
			sr1 -= tr1;
			std::string tn = t.substr(lcp[n2-1]);
			int n3 = tn.length();
			int zt0 = 0, zt1 = 0;
			for(int i=0;i<n3;i++)
			{
				if(tn[i] == '0')
				zt0++;
				else zt1++;	
			}
			while(sr0 >= zt0 && sr1 >= zt1)
			{
				std::cout<<tn;
				sr0 -= zt0;
				sr1 -= zt1;
			}
			for(int i=0;i<sr0;i++)
			std::cout<<"0";
			for(int i=0;i<sr1;i++)
			std::cout<<"1";
			std::cout<<"\n";	
		}	
	}	
	return 0;
}