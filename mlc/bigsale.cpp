#include <bits/stdc++.h>

struct item
{
	int c,q,d;
};

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::cin>>n;
		item Q[n];
		for(int i=0;i<n;i++)
		std::cin>>Q[i].c>>Q[i].q>>Q[i].d;
		double tl = 0;
		for(int i=0;i<n;i++)
		{
			double inc = (double)Q[i].d * (double)Q[i].c/100;
			double nc = Q[i].c + inc;
			inc = (double)Q[i].d * nc/100;
			nc -= inc;
			tl += Q[i].q*(Q[i].c - nc);
		}	
		std::cout<<std::fixed<<std::setprecision(8)<<tl<<"\n";
	}
	return 0;	
}