#include <bits/stdc++.h>

/* for elem 0 = air
			1 = fire
			2 = water
*/			
int memo[3][2000][2000];

int vict(int elem, int h, int a)
{
	if(h <= 0 || a <= 0)
	return -1;
	if(memo[elem][h][a] != -1)
	return memo[elem][h][a];	
	int ans = 0;
	if(elem == 1 || elem == 2)
	ans = 1 + vict(0, h+3, a+2);
	else ans = 1 + std::max(vict(1, h-20, a+5), vict(2, h-5, a-10));
	memo[elem][h][a] = ans;
	return ans;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{
		memset(memo, -1, sizeof(memo));
		int h,a;
		std::cin>>h>>a;
		int ans = std::max(vict(1, h, a), vict(2, h, a));
		std::cout<<ans<<"\n";
	}	
	return 0;
}