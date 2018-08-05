#include <bits/stdc++.h>
#define mp std::make_pair
#define INF 100000000

std::pair<int, int> NE[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int G1[100][100], G2[100][100], G3[100][100];

void bfs_mou(int n, int m, int mx, int my)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        G1[i][j] = INF;
    }
    G1[mx][my] = 0;
    std::queue<std::pair<int, int> > Q;
    Q.push(mp(mx, my));
    while(!Q.empty())
    {
        std::pair<int, int> p = Q.front();
        Q.pop();
        int x = p.first;
        int y = p.second;
        for(int i=0;i<4;i++)
        {
            int cx = x + NE[i].first;
            int cy = y + NE[i].second;
            if(0 <= cx && cx < n && 0 <= cy && cy < m)
            {
                if(G1[cx][cy] > G1[x][y] + 1)
                {
                    G1[cx][cy] = G1[x][y] + 1;
                    Q.push(mp(cx, cy));
                }
            }
        }
    }
    return;
}

void bfs_c1(int n, int m, int c1x, int c1y)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        G2[i][j] = INF;
    }
    G2[c1x][c1y] = 0;
    std::queue<std::pair<int, int> > Q;
    Q.push(mp(c1x, c1y));
    while(!Q.empty())
    {
        std::pair<int, int> p = Q.front();
        Q.pop();
        int x = p.first;
        int y = p.second;
        for(int i=0;i<4;i++)
        {
            int cx = x + NE[i].first;
            int cy = y + NE[i].second;
            if(0 <= cx && cx < n && 0 <= cy && cy < m)
            {
                if(G2[cx][cy] > G2[x][y] + 1)
                {
                    G2[cx][cy] = G2[x][y] + 1;
                    Q.push(mp(cx, cy));
                }
            }
        }
    }
    return;
}

void bfs_c2(int n, int m, int c2x, int c2y)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        G3[i][j] = INF;
    }
    G3[c2x][c2y] = 0;
    std::queue<std::pair<int, int> > Q;
    Q.push(mp(c2x, c2y));
    while(!Q.empty())
    {
        std::pair<int, int> p = Q.front();
        Q.pop();
        int x = p.first;
        int y = p.second;
        for(int i=0;i<4;i++)
        {
            int cx = x + NE[i].first;
            int cy = y + NE[i].second;
            if(0 <= cx && cx < n && 0 <= cy && cy < m)
            {
                if(G3[cx][cy] > G3[x][y] + 1)
                {
                    G3[cx][cy] = G3[x][y] + 1;
                    Q.push(mp(cx, cy));
                }
            }
        }
    }
    return;
}

int main(void)
{
    int n,m;
    std::cin>>n>>m;
    int T;
    std::cin>>T;
    while(T--)
    {
        int mx, my, c1x, c1y, c2x, c2y;
        std::cin>>mx>>my>>c1x>>c1y>>c2x>>c2y;
        mx--;
        my--;
        c1x--;
        c1y--;
        c2x--;
        c2y--;
        bfs_mou(n, m, mx, my);
        bfs_c1(n, m, c1x, c1y);
        bfs_c2(n, m, c2x, c2y);
        bool ok = 0;
        for(int i=0;i<n;i++)
        {
            if((G1[i][0] < G2[i][0]) && (G1[i][0] < G3[i][0]))
            {
                ok = 1;
                break;
            }
            if((G1[i][m-1] < G2[i][m-1]) && (G1[i][m-1] < G3[i][m-1]))
            {
                ok = 1;
                break;
            }
        }
        for(int i=0;i<m;i++)
        {
            if((G1[0][i] < G2[0][i]) && (G1[0][i] < G3[0][i]))
            {
                ok = 1;
                break;
            }
            if((G1[n-1][i] < G2[n-1][i]) && (G1[n-1][i] < G3[n-1][i]))
            {
                ok = 1;
                break;
            }
        }
        if(ok)
        std::cout<<"YES\n";
        else std::cout<<"NO\n";
    }
    return 0;
}
