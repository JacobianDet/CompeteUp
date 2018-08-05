#include <bits/stdc++.h>

int lcp[1000001];

int main(void)
{
    int T;
    std::cin>>T;
    for(int t=1;t<=T;t++)
    {
        int n;
        std::cin>>n;
        std::string s;
        std::cin>>s;
        lcp[0] = 0;
        for(int i=1;i<n;i++)
        {
            int j = lcp[i-1];
            while(j && (s[i] != s[j]))
            j = lcp[j-1];
            if(s[i] == s[j])
            j++;
            lcp[i] = j;
        }
        std::cout<<"Test case #"<<t<<"\n";
        for(int i=2;i<=n;i++)
        {
            int k = i - lcp[i-1];
            if((k != i) && !(i%k))
            std::cout<<i<<" "<<i/k<<"\n";
        }
    }
    return 0;
}
