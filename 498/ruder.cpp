#include <bits/stdc++.h>
#define pb push_back

int arr[2001];
std::multiset<int, std::greater<int> > Z; 
std::multiset<int> V;

int main(void)
{
    int n,k;
    std::cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int t;
        std::cin>>t;
        arr[i] = t;
        Z.insert(t);
    }
    int sum = 0, x = 0;
    for(std::multiset<int>::iterator it = Z.begin();it != Z.end();it++)
    {
        if(x == k)
        break;
        sum += (*it);
        V.insert(*it);
        x++;
    }
    std::cout<<sum<<"\n";
    x = 0;
    int lv = 0;
    for(int i=0;i<n;i++)
    {
        if(x == k-1)
        break;
        std::multiset<int>::iterator it = V.lower_bound(arr[i]);
        if((it != V.end()) && (*it == arr[i]))
        {
            std::cout<<(i - lv + 1)<<" ";
            lv = i+1;
            V.erase(it);
            x++;
        }
    }
    std::cout<<(n - lv)<<"\n";
    return 0;
}