#include <bits/stdc++.h>
#define INF 1000000000000

typedef long long ll;

struct trix
{
    ll dist;
    int x, y;
};

struct comp
{
        bool operator()(const trix& a, const trix& b)
        {
            return (a.dist > b.dist);
        }
};

std::pair<int, int> NE[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

std::string G[25];
bool vis[25][25];
ll dist[25][25];

void dijkstra_find(int n, int m, int sx, int sy)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            vis[i][j] = 0;
            dist[i][j] = INF;
        }
    }
    std::priority_queue<trix, std::vector<trix>, comp> P;
    dist[sx][sy] = 0;
    P.push({0, sx, sy});
    while(!P.empty())
    {
        trix z = P.top();
        P.pop();
        int x = z.x;
        int y = z.y;
        if(vis[x][y])
        continue;
        vis[x][y] = 1;
        if(G[x][y] == 'D')
        break;
        for(int i=0;i<4;i++)
        {
            int cx = x + NE[i].first;
            int cy = y + NE[i].second;
            if(0 <= cx && cx < n && 0 <= cy && cy < m && !vis[cx][cy] && G[cx][cy] != 'X')
            {
                if(G[x][y] == 'S')
                {
                    dist[cx][cy] = 0;
                    P.push({dist[cx][cy], cx, cy});
                }
                else if(dist[cx][cy] > (dist[x][y] + 1LL*(G[x][y] - '0')))
                {
                    dist[cx][cy] = dist[x][y] + 1LL*(G[x][y] - '0');
                    P.push({dist[cx][cy], cx, cy});
                }
            }
        }
    }
    return;
}

int main(void)
{
    int n,m;
    std::cin>>m>>n;
    while(n && m)
    {
        int sx = 0, sy = 0, dx = 0, dy = 0;
        for(int i=0;i<n;i++)
        std::cin>>G[i];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(G[i][j] == 'S')
                {
                    sx = i;
                    sy = j;
                }
                if(G[i][j] == 'D')
                {
                    dx = i;
                    dy = j;
                }
            }
        }
        dijkstra_find(n, m, sx, sy);
        std::cout<<dist[dx][dy]<<"\n";
        std::cin>>m>>n;
    }
    return 0;
}
