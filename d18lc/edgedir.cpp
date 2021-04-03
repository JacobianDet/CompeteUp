#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

std::vector<int> G[100001];
std::pair<int, int> E[100001];
bool et[100001];
int degx[100001], indeg[100001], outdeg[100001];
std::map<std::pair<int, int>, int> MZ;

bool cmpx(int a, int b)
{
    if(degx[a] > degx[b])
    return 1;
    else if((degx[a] == degx[b]) && (indeg[a] > indeg[b]))
    return 1;
    else return 0;
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
        memset(et, 0, sizeof(et));
        int n,m;
        std::cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            int s,d;
            std::cin>>s>>d;
            G[s].pb(d);
            G[d].pb(s);
            E[i] = mp(s, d);
            MZ[mp(s, d)] = i;
            MZ[mp(d, s)] = i;
            degx[s]++;
            degx[d]++;
        }
        if(m & 1)
        std::cout<<"-1\n";
        else
        {
            std::set<std::pair<std::pair<std::pair<int, int>, int>, int> > SX;
            for(int i=1;i<=n;i++)
            SX.insert(mp(mp(mp(degx[i], indeg[i]), outdeg[i]), i));
            while(!SX.empty())
            {
                std::pair<std::pair<std::pair<int, int>, int>, int> p = *SX.begin();
                SX.erase(p);
                int u = p.second;
                bool ok1 = 0, ok2 = 0;
                int cx = 0;
                if((!(degx[u] & 1) && (indeg[u] & 1)) || ((degx[u] & 1) && !(indeg[u] & 1)))
                {
                    ok1 = 1;
                    cx += (degx[u] - 1);
                }
                else ok2 = 1;
                std::vector<int> VX(G[u].begin(), G[u].end());
                std::sort(VX.begin(), VX.end(), cmpx);
                for(auto v : VX)
                {
                    if(degx[v])
                    {
                        SX.erase(mp(mp(mp(degx[v], indeg[v]), outdeg[v]), v));
                        if(ok1)
                        {
                            if(!cx)
                            {
                                if(E[MZ[mp(u, v)]] != mp(u, v))
                                et[MZ[mp(u, v)]] = 1;
                                indeg[v]++;
                                outdeg[u]++;
                            }  
                            else
                            {
                                if(E[MZ[mp(v, u)]] != mp(v, u))
                                et[MZ[mp(u, v)]] = 1;
                                indeg[u]++; 
                                outdeg[v]++;
                                cx--; 
                            }    
                        }
                        else if(ok2)
                        {
                            if(E[MZ[mp(v, u)]] != mp(v, u))
                            et[MZ[mp(u, v)]] = 1;
                            indeg[u]++;
                            outdeg[v]++;
                        }
                        degx[v]--;
                        degx[u]--;
                        if(degx[v])
                        SX.insert(mp(mp(mp(degx[v], indeg[v]), outdeg[v]), v));   
                    }
                }
            }
            for(int i=0;i<m;i++)
            std::cout<<et[i]<<" ";
            std::cout<<"\n";
        }
        MZ.clear();
        for(int i=1;i<=n;i++)
        {
            G[i].clear();
            degx[i] = 0;
            indeg[i] = 0;
            outdeg[i] = 0;
        }
    }
    return 0;
}