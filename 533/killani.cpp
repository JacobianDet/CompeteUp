#include <bits/stdc++.h>
#define mp std::make_pair

std::pair<int, int> NE[4] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

int s[10], ans[10];
std::string G[1001];
int tx[1001][1001];
bool vis[1001][1001];
std::pair<int, int> sol[1001][1001];
int n,m;

struct amma
{
    int tv, p, x, y, lvl;
    bool operator < (const amma& ax) const
    {
	if(tv < ax.tv)
    	return 0;
	else if((tv == ax.tv) && (p < ax.p))
	return 0;
	else if((tv == ax.tv) && (p == ax.p) && (lvl < ax.lvl))
	return 0;
	else return 1;
    }	
};

void bfs_visit(int p)
{	
    std::priority_queue<amma> Q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
	    tx[i][j] = 10000001;	
            for(int x=0;x<p;x++)
	    {
		 char z = (char)(x + 1 + '0');	    
           	 if(G[i][j] == z)
           	 {
			tx[i][j] = 0;
			//std::cout<<i<<" "<<j<<" "<<(char)(p + 1 + '0')<<" "<<G[i][j]<<"\n";    
                	Q.push({tx[i][j], x, i, j, 0});
                	sol[i][j] = mp(0, x);
            	 }
	    }	 
        }
    }
    while(!Q.empty())
    {
        amma px = Q.top();
	Q.pop();
        int x = px.x;
        int y = px.y;
	if(vis[x][y])
	continue;	
	vis[x][y] = 1;	
	tx[x][y] = px.tv;
	//std::cout<<x<<" "<<y<<" "<<px.p<<" "<<px.tv<<"\n";	
	if(tx[x][y] < sol[x][y].first)
	{
		sol[x][y].first = tx[x][y];
		sol[x][y].second = px.p;
	}	
	else if(tx[x][y] == sol[x][y].first && px.p < sol[x][y].second)
	sol[x][y].second = px.p;	
        for(int i=0;i<4;i++)
        {
            int cx = x + NE[i].first;
            int cy = y + NE[i].second;
            if(cx >= 0 && cx < n && cy >= 0 && cy < m && G[cx][cy] == '.') 
            {
		//std::cout<<cx<<" "<<cy<<"\n";    
		int txx = 0;
		if((px.lvl + 1) % s[px.p])
		txx = 1 + (px.lvl + 1) / s[px.p];
		else txx = (px.lvl + 1) / s[px.p];
                Q.push({txx, px.p, cx, cy, 1 + px.lvl});	
            }	    
        }
    }
    return;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);    
    int p;
    std::cin>>n>>m>>p;
    for(int i=0;i<p;i++)
    std::cin>>s[i];
    for(int i=0;i<n;i++)
    std::cin>>G[i];
    for(int i=0;i<n;i++)
    {
	    for(int j=0;j<m;j++)
	    sol[i][j] = mp(10000001, 10000001);
    }	    
    bfs_visit(p);
    for(int i=0;i<n;i++)
    {
	    for(int j=0;j<m;j++)
	    {
		if(sol[i][j].second < p)    
	    	ans[sol[i][j].second]++;
	    }	
    }
    for(int i=0;i<p;i++)
    std::cout<<ans[i]<<" ";
    std::cout<<"\n";
    return 0;    
}
