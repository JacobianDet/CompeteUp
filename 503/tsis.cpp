#include <bits/stdc++.h>

int main(void)
{
	int n,h,a,b,k;
	std::cin>>n>>h>>a>>b>>k;
	while(k--)
	{
		int ta,fa,tb,fb;
		std::cin>>ta>>fa>>tb>>fb;
		int mf1 = 0, mf2 = 0;
		if(fa < a)
		mf1 = a;
		else if(b < fa)
		mf1 = b;
		else mf1 = fa;
		if(fb < a)
		mf2 = a;
		else if(b < fb)
		mf2 = b;
		else mf2 = fb;	
		int dist = (ta == tb) ? abs(fa - fb) : (abs(ta - tb) + abs(mf1 - mf2) + abs(mf1 - fa) + abs(mf2 - fb));
		std::cout<<dist<<"\n";
	}
	return 0;
}