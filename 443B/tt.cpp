#include <bits/stdc++.h>

int main(void)
{
    long long n,k;
    std::cin>>n>>k;
    std::vector<long long> a(n);
    for(long long i=0;i<n;i++)
    std::cin>>a[i];
    long long maxx=a[0],i=1;
    std::queue<long long> q;
    while(q.size() < k && i < n)
    {
        if(maxx > a[i])
        q.push(a[i]);
        else {
             while(!q.empty())
             q.pop();
         	 q.push(maxx);
             maxx = a[i];
        }
        i++;
    }
    std::cout<<maxx<<"\n";
    return 0;
}
