#include <bits/stdc++.h>

int main(void)
{
	int x,y,z,t1,t2,t3;
	std::cin>>x>>y>>z>>t1>>t2>>t3;
	if(abs(x-y)*t1 < abs(x-z)*t2+abs(x-y)*t2+3*t3)
	std::cout<<"NO\n";
	else std::cout<<"YES\n";
	return 0;	
}