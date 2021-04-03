#include <bits/stdc++.h>

int lcp[51];

int main(void)
{
	int n,k;
	std::cin>>n>>k;
	std::string t;
	std::cin>>t;
	for(int i=1;i<n;i++)
	{
		int j = lcp[i-1];
		while(j && (t[i] != t[j]))
		j = lcp[j-1];
		if(t[i] == t[j])
		j++;
		lcp[i] = j;	
	}
	if(!lcp[n-1])
	{
		for(int i=0;i<k;i++)
		std::cout<<t;
		std::cout<<"\n";
	}	
	else
	{
		std::string w;
		for(int i=lcp[n-1];i<n;i++)
		w += t[i];
		std::cout<<t;
		for(int i=0;i<k-1;i++)
		std::cout<<w;
		std::cout<<"\n";	
	}
	return 0;
}