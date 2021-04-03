#include <bits/stdc++.h>

int main(void)
{
	int x1,y1,x2,y2,x,y;
	std::cin>>x1>>y1>>x2>>y2>>x>>y;
	int m1 = abs(x2 - x1);
	int m2 = abs(y2 - y1);
	if((m1 % x) || (m2 % y))
	std::cout<<"NO\n";
	else
	{
		m1 /= x;
		m2 /= y;
		if(abs(m2 - m1) & 1)
		std::cout<<"NO\n";
		else std::cout<<"YES\n";
	}
	return 0;
}
