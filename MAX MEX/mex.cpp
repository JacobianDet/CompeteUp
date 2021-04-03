#include <bits/stdc++.h>

int main(void)
{
    long long T;
    std::cin>>T;
    for(long long i=0;i<T;i++)
    {
        long long n,k,mex=0,f=0;
        std::cin>>n>>k;
        std::vector<long long> x(n),cou(200001);
        for(long long j=0;j<n;j++)
        {
            std::cin>>x[j];
            cou[x[j]]++;
        }
        std::sort(x.begin(),x.end());
        for(long long j=0;j<k; )
        {
            if(mex == x[f])
            {
                f+=cou[x[f]];
                mex++;
            }
            if(mex != x[f])
            {
                mex++;
                j++;
            }
        }
        for( ;f<n;f+=cou[x[f]])
        {
            if(mex == x[f])
            mex++;
        }
        std::cout<<mex<<std::endl;
    }
    return 0;
}
