#include <bits/stdc++.h>

typedef long long ll;

ll memo[(1<<24)];

int main(void)
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++)
    {
        std::string s;
        std::cin>>s;
        int mask = 0;
        mask |= (1<<(s[0] - 'a'));
        mask |= (1<<(s[1] - 'a'));
        mask |= (1<<(s[2] - 'a'));
        memo[mask]++;
    }
    for(int p=0;p<24;p++)
    {
        for(int mask=0; mask<(1<<24); mask++)
        {
            if(mask & (1<<p))
            memo[mask] += memo[mask ^ (1<<p)];
        }
    }
    ll ans = 0;
    for(int mask = 0; mask<(1<<24); mask++)
    ans ^= ((n-memo[mask]) * (n-memo[mask]));
    std::cout<<ans<<"\n";
    return 0;
}