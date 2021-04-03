#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back
#define MV 605505
#define LM 25

int cord[MV], RW[MV], px[MV];
std::vector<std::string> Q;
std::map<char, int> crx;
std::set<char> Z;
std::string s;
int SA[LM][MV];
int x;

struct trip
{
    int x,y,id;
}L[MV];

class SAX
{
    public: void SA_build(int n);
            int LCP_find(int a, int b);
}T;

void counting_sort(int n)
{
    int count[MV+9];
    trip temp[n + 9];
    memset(count , 0 , sizeof count);

    for(int i = 0 ;i < n ; i++)
        count[L[i].y + 1]++;

    for(int i = 1 ; i  < MV ; i++)
        count[i] += count[i-1];

    for(int i = 0 ; i<n ; i++)
    {
        temp[count[L[i].y +1] - 1] = L[i];
        count[L[i].y + 1]--;
    }

    memset(count , 0 , sizeof count);

    for(int i = 0 ; i < n ; i ++)
        count[L[i].x + 1] ++;

    for(int i = 1 ; i<MV ; i++)
        count[i] += count[i-1];

    for(int i = n- 1; i>=0 ; i--)
    {
        L[count[temp[i].x + 1] - 1] = temp[i];
        count[temp[i].x + 1]--;
    }
}

void SAX::SA_build(int n)
{
    for(int i=0;i<n;i++)
    SA[0][i] = crx[s[i]];
    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<n;j++)
        {
            L[j].x = SA[i-1][j];
            L[j].y = (j + (1<<(i-1))) < n ? SA[i-1][j + (1<<(i-1))] : -1;
            L[j].id = j;
        }
        counting_sort(n);
        int u = 0;
        for(int j=0;j<n;j++)
        SA[i][L[j].id] = (j && (L[j].x == L[j-1].x) && (L[j].y == L[j-1].y)) ? SA[i][L[j-1].id] : u++;
    }
    for(int i=0;i<n;i++)
    RW[i] = L[i].id;
    return;
}

int SAX::LCP_find(int a, int b)
{
    int ans = 0;
    for(int k=x;k>=0;k--)
    {
        if(SA[k][a] == SA[k][b])
        {
            ans += (1<<k);
            a += (1<<k);
            b += (1<<k);
        }
    }
    return ans;
}

int bs1(int l, int lcp)
{
    int lo = 0;
    int hi = l;
    while(lo < hi)
    {
        int mid = lo + (hi - lo)/2;
        if(T.LCP_find(RW[mid], RW[l]) < lcp)
        lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int bs2(int r, int n, int lcp)
{
    int lo = r;
    int hi = n-1;
    while(lo < hi)
    {
        int mid = lo + (hi - lo + 1)/2;
        if(T.LCP_find(RW[mid], RW[r]) < lcp)
        hi = mid - 1;
        else lo = mid;
    }
    return lo;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
    memset(SA, -1, sizeof(SA));
    int m;
    std::cin>>m;
    int n = 0;
    for(int i=0;i<m;i++)
    {
        std::string sx;
        std::cin>>sx;
        Q.pb(sx);
        n += (int)sx.size();
        if(i < m-1)
        {
            n++;
            s += (sx + '$');
        }
        else s += sx;
    }
    for(int i=0;i<n;i++)
    Z.insert(s[i]);
    int u = 0;
    for(std::set<char>::iterator it=Z.begin();it != Z.end();it++)
    crx[*it] = u++;
    for(x=0;(1<<x)<=n;x++);
    T.SA_build(n);
    for(int i=0;i<n;i++)
    px[RW[i]] = i;
    u = 0;
    for(int i=0;i<m;i++)
    {
        cord[i] = px[u];
        u += ((int)Q[i].size() + 1);
    }
    int q;
    std::cin>>q;
    while(q--)
    {
        int l,r;
        std::cin>>l>>r;
        l--;
        r--;
        int a = cord[l];
        int b = cord[r];
        if(a > b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        int lcp = T.LCP_find(RW[a], RW[b]);
        lcp = std::min(lcp, (int)Q[l].size());
        lcp = std::min(lcp, (int)Q[r].size());
        if(!lcp)
        std::cout<<"0\n";
        else
        {
            int a1 = bs1(a, lcp);
            int a2 = bs2(b, n, lcp);
            int ans = (a2 - a1 + 1);
            std::cout<<ans<<"\n";
        }
    }
    return 0;
}
