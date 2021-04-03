#include <bits/stdc++.h>
#define CHOR 1000000007

 std::unordered_map<long long,std::tuple<long long,long long,long long>> mx;
 std::unordered_map<long long,std::vector<long long>> memo;
long long pos=0,m;

 void commando(long long f,std::vector<long long>& z,long long n)
 {
     if(f == m+1)
     return;
     if(!memo[f].empty())
     {
         for(long long i=0;i<n;i++)
         {
             if(memo[f][i] == 0)
             continue;
             memo[pos][i] = ((memo[pos][i]%CHOR) + (memo[f][i]%CHOR));
         }
         return;
     }
     long long t,l,r;
     std::tie (t, l, r) = mx[f];
     if(t == 1)
     {
         memo[f].resize(n);
         for(long long i = l-1;i < r;i++)
         memo[f][i] = (memo[f][i]%CHOR + 1)%CHOR;
     }
     else if(t == 2)
     {
         pos = f;
         memo[f].resize(n);
         for(long long i = l;i <= r;i++)
         commando(i,z,n);
     }
     for(long long i=0;i<n;i++)
     {
         if(memo[f][i] == 0)
         continue;
         z[i] = (z[i]%CHOR + memo[f][i]%CHOR)%CHOR;
     }
     commando(f+1,z,n);
 }

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin>>T;
    for(int i=0;i<T;i++)
    {
        long long n,t,l,r;
        std::cin>>n>>m;
        std::vector<long long> x(n,0);
        for(long long j=1;j<=m;j++)
        {
            std::cin>>t>>l>>r;
            mx[j] = std::make_tuple (t, l, r);
        }
        commando(1,x,n);
        for(int j=0;j<n;j++)
        std::cout<<x[j]<<" ";
        std::cout<<std::endl;
        memo.clear();
        mx.clear();
    }
    return 0;
}

