#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

std::vector<int> vx; 

int main(void)
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		std::cin>>x;
		vx.pb(x);
	}	
	std::sort(vx.begin(), vx.end());
	int p1 = 0, p2 = (int)vx.size() - 1;
	ll ans = 0;
	while(p1 < p2)
	{
		ans += ((1LL * (vx[p1] + vx[p2])) * (1LL * (vx[p1] + vx[p2])));
		p1++;
		p2--; 
	}
	std::cout<<ans<<"\n";
	return 0;
}