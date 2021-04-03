#include <bits/stdc++.h>

int main(void)
{
    long long T;
    std::cin>>T;
    for(long long i=0;i<T;i++)
    {
        long long N,Q;
        std::cin>>N>>Q;
        long long r[Q],c[Q];
        std::vector<long long> x(N);
        std::vector<std::vector<long long>> mx(N,x,-1);
        std::map <int,std::pair<long long,long long>> m;
        for(long long j=0;j<Q;j++)
        {
            std::cin>>r[j]>>c[j];
            std::cin>>mx[r[j]-1][c[j]-1];
        }
        m[0].first = r[0];
        m[0].second = c[0];
        for(long long j=0;j<Q;j++)
        {
           if(r[j] == c[j])
           {
               if(mx[r[j]-1][r[j]-1] != 0)
               std::cout<<"no"<<std::endl;
               break;
           }
           if(j != 0)
           {
                m[1].first = r[j];
                m[1].second = c[j];
                if(m[0].first == m[1].second && m[1].first == m[0].second)
                {
                    if(mx[m[0].first-1][m[0].second-1] != mx[m[1].first-1][m[1].second-1])
                    std::cout<<"no"<<std::endl;
                }
                else
                {

                }
           }

        }




    }
}
