#include <bits/stdc++.h>
#define CHOR 1000000007

 std::map<long long,std::string> mx;

 void commando(long long f,std::vector<long long>& z)
 {
     int m = 0;
     std::string x;
     long long t[3];
     for(int i = 0,j = (int)mx[f].size();i<j;i++)
     {
        if(mx[f][i] == ' ')
        {
            t[m] = std::atoll(x.c_str());
            x="";
            m++;
        }
        else x += mx[f][i];
     }
     t[m] = std::atoll(x.c_str());
     if(t[0] == 1)
     {
         for(long long i = t[1]-1;i < t[2];i++)
         z[i] = (z[i]%CHOR + 1)%CHOR;
     }
     else if(t[0] == 2)
     {
         for(long long i = t[1];i <= t[2];i++)
         commando(i,z);
     }
     return;
 }

int main()
{
    int T;
    std::cin>>T;
    for(int i=0;i<T;i++)
    {
        long long n,m;
        std::cin>>n>>m;
        std::cin.ignore();
        std::vector<long long> x(n,0);
        for(long long j=1;j<=m;j++)
        {
            std::getline(std::cin,mx[j]);
            commando(j,x);
        }
        for(int j=0;j<n;j++)
        std::cout<<x[j]<<" ";
        std::cout<<std::endl;
    }
    return 0;
}
