#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

struct DSU
{
	int connected;
	vector<int> par, sz, mn, mx;

	DSU() {} 

	void init(int n) 
	{
		par = sz = mn = mx = vector<int> (n + 5, 0);
		for(int i = 1; i <= n; i++)
		{
			par[i] = i;
			sz[i] = 1;
			mn[i] = mx[i] = i;
		}
		connected = n;
	}

	int getPar(int k)
	{
		while(k!=par[k])
		{
			par[k]=par[par[k]];
			k=par[k];
		}
		return k;
	}

	int getSize(int k)
	{
		return sz[getPar(k)];
	}

	int getMn(int k)
	{
		return mn[getPar(k)];
	}

	int getMx(int k)
	{
		return mx[getPar(k)];
	}

	void unite(int u, int v)
	{
		int par1=getPar(u), par2=getPar(v);

		if(par1==par2)
			return;

		connected--;

		if(sz[par1]>sz[par2])
			swap(par1, par2);

		sz[par2]+=sz[par1];
		mn[par2] = min(mn[par2], mn[par1]);
		mx[par2] = max(mx[par2], mx[par1]);
		sz[par1]=0;
		par[par1]=par[par2];
	}
};

int n, q;
int a[N], s[N], k[N], answer[N];
int lo[N], mid[N], hi[N], storeL[N], storeR[N];
vector<int> vec[N];
DSU dsu;
map<int, int> idx;

void apply(int val) //Apply ith update/query
{
	if(!idx.count(val))
		return;
	int pos = idx[val];
	dsu.unite(pos, pos + 1);
}

bool check(int idx) //Check if the condition is satisfied
{
	int sz = dsu.getSize(s[idx]);
	int reqd = k[idx];
	storeL[idx] = dsu.getMn(s[idx]);
	storeR[idx] = dsu.getMx(s[idx]);
	return sz >= reqd;
}	

void work()
{	
	for(int i = 1; i <= 1e5; i++)
		vec[i].clear();
	for(int i = 1; i <= q; i++)
		if(mid[i] > 0)
			vec[mid[i]].push_back(i);
	dsu.init(n);
	for(int i = 1; i <= 1e5; i++)
	{
		apply(i);
		for(auto &it:vec[i]) //Add appropriate check conditions
		{
			if(check(it))
				hi[it] = i;
			else
				lo[it] = i + 1;
		}
	}
}

void parallel_binary()
{
	for(int i = 1; i <= q; i++)
		lo[i] = 1, hi[i] = 1e5;
	bool changed = 1;
	while(changed)
	{
		changed = 0;
		for(int i = 1; i <= q; i++)
		{
			if(lo[i] < hi[i])
			{
				changed = 1;
				mid[i] = (lo[i] + hi[i]) / 2;
			}	
			else
				mid[i] = -1;
		}
		work();
	}
}

void final()
{
	for(int i = 1; i <= q; i++)
		vec[lo[i]].push_back(i);
	dsu.init(n);
	for(int i = 1; i <= 1e5; i++)
	{
		for(auto &cur:vec[i]) //Add appropriate check conditions
		{
			int curSz = dsu.getSize(s[cur]);
			int val = i;
			int pos = idx[val];
			int left = k[cur] - curSz;
			if(pos >= s[cur])
				answer[cur] = dsu.getMx(s[cur]) + left;
			else
				answer[cur] = dsu.getMn(s[cur]) - left;
		}
		apply(i);
	}
	for(int i = 1; i <= q; i++)
	{
		if(k[i] == 1)
			answer[i] = s[i];
		cout << answer[i] << " ";
	}
	cout << endl;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	int tc = 0;
	while(t--)
	{
		idx.clear();
		tc++;
		cin >> n >> q;
		for(int i = 1; i <= n - 1; i++)
		{
			cin >> a[i];
			idx[a[i]] = i;
		}
		for(int i = 1; i <= q; i++)
			cin >> s[i] >> k[i];
		parallel_binary();
		cout << "Case #" << tc << ": ";
		final();
	}
	return 0;
}