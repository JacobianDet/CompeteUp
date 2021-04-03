#include <bits/stdc++.h>

int lcp[2002], pref[2002];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m,q;
	std::cin>>n>>m>>q;
	std::string s,t;
	std::cin>>s>>t;
	std::string z = t + '#' + s;
	lcp[0] = 0;
	for(int i=1;i<=n+m;i++)
	{
		int j = lcp[i-1];
		while(j && z[i] != z[j])
		j = lcp[j-1];
		if(z[i] == z[j])
		j++;
		lcp[i] = j;	
	}	
	for(int i=2*m;i<=n+m;i++)
	{
		if(lcp[i] == m)
		pref[i-2*m+1] = pref[i-2*m] + 1;
		else pref[i-2*m+1] = pref[i-2*m]; 	
	}	
	while(q--)
	{
		int l,r;
		std::cin>>l>>r;
		if(r-m+1 >= l)
		std::cout<<(pref[r-m+1] - pref[l-1])<<"\n";
		else std::cout<<"0\n";	
	}
	return 0;
}