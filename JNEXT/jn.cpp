#include <bits/stdc++.h>

int arr[1000001];

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    while(T--)
    {
        int n;
        std::cin>>n;
        for(int i=0;i<n;i++)
        std::cin>>arr[i];
        std::multiset<int> Z;
        bool ok = 0;
        for(int i=n-1;i>=0;i--)
        {
            Z.insert(arr[i]);
            std::multiset<int>::iterator it = Z.upper_bound(arr[i]);
            if(it != Z.end())
            {
                ok = 1;
                for(int j=0;j<i;j++)
                std::cout<<arr[j];
                std::cout<<*it;  
                Z.erase(it);
                break;
            }
        }
        if(!ok)
        std::cout<<"-1\n";
        else
        {
            for(std::multiset<int>::iterator it=Z.begin();it != Z.end();it++)
            std::cout<<*it;
            std::cout<<"\n";
        }
    }
    return 0;
}