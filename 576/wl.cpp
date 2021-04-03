#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll h,l;
	std::cin>>h>>l;
	ld ans = ((ld)h*h + (ld)l*l)/((ld)2 * (ld)h) - (ld)h;
	std::cout.setf(std::ios_base::fixed);
	std::cout<<std::setprecision(9)<<ans<<"\n";
	return 0;
}