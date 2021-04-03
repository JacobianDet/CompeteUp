#include <bits/stdc++.h>
#define CHOR 100001

typedef long long ll;

ll BIT1[27], BIT2[27];
std::string s;
int n;

class fentree
{
    public: void build(ll BIT[]);
            void update(ll BIT[], int i, ll val);
            ll query(ll BIT[], int i);
};

void fentree::build(ll BIT[])
{
    for(int i=1;i<=26;i++)
    BIT[i] = 0;
    return;
}

void fentree::update(ll BIT[], int i, ll val)
{
    for( ;i<=26;i+=(i & (-i)))
    BIT[i] += val;
    return;
}

ll fentree::query(ll BIT[], int i)
{
    ll sum = 0;
    for( ;i>0;i-=(i & (-i)))
    sum += BIT[i];
    return sum;
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
        std::cin>>s;
        n = (int)s.size();
        fentree D;
        D.build(BIT1);
        D.build(BIT2);
        ll ta = 0;
        ll ans = 1000000000000;
        for(int i=0;i<n;i++)
        {
            ta += D.query(BIT2, (s[i] - 97));
            D.update(BIT2, (s[i] - 96), 1);
        }
        //std::cout<<ta<<"\n";
        for(int i=0;i<n;i++)
        {
            D.update(BIT2, (s[i] - 96), -1);
            for(int j=1;j<=26;j++)
            {
                ll tx = 0;
                tx = ta - D.query(BIT1, (s[i] - 97)) - D.query(BIT2, 26) + D.query(BIT2, (s[i] - 96)) + abs((s[i] - 96) - j) + D.query(BIT1, j-1) + (D.query(BIT2, 26) - D.query(BIT2, j));
                //std::cout<<tx<<"\n";
                ans = std::min(ans, tx);
            }
            D.update(BIT1, (s[i] - 96), 1);
        }
        std::cout<<ans<<"\n";
    }
    return 0;
}

