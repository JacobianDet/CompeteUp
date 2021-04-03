#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back

int arr[101];
int n;
bool memo[101][8];
bool use[101][8];
std::pair<int, int> par[101][8];

int main(void)
{
    memset(memo, 0, sizeof(memo));
    memset(use, 0, sizeof(use));
    std::string s;
    std::cin>>s;
    n = (int)s.size();
    for(int i=0,j=(int)s.size();i<j;i++)
    arr[i+1] = (s[i] - '0');
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<8;j++)
        par[i][j] = mp(i, j);
    }
    for(int i=1;i<=n;i++)
    {
        memo[i][(arr[i] % 8)] = 1;
        use[i][(arr[i] % 8)] = 1;
        for(int j=0;j<8;j++)
        {
            if(memo[i-1][j] && !memo[i][(10*j + arr[i])%8])
            {
                par[i][(10*j + arr[i])%8] = mp(i-1, j);
                use[i][(10*j + arr[i])%8] = 1;
                memo[i][(10*j + arr[i])%8] |= memo[i-1][j];
            }
            if(memo[i-1][j] && !memo[i][j])
            {
                par[i][j] = mp(i-1, j);
                memo[i][j] |= memo[i-1][j];
            }
        }
    }
    bool f = 0;
    std::vector<int> Z;
    for(int i=1;i<=n;i++)
    {
        if(memo[i][0])
        {
            int x = i;
            int y = 0;
            while(mp(x, y) != par[x][y])
            {
                //std::cout<<x<<" "<<y<<"\n";
                if(use[x][y])
                Z.pb(arr[x]);
                std::pair<int, int> p = par[x][y];
                x = p.first;
                y = p.second;
            }
            //std::cout<<x<<" "<<y<<"\n";
            if(use[x][y])
            Z.pb(arr[x]);
            f = 1;
            break;
        }
    }
    if(!f)
    std::cout<<"NO\n";
    else
    {
        std::cout<<"YES\n";
        std::reverse(Z.begin(), Z.end());
        for(int i=0,j=(int)Z.size();i<j;i++)
        std::cout<<Z[i];
        std::cout<<"\n";
    }
    return 0;
}
