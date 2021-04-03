#include <bits/stdc++.h>
#define pb push_back
#define CHOR 1000001
#define INF 100000001

std::vector<int> GT[CHOR];
std::vector<int> res[CHOR];
int indeg[CHOR], lvl[CHOR], par[CHOR];
std::queue<int> Z;

void bfs_visit(int n)
{
    std::queue<int> Q;
    for(int i=1;i<=n;i++)
    {
        if(!indeg[i])
        {
            lvl[i] = 0;
            par[i] = i;
            Q.push(i);
        }    
    }
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        Z.push(u);
        for(auto v : GT[u])
        {
            indeg[v]--;
            if(!indeg[v])
            {
                par[v] = u;
                lvl[v] = 1 + lvl[u];
                Q.push(v);
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
    int n,m;
    std::cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int s,d;
        std::cin>>s>>d;
        GT[d].pb(s);
        indeg[s]++;
    }
    bfs_visit(n);
    int st = 0;
    while(!Z.empty())
    {
        st++;
        int u = Z.front();
        Z.pop();
        if(!Z.empty())
        {
            int v = Z.front();
            if(lvl[u] == lvl[v])
            {
                res[st].pb(2);
                res[st].pb(u);
                res[st].pb(v);
                Z.pop();
            }
            else if((lvl[v] == lvl[u] + 1) && (par[v] != u))
            {
                res[st].pb(2);
                res[st].pb(u);
                res[st].pb(v);
                Z.pop();
            } 
            else
            {
                res[st].pb(1);
                res[st].pb(u);
            }   
        }
        else
        {
            res[st].pb(1);
            res[st].pb(u);
        } 
    }
    std::cout<<st<<"\n";
    for(int i=1;i<=st;i++)
    {
        for(int j=0,k=(int)res[i].size();j<k;j++)
        std::cout<<res[i][j]<<" ";
        std::cout<<"\n";

    }
    return 0;
}