#include <bits/stdc++.h>

std::set<int> R, C;

int main(void)
{
    int T;
    std::cin>>T;
    while(T--)
    {
        int n,k;
        std::cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            R.insert(i);
            C.insert(i);   
        }   
        for(int i=0;i<k;i++)
        {
            int r,c;
            std::cin>>r>>c;
            R.erase(r);
            C.erase(c);
        }
        int ax = n-k;
        std::cout<<ax<<" ";
        while(ax > 0)
        {
            int zx1 = *R.begin();
            int zx2 = *C.begin();
            std::cout<<zx1<<" "<<zx2<<" ";
            R.erase(R.begin());
            C.erase(C.begin());
            ax--;
        }
    }
    return 0;
}