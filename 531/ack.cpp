#include <bits/stdc++.h>
#define pb push_back

std::vector<int> pos[5001];
int col[5001], cx[5001];
bool use[5001];

int main(void)
{
    int n,k;
    std::cin>>n>>k;
    int mx = 0;
    for(int i=0;i<n;i++)
    {
        int x;
        std::cin>>x;
        pos[x].pb(i);
        mx = std::max(mx, x);
    }
    bool ok = 1;
    for(int i=1;i<=mx;i++)
    {
        if((int)pos[i].size() > k)
        {
            ok = 0;
            break;
        }
        else
        {
            memset(use, 0, sizeof(use));
            for(int j=0,z=(int)pos[i].size();j<z;j++)
            {
                for(int x=1;x<=k;x++)
                {
                    if(!cx[x])
                    {
                        use[x] = 1;
                        col[pos[i][j]] = x;
                        cx[x]++;
                        break;
                    }    
                }
                if(!col[pos[i][j]])
                {
                    for(int x=1;x<=k;x++)
                    {
                        if(!use[x])
                        {
                            use[x] = 1;
                            col[pos[i][j]] = x;
                            cx[x]++;
                            break;
                        }    
                    }
                }
            }         
        }
    }
    for(int i=1;i<=k;i++)
    {
        if(!cx[i])
        {
            ok = 0;
            break;
        }
    }
    if(ok)
    {
        std::cout<<"YES\n";
        for(int i=0;i<n;i++)
        std::cout<<col[i]<<" ";
        std::cout<<"\n";
    }
    else std::cout<<"NO\n";
    return 0;
}