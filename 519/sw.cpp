#include <bits/stdc++.h>
#define pb push_back

bool ctx[1001];

int main(void)
{
	std::string s;
	std::cin>>s;
	int n = (int)s.size();
	int apos = -1;
	for(int i=n-1;i>=0;i--)
	{
		if(s[i] == 'a')
		{
			apos = i;
			break;
		}	
	}	
	if(apos == -1)
	{
		for(int i=0;i<n;i++)
		std::cout<<"0 ";
		std::cout<<"\n";	
	}	
	else
	{
		std::vector<int> ax;
		std::vector<int> bx;
		for(int i=0;i<apos;i++)
		{
			if((s[i] == 'a') && (s[i+1] == 'b'))
			ax.pb(i);	
			if((s[i] == 'b') && (s[i+1] == 'a'))
			bx.pb(i);	
		}	
		for(int i=0,j=(int)ax.size();i<j;i++)
		ctx[ax[i]] = 1;
		for(int i=0,j=(int)bx.size();i<j;i++)
		ctx[bx[i]] = 1;	
		ctx[apos] = 1;
		for(int i=0;i<n;i++)
		std::cout<<ctx[i]<<" ";
		std::cout<<"\n";	
	}
	return 0;
}