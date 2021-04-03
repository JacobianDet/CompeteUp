#include <bits/stdc++.h>
#define mp std::make_pair

std::pair<int, int> C[1001];
int ctz[1001], arr[1001];

bool cmpx(std::pair<int, int> a, std::pair<int, int> b)
{
    if(a.second < b.second)
    return 1;
    else if((a.second == b.second) && (a.first < b.first))
    return 1;
    else return 0;
}

int main(void)
{
    int n;
    std::cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int s,d;
        std::cin>>s>>d;
        if(s < d)
        C[i] = mp(s, d);
        else C[i] = mp(d, s);
    }
    std::sort(C, C+n-1, cmpx);
    for(int i=0;i<n-1;i++)
    {
        ctz[C[i].first]++;
        ctz[C[i].second]++;
    }
    int ct = 0;
    bool ok = 1;
    for(int i=1;i<n;i++)
    {
        ct += ctz[i];
        if(ct > i)
        {
            ok = 0;
            break;
        }
    }
    if(ctz[n] != n-1)
    ok = 0;
    if(!ok)
    std::cout<<"NO\n";
    else
    {
        std::set<int> Z;
        for(int i=1;i<=n;i++)
        Z.insert(i);
        std::cout<<"YES\n";
        for(int i=0;i<n-1;i++)
        {
            if(!i)
            {
                arr[i] = C[i].first;
                Z.erase(arr[i]);
            }
            else
            {
                if(C[i].first > C[i-1].first)
                {
                    arr[i] = C[i].first;
                    Z.erase(arr[i]);
                }
                else
                {
                    arr[i] = *Z.begin();
                    Z.erase(Z.begin());
                }
            }
        }
        arr[n-1] = *Z.begin();
        Z.erase(Z.begin());
        for(int i=0;i<n-1;i++)
        std::cout<<arr[i]<<" "<<arr[i+1]<<"\n";
    }
    return 0;
}