#include <bits/stdc++.h>

typedef long double ld;

int main(void)
{
	int h,m,H,D,C,N;
	std::cin>>h>>m;
	std::cin>>H>>D>>C>>N;
	ld cost = 0;
	int reqd = ceil((ld)H/N);
	cost = reqd * C;
	if(h >= 20)
	cost = cost*0.8;
	else 
	{
		int md = 60 - m;
		int hd = 19 - h;
		if(md == 60)
		{
			md = 0;
			hd++;
		}	
		H += (md + 60*hd)*D;
		int reqd2 = ceil((ld)H/N);
		ld cd2 = reqd2 * C * 0.8;
		if(cd2 < cost)
		cost = cd2;	
	}	
	std::cout<<std::fixed<<std::setprecision(4)<<cost<<"\n";
	return 0;
}