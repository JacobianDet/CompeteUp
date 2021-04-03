#include <bits/stdc++.h>

int ld[300002];
int next[300002];

int ldp(int x)
{
	if(x == next[x])
	return x;	
	else return next[x] = ldp(next[x]);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m;
	std::cin>>n>>m;
	for(int i=1;i<=300001;i++)
	{
		ld[i] = i;
		next[i] = i;
	}	
	for(int i=0;i<m;i++)
	{
		int l,r,z;
		std::cin>>l>>r>>z;
		for(int j=ldp(l);j<=r;j=ldp(j))
		{
			ld[j] = z;
			if(j == z)
			j++;
			else next[j] = j+1;	
		}	
	}	
	for(int i=1;i<=n;i++)
	{	
		if(ld[i] == i)
		ld[i] = 0;	
		std::cout<<ld[i]<<" ";
	}	
	std::cout<<"\n";
	return 0;	
}