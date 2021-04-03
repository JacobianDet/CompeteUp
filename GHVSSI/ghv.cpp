#include <bits/stdc++.h>

int ctr[4];
bool memo[2][301][301][301][4], vis[2][301][301][301][4];

bool GHV(int c0, int c1, int c2, int c3, int sx)
{
	if(sx == 2)
	return 1;
	else if(!c0 && !c1 && !c2 && !c3)
	return 0;
	if(vis[c0][c1][c2][c3][sx])
	return memo[c0][c1][c2][c3][sx];
	bool ans = 0;
	if(c0 > 0)
	ans |= (1 ^ GHV(c0 - 1, c1, c2, c3, sx));
	if(c1 > 0)
	ans |= (1 ^ GHV(c0, c1 - 1, c2, c3, (sx + 1)%4));
	if(c2 > 0)
	ans |= (1 ^ GHV(c0, c1, c2 - 1, c3, (sx + 2)%4));
	if(c3 > 0)
	ans |= (1 ^ GHV(c0, c1, c2, c3 - 1, (sx + 3)%4));		
	vis[c0][c1][c2][c3][sx] = 1;
	memo[c0][c1][c2][c3][sx] = ans;
	return ans;	
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    memset(memo, 0, sizeof(memo));
    memset(vis, 0, sizeof(vis));
    while(T--)
    {
        memset(ctr, 0, sizeof(ctr));
        int n;
        std::cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;
            std::cin>>x;
            ctr[x%4]++;
        }
        ctr[0] %= 2;
        bool ans = GHV(ctr[0], ctr[1], ctr[2], ctr[3], 0);
        if(ans)
        std::cout<<"Ghayeeth\n";
        else std::cout<<"Siroj\n";	
    }
    return 0;
}