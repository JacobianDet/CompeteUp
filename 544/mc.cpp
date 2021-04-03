#include <bits/stdc++.h>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int h1, m1, h2, m2;
	char c;
	std::cin>>h1>>c>>m1;
	std::cin>>h2>>c>>m2;
	int xm1 = h1 * 60 + m1;
	int xm2 = h2 * 60 + m2;
	int mm = (xm2 - xm1)/2;
	int hm = h1;
	mm += m1;
	while(mm >= 60)
	{
		hm++;
		mm -= 60;
	}
	if(hm >= 0 && hm <= 9)
	std::cout<<"0"<<hm<<":";
	else std::cout<<hm<<":";
	if(mm >= 0 && mm <= 9)
	std::cout<<"0"<<mm<<"\n";
	else std::cout<<mm<<"\n";	
	return 0;	
}