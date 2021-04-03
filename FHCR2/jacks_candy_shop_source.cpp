#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define fu(i,a,n) for(i=a;i<=n;i++)
#define fd(i,a,n) for(i=a;i>=n;i--)
#define rep(i,n)  for(i=0;i<n;i++)
#define si(i)  scanf("%d",&i)
#define ss(s)  scanf("%s",s)
#define sl(i)  scanf("%lld",&i)
#define pi(i)  printf("%d",i)
#define pl(i)  printf("%lld",i);
#define ps()   printf(" ");
#define pn()   printf("\n");
#define all(v)  v.begin(),v.end()
vector <ll> adj[100005];
vector< pair < ll, ll > >  tree(4*100005);
ll tmv=0;
vector< pair< ll, ll > >  se(100005);
void dfs(ll u, vector< ll > adj[], vector< bool > &vis,ll arr[], ll idn[])
{
	vis[u]=1;
	ll i;
	se[u].first=++tmv;
	idn[u]=tmv;
	arr[tmv]=u;
	rep(i,adj[u].size())
	{
		if(!vis[adj[u][i]])
		{
			dfs(adj[u][i],adj,vis,arr,idn);
		}
	}
	se[u].second=tmv;
}
void build_tree(ll index, ll a, ll b, ll arr[])
{
	if(a>b)
	return;
	if(a==b)
	{
		tree[index].first=arr[a];
		tree[index].second=a;
		return;
	}
	build_tree(index*2,a,(a+b)/2,arr);
	build_tree(index*2+1,(a+b)/2+1,b,arr);
	if(tree[index*2].first>tree[index*2+1].first)
	{
		tree[index].first=tree[index*2].first;
		tree[index].second=tree[index*2].second;
	}
	else
	{	
		tree[index].first=tree[index*2+1].first;
		tree[index].second=tree[index*2+1].second;
	}
}
pair< ll, ll > query_tree(ll index, ll a, ll b, ll i, ll j)
{
	pair< ll, ll > res;
	res.first=0;
	res.second=0;
	if(a>b||a>j||b<i)
	return res;
	if(a>=i&&b<=j)
	return tree[index];
	ll mid = (a+b)/2;
    if (i > mid)
    return query_tree(2*index+1, mid+1, b, i, j);
    if (j <= mid)
    return query_tree(2*index, a, mid, i, j);
    pair< ll, ll > q1 = query_tree(index*2, a, (a+b)/2, i, j);
    pair<  ll, ll > q2 = query_tree(1+index*2, 1+(a+b)/2, b, i, j);
    if(q1.first>q2.first)
    return q1;
    return q2;
}
void update_tree(ll index, ll a, ll b, ll i, ll j)
{
	if(a>j||b<i||a>b)
	return ;
	if(a>=i&&b<=j)
	{
		tree[index].first=0;
		tree[index].second=0;
		return;
	}
	ll mid=(a+b)/2;
	if (i > mid)
    update_tree(2*index+1, mid+1, b, i, j);
    if (j <= mid)
    update_tree(2*index, a, mid, i, j);
    if(tree[index*2].first>tree[index*2+1].first)
	{
		tree[index].first=tree[index*2].first;
		tree[index].second=tree[index*2].second;
	}
	else
	{	
		tree[index].first=tree[index*2+1].first;
		tree[index].second=tree[index*2+1].second;
	}
}
int main()
{
	ll t;
	cin>>t;
	ll z=0;
	while(z<t)
	{
		tmv=0;
	  ll n,m,a,b;
	  scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
	  vector< ll > adj[n+1];
	  for(ll j=1;j<=n-1;j++)
	  {
	  	ll k;
	  	scanf("%lld",&k);
	  	adj[j].push_back(k);
	  	adj[k].push_back(j);
	  }
	  ll arr[n+1];
	  ll idn[n+1];
	  for(ll j=0;j<=n;j++)
	  {
	  	arr[j]=0;
	  	idn[j]=0;
	  }
	  tree.clear();
	  tree.resize(4*100005,{0,0});
	  vector< bool > vis(n+1,false);
	    se.clear();
	  se.resize(100005,{0,0});
	  dfs(0,adj,vis,arr,idn);
	 /* for(ll i=0;i<=n;i++)
	  cout<<arr[i]<<" ";
	  cout<<endl;
	  for(ll j=0;j<n;j++)
	  {
	  	cout<<se[j].first<<" "<<se[j].second<<" "<<idn[j]<<endl;
	  }*/
	  build_tree(1,0,n,arr);
	  ll ans=0;
	  vector< ll > level(n+1,0);
	  vector< ll > ldj[n+1];
	  queue< ll > q;
	  q.push(0);
	  level[0]=1;
	  while(!q.empty())
	  {
	  	ll k1=q.front();
	  	q.pop();
	  	for(ll j=0;j<adj[k1].size();j++)
	  	{
	  		if(level[adj[k1][j]]==0)
	  		{
	  			level[adj[k1][j]]=level[k1]+1;
	  			q.push(adj[k1][j]);
	  		}
	  	}
	  }
	  vector< ll > c;
	  for(ll j=0;j<m;j++)
	  {
	  	ll k=(a*j+b)%n;
	  c.push_back(k);
	  ldj[level[k]].push_back(k);
      }
      ans=0;
      for(ll j=n;j>=0;j--)
      {
      	for(ll i=0;i<ldj[j].size();i++)
      	{
      		//cout<<se[ldj[j][i]].first<<" "<<se[ldj[j][i]].second<<" j= "<<j<<" "<<ldj[j][i]<<endl;
      		pair< ll, ll > h=query_tree(1,0,n,se[ldj[j][i]].first,se[ldj[j][i]].second);
      		ans+=h.first;
      		update_tree(1,0,n,h.second,h.second);
      	}
      }
      cout<<"Case #"<<z+1<<": "; 
	  cout<<ans<<endl;
	  z++;
	}
	return 0;
}
