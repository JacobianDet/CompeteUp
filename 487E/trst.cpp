#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define MV 200001
#define LMV 21
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define emp emplace
#define mp make_pair
#define ins insert
#define sz size
#define whoami(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); whi(_it, args); }

void whi(istream_iterator<string> it) { cerr<<"\n"; }

template<typename T, typename... Args>
void whi(istream_iterator<string> it, T a, Args... args) { cerr<<*it<<" "<<a<<" "; whi(++it, args...); }

void FLASH() {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
void SETF() {cout.ios_base::setf(ios_base::fixed); cerr.ios_base::setf(ios_base::fixed);}
void UNSETF() {cout.ios_base::unsetf(ios_base::fixed); cerr.ios_base::unsetf(ios_base::fixed);}

typedef long long ll;
typedef long double ld;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<PII, int> PPII;
typedef pair<PLL, ll> PPLL;
typedef map<int, int> MII;

const int MOD = 1000000007;
const ll INF = 4e18;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct h_llint {
  static uint64_t splitmix64(uint64_t x) {    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

struct h_pair{
  size_t operator()(const PLL&x)const{
    return hash<ll>()(((ll)x.ff)^(((ll)x.ss)<<32));
  }
};

typedef map<ll, ll> MLL;
typedef map<PII, int> MPII;
typedef map<PLL, ll> MPLL;
typedef set<int> SI;
typedef set<ll> SL;
//ordered_set = order_of_key(.)
//ordered_set = find_by_order(.)
typedef ordered_set<int> OSI;
typedef ordered_set<ll> OSL;
typedef ordered_multiset<int> MOSI;
typedef ordered_multiset<ll> MOSL;
typedef unordered_map<ll, int, h_llint> UMLI;
typedef unordered_map<ll, ll, h_llint> UMLL;
typedef unordered_map<PLL, int, h_pair> UMPI;
typedef unordered_map<PLL, ll, h_pair> UMPL;

int ar[MV], dsc[MV], mdsc[MV], cord[MV], droc[MV], P[MV][LMV], lvl[MV], sze[MV], disc[MV], udsc[MV], head[MV], seg[4*MV];
ll arr[MV];
bool vis[MV], art[MV];
stack<int> S;
vector<PII> edg, G[MV];
VI TVC[MV];
map<PII, bool> mkd;
multiset<int> tnx[MV];
int tx, x;

void dfs_vis1(int s, int p, int id)
{
    dsc[s] = mdsc[s] = ++tx;
    if((id != -1) && !vis[id])
    {
        S.push(id);
        vis[id] = 1;
    }       
    bool chd = 0;
    for(auto u : G[s])
    {
        if(u.ss == id)
        continue;
        else if(!dsc[u.ff])
        {
            dfs_vis1(u.ff, s, u.ss);
            mdsc[s] = min(mdsc[s], mdsc[u.ff]);
            if((p != -1) ? (mdsc[u.ff] >= dsc[s]) : chd)
            {
                art[s] = 1;
                x++;
                while(!S.empty() && (S.top() != u.ss))
                {   
                    TVC[x].pb(S.top());
                    S.pop();
                }
                if(!S.empty())
                {
                    TVC[x].pb(S.top());
                    S.pop();
                }       
            }   
            chd = 1;
        }
        else if(!vis[u.ss])
        {
            S.push(u.ss);
            vis[u.ss] = 1;
            mdsc[s] = min(mdsc[s], dsc[u.ff]);
        }       
    }
    return;
}

void dfs_vis2(int s, int p)
{
	// whoami("dfs", s, p);
	P[s][0] = p;
	if(p != -1)
	lvl[s] = 1 + lvl[p];
	sze[s] = 1;
	for(auto u : G[s])
	{
		if(u.ff != p)
		{	
			dfs_vis2(u.ff, s);
			sze[s] += sze[u.ff];
		}		
	}
	return;	
}

void dfs_vis3(int s, int p, int chh)
{
	head[s] = chh;
	tx++;
	disc[s] = tx;
	udsc[tx] = s;
	VI chd;
	for(auto u : G[s])
	{
		if(u.ff != p)
		chd.pb(u.ff);
	}
	sort(chd.begin(), chd.end(), [](int A, int B){ return (sze[A] > sze[B]); });
	bool ok = 1;
	for(auto u : chd)
	{
		if(ok)
		{
			dfs_vis3(u, s, chh);
			ok ^= 1;
		}	
		else dfs_vis3(u, s, u);
	}
	return;
}

class segtree
{
	public: void build(int i, int s, int d);
			int merger(int left, int right);
			void update(int i, int s, int d, int qs, int qd, int vx);
			int query(int i, int s, int d, int qs, int qd);
};

class sparse
{
	public: void build(int n);
			int LCA_find(int p, int q);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i] = MOD;
		return;
	}
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

int segtree::merger(int left, int right)
{
	return min(left, right);
}

void segtree::update(int i, int s, int d, int qs, int qd, int vx)
{
	if(s > qd || d < qs)
	return;	
	else if(qs <= s && d <= qd)
	{
		seg[i] = vx;
		return;
	}	
	int m = (s + d)/2;
	update(2*i, s, m, qs, qd, vx);
	update(2*i+1, m+1, d, qs, qd, vx);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;	
}

int segtree::query(int i, int s, int d, int qs, int qd)
{
	if(s > qd || d < qs)
	return MOD;
	else if(qs <= s && d <= qd)
	return seg[i];
	int m = (s + d)/2;
	int p1 = query(2*i, s, m, qs, qd);
	int p2 = query(2*i+1, m+1, d, qs, qd);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return merger(p1, p2); 
}

void sparse::build(int n)
{
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(P[i][j-1] != -1)
			P[i][j] = P[P[i][j-1]][j-1];
		}	
	}
	return;
}

int sparse::LCA_find(int p, int q)
{
	if(lvl[p] < lvl[q])
	{
		int tp = p;
		p = q;
		q = tp;
	}
	int lx = 0;
	for(lx=1;(1<<lx)<=lvl[p];lx++);
	lx--;
	for(int i=lx;i>=0;i--)
	{
		if((lvl[p] - (1<<i)) >= lvl[q])
		p = P[p][i];
	}	
	if(p == q)
	return p;
	for(int i=lx;i>=0;i--)
	{
		if((P[p][i] != -1) && (P[p][i] != P[q][i]))
		{
			p = P[p][i];
			q = P[q][i];
		}	
	}	
	return P[p][0];
}

void solve(int T)
{
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    cin>>ar[i];	
    for(int i=0;i<m;i++)
    {
        int s,d;
        cin>>s>>d;
        edg.pb({s, d});
        G[s].pb({d, i});
        G[d].pb({s, i});
    }   
    tx = 0, x = 0;
    for(int i=1;i<=n;i++)
    {
        if(!dsc[i])
        {   
            dfs_vis1(i, -1, -1);
            if(!S.empty())
            {   
                x++;
                while(!S.empty() && (S.top() != -1))
                {
                    TVC[x].pb(S.top());
                    S.pop();
                }
            }       
        }   
    }
    VI arp;
    for(int i=1;i<=x;i++)
    {
    	VI tnn;
    	for(auto &&u : TVC[i])
    	{
    		int s = edg[u].ff;
    		int d = edg[u].ss;
    		if(!art[s])
    		tnn.pb(s);
    		else arp.pb(s);
    		if(!art[d])
    		tnn.pb(d);
    		else arp.pb(d);
    	}
    	sort(begin(tnn), end(tnn));
    	tnn.resize(unique(begin(tnn), end(tnn)) - begin(tnn));
    	for(auto &&u : tnn)
    	{	
    		cord[u] = i;
    		tnx[i].ins(ar[u]);
    	}	
    }
    sort(begin(arp), end(arp));
    arp.resize(unique(begin(arp), end(arp)) - begin(arp));
    int xt = x;
    for(auto &&u : arp)
    {
    	cord[u] = ++xt;
    	droc[xt] = u;
    	tnx[xt].ins(ar[u]);
    }
    arp.clear();
    for(int i=1;i<=n;i++)
    G[i].clear();	
	for(int i=1;i<=x;i++)
	{
		for(auto &&u : TVC[i])
		{
			int s = cord[edg[u].ff];
			int d = cord[edg[u].ss];
			if(s > x)
			arp.pb(s);
			if(d > x)
			arp.pb(d);	
		}	
		sort(begin(arp), end(arp));
		arp.resize(unique(begin(arp), end(arp)) - begin(arp));
		for(auto &&u : arp)
		{
			G[u].pb({i, -1});
			G[i].pb({u, -1});
		}
		arp.clear();	
	}	
    dfs_vis2(1, -1);
    iota(head, head+MV, 0);
    tx = 0;
    dfs_vis3(1, -1, 1);
    n = xt;
    for(int i=x+1;i<=n;i++)
    {
    	if(P[i][0] != -1)
    	tnx[P[i][0]].ins(ar[droc[i]]);		
    }	
    segtree D1;
	sparse D2;
	D1.build(1, 1, n);
	D2.build(n);
	for(int i=1;i<=n;i++)	
	{	
		if((int)tnx[i].sz() > 0)
		D1.update(1, 1, n, disc[i], disc[i], *tnx[i].begin());	
	}
	while(q--)
	{
		char ch;
		cin>>ch;
		if(ch == 'C')
		{
			int ps,w;
			cin>>ps>>w;
			int lf = cord[ps];
			if(lf > x)
			{
				tnx[lf].erase(tnx[lf].find(ar[ps]));
				tnx[lf].ins(w);
				D1.update(1, 1, n, disc[lf], disc[lf], *tnx[lf].begin());
				if(P[lf][0] != -1)
				{
					tnx[P[lf][0]].erase(tnx[P[lf][0]].find(ar[ps]));
					tnx[P[lf][0]].ins(w);
					D1.update(1, 1, n, disc[P[lf][0]], disc[P[lf][0]], *tnx[P[lf][0]].begin());
				}
				ar[ps] = w;	
			}
			else
			{
				tnx[lf].erase(tnx[lf].find(ar[ps]));
				ar[ps] = w;
				tnx[lf].ins(w);
				D1.update(1, 1, n, disc[lf], disc[lf], *tnx[lf].begin());
			}	
		}
		else
		{
			int mx = MOD;
			int l,r;
			cin>>l>>r;
			if(l == r)
			mx = min(mx, ar[l]);
			else
			{	
				l = cord[l];
				r = cord[r];
				int lc = D2.LCA_find(l, r);
				// whoami(l, r, lc);
				while(head[lc] != head[l])
				{
					mx = min(mx, D1.query(1, 1, n, disc[head[l]], disc[l]));
					l = P[head[l]][0];
				}
				mx = min(mx, D1.query(1, 1, n, disc[lc], disc[l]));
				while(head[lc] != head[r])
				{
					mx = min(mx, D1.query(1, 1, n, disc[head[r]], disc[r]));
					r = P[head[r]][0];
				}
				mx = min(mx, D1.query(1, 1, n, disc[lc], disc[r]));
				if((lc <= x) && (P[lc][0] != -1))
				mx = min(mx, D1.query(1, 1, n, disc[P[lc][0]], disc[P[lc][0]]));
			}
			cout<<mx<<"\n";	
		}	
	}	
    return;
}

int main(void)
{
	FLASH();
	//freopen("cowjog.in", "r", stdin);
	//freopen("cowjog.out", "w", stdout);
	int T;
	T = 1;

#ifndef ONLINE_JUDGE
	time_t time_t1, time_t2;
	time_t1 = clock();
#endif

	//cin>>T;
	while(T--)
	solve(T);

#ifndef ONLINE_JUDGE
	time_t2 = clock();
	SETF();
	cerr<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
	UNSETF();
#endif

	return 0;
}