#include <bits/stdc++.h>
#define CHOR 5001
#define pb push_back
 
std::vector<bool> pr(CHOR, true);
std::vector<int> a(CHOR,-1);
std::vector<std::vector<int> > memo(CHOR, a);
 
void siever(void)
{
    pr[0] = false;
    pr[1] = false;
    for(int i=2;i*i<CHOR;i++)
    {
        if(pr[i])
        {
            for(int j=i*i;j<CHOR;j+=i)
            {
                if(pr[j])
                pr[j] = false;
            }
        }
    }
    return;
}
 
int selt(std::vector<int>& x, int t, int c)
{
    int n = x.size();
    if(t == n)
    return 0;
    if(memo[t][c] != -1)
    return memo[t][c];
    int ans = 0;
    if(pr[c] || !c)
    {
        for(int i=1;i<=n-t;i++)
        {
            if(pr[c+i])
            {
                ans = std::max(x[t]+selt(x,t+1,c+1),ans);
                break;
            }    
        }
        ans = std::max(ans,selt(x,t+1,0));
    }
    else ans = std::max(ans,x[t] + selt(x,t+1,c+1));
    memo[t][c] = ans;
    return ans;
}
 
int main(void)
{
    siever();
    int n;
    std::cin>>n;
    std::vector<int> x(n);
    for(int i=0;i<n;i++)
    std::cin>>x[i];
    int ans = selt(x,0,0);
    std::cout<<ans<<"\n";
    memo.clear();
    return 0;
}