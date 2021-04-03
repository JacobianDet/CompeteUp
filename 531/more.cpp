#include <bits/stdc++.h>
#define pb push_back
#define MOD 998244353

typedef long long ll;

std::map<int, std::vector<int> > mvx;
int arr[200001], rank[200001], lst[200001];

class dsu
{
	public: int root(int x);
			void find_union(int x, int y); 
};

int dsu::root(int x)
{
	return (x == arr[x]) ? x : (arr[x] = root(arr[x]));
}

void dsu::find_union(int x, int y)
{
	int rx = root(x);
	int ry = root(y);
	if(rx == ry)
	return;
	if(rank[ry] > rank[rx])
	{
		int tmp = ry;
		ry = rx;
		rx = tmp;
	}	
	arr[ry] = rx;
    if(lst[rx] < lst[ry])
    lst[rx] = lst[ry];
    if(rank[rx] == rank[ry])
	rank[rx]++;
	return;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
    int n;
    std::cin>>n;
    for(int i=1;i<=n;i++)
    {
        arr[i] = i;
        rank[i] = 0;
        lst[i] = i;
    }
    for(int i=1;i<=n;i++)
    {
        int x;
        std::cin>>x;
        mvx[x].pb(i);
    }
    dsu T;
    for(std::map<int, std::vector<int> >::iterator it = mvx.begin();it != mvx.end();it++)
    {
        std::vector<int> Z((it->second).begin(), (it->second).end());
        for(int i=0,j=(int)Z.size();i<j-1;i++)
        T.find_union(Z[i], Z[i+1]);
    }
    std::set<int> Z;
    ll ans = 1;
    int tx = lst[T.root(1)];
    for(int i=1;i<=n;i++)
    {
        if(i <= tx)
        {
            T.find_union(tx, i);
            tx = lst[T.root(tx)];
        }
        else
        {
            tx = lst[T.root(i)];
            ans = ((ans%MOD) * (2%MOD))%MOD;
        }
    }
    std::cout<<ans<<"\n";
    return 0;
}