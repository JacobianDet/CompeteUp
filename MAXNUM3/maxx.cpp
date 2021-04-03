#include <bits/stdc++.h>

int main(void)
{
    int T;
    std::cin>>T;
    for(int i=0;i<T;i++)
    {
        std::string s;
        std::cin>>s;
        std::vector<int> z;
        long long sum = 0;
        long long k = s.size();
        for(long long j=0;j<k;j++)
        {
            z.push_back(s[j]-'0');
            sum += (s[j]-'0');
        }
        if(z[k-1] & 1)
        {
            if((z[k-2] & 1) || (!(z[k-2] & 1) && (sum-z[k-1])%3 != 0))
            std::cout<<-1<<"\n";
            else {
                  for(long long j=0;j<k;j++)
                  {
                      if(j == k-1)
                      continue;
                      else std::cout<<z[j];
                  }
                  std::cout<<"\n";
            }
        }
        else {
             long long chor=0;
             for(long long j=0;j<k;j++)
             {
                 if(j != k-1 && (sum-z[j])%3 == 0)
                 chor++;
                 else if(j == k-1 && (sum-z[j])%3 == 0 && !(z[j-1] & 1))
                 chor++;
             }
             if(chor == 0)
             std::cout<<-1<<"\n";
             else {
                   for(long long j=0;j<k;j++)
                   {
                       if((chor > 0 && (sum-z[j])%3 == 0 && z[j] < z[j+1]) || (chor == 1 && (sum-z[j])%3 == 0))
                       {
                            chor = 0;
                            continue;
                       }
                       else if((sum-z[j])%3 == 0 && (chor > 1 && z[j] >= z[j+1]))
                       {
                           chor--;
                           std::cout<<z[j];
                       }
                       else std::cout<<z[j];
                   }
                   std::cout<<"\n";
             }
        }
    }
    return 0;
}
