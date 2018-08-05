#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back
#define indc std::vector<std::pair<int, int> >

char G[50][50];
int mpath[50][50];
int h,w;
std::pair<int, int> NE[8] ={{-1, -1}, {-1, 1}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, -1}, {1, 1}};

int dfs_visit(int x, int y)
{
    if(G[x][y] == 'Z')
    return 1; 
    if(mpath[x][y] != -1)
    return mpath[x][y];   
    int axe = 1;
    for(int i=0;i<8;i++)
    {
        int u = NE[i].first;
        int v = NE[i].second;
        int cx = x + u;
        int cy = y + v;
        if(0 <= cx && cx < h && 0 <= cy && cy < w && G[cx][cy] == G[x][y] + 1)
        axe = std::max(axe, 1 + dfs_visit(cx, cy));
    }   
    mpath[x][y] = axe;
    return axe;
}

int main(void)
{
    int t = 1;
    std::cin>>h>>w;
    while(h && w)
    {
        memset(mpath,-1,sizeof(mpath));
        indc Z;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                std::cin>>G[i][j];
                if(G[i][j] == 'A')
                Z.pb(mp(i,j));    
            }    
        }
        int maxm = 0;
        for(indc::iterator it = Z.begin(); it != Z.end(); it++)    
        {
            int x = it->first;
            int y = it->second;
            maxm = std::max(maxm, dfs_visit(x, y));
        }    
        std::cout<<"Case "<<t<<": "<<maxm<<"\n";
        t++;
        std::cin>>h>>w;
    }    
    return 0;
}