#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

typedef long long ll;

std::vector<std::string> Z;
std::vector<std::pair<ll, ll> > X[26][26];
ll ssz[26];

bool cmpx(std::pair<ll, ll> A, std::pair<ll, ll> B)
{
    if(A.first > B.first)
    return 1;
    else if((A.first == B.first) && (A.second > B.second))
    return 1;
    else return 0;
}

int main(void)
{
    int T;
    std::cin>>T;
    while(T--)
    {
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            X[i][j].clear();
        }
        Z.clear();
        memset(ssz, 0, sizeof(ssz));
        int n;
        std::cin>>n;
        std::string s;
        std::cin>>s;
        std::string z = "";
        for(int i=0;i<n-1;i++)
        {
            if(s[i] == s[i+1])
            z += s[i];
            else
            {
                z += s[i];
                Z.pb(z);
                z = "";
            }
        }
        z += s[n-1];
        Z.pb(z);
        for(int i=0,j=(int)Z.size();i<j-1;i++)
        {
            X[Z[i][0] - 'a'][Z[i+1][0] - 'a'].pb(mp((ll)Z[i].size(), (ll)Z[i+1].size()));
            ssz[Z[i][0] - 'a'] = std::max(ssz[Z[i][0] - 'a'], (ll)Z[i].size());
        }    
        ssz[Z[(int)Z.size()-1][0] - 'a'] = std::max(ssz[Z[(int)Z.size()-1][0] - 'a'], (ll)Z[(int)Z.size()-1].size());
        ll ans = 0;
        for(int i=0;i<26;i++)
        ans += ssz[i];
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                if((i != j) && ((int)X[i][j].size() > 0))
                {
                    std::sort(X[i][j].begin(), X[i][j].end(), cmpx);
                    int k = 1, pk = 0;
                    ans += X[i][j][0].first * X[i][j][0].second;
                    while(k < (int)X[i][j].size())
                    {
                        if((X[i][j][pk].first >= X[i][j][k].first) && (X[i][j][pk].second >= X[i][j][k].second))
                        k++;
                        else
                        {
                            ans += X[i][j][k].first * (X[i][j][k].second - X[i][j][pk].second);
                            pk = k;
                            k++;
                        }
                    }
                }
            }
        }
        std::cout<<ans<<"\n";
    }
    return 0;
}