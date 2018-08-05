#include <bits/stdc++.h>
#define pb push_back

struct doll
{
    int w,h;
};

doll arr[20001];
std::vector<doll> vsz;

bool comp(doll a, doll b)
{
    if((a.w < b.w))
    return 1;
    else if((a.w == b.w) && (a.h > b.h))
    return 1;
    else return 0;
}

void bs1(int i)
{
    int lo = 0;
    int hi = (int)vsz.size()-1;
    while(lo < hi)
    {
        int mid = lo + (hi - lo)/2;
        if((vsz[mid].w <= arr[i].w) || (vsz[mid].h <= arr[i].h))
        lo = mid + 1;
        else hi = mid;
    }
    if(vsz[lo].w <= arr[i].w || vsz[lo].h <= arr[i].h)
    vsz.pb(arr[i]);
    else
    {
        vsz[lo].w = arr[i].w;
        vsz[lo].h = arr[i].h;
    }
    return;
}

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
        for(int i=1;i<=n;i++)
        std::cin>>arr[i].w>>arr[i].h;
        std::sort(arr+1, arr+n+1, comp);
        vsz.pb(arr[n]);
        for(int i=n-1;i>0;i--)
        bs1(i);
        std::cout<<(int)vsz.size()<<"\n";
        vsz.clear();
    }
    return 0;
}
