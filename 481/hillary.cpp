#include <bits/stdc++.h>

struct racex
{
	int s,d,c,id;
};

bool cmp(racex a, racex b)
{
	if(a.d < b.d)
	return 1;	
	else return 0;	
}

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	racex rx[m];
	for(int i=0;i<m;i++)
	{
		std::cin>>rx[i].s>>rx[i].d>>rx[i].c;
		rx[i].id = i+1;
	}	
	std::sort(rx,rx+m,cmp);
	/*for(int i=0;i<m;i++)
	std::cout<<rx[i].s<<" "<<rx[i].d<<"\n";*/	
	int pix[n+1];
	memset(pix,0,sizeof(pix));
	bool ok = 1;
	for(int i=0;(i<m && ok);i++)
	{
		int ctr = 0;
		for(int j=rx[i].s;(j < rx[i].d && ctr < rx[i].c);j++)
		{
			if(!pix[j])
			{	
				pix[j] = rx[i].id;
				ctr++;
			}
		}
		if(ctr != rx[i].c)
		ok = 0;	
		pix[rx[i].d] = m+1;		
	}
	if(!ok)
	std::cout<<"-1\n";
	else
	{
		for(int i=1;i<=n;i++)
		std::cout<<pix[i]<<" ";
		std::cout<<"\n";	
	}
	return 0;
}