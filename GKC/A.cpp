#include <bits/stdc++.h>
using namespace std;
#define input freopen("B-large.in","r",stdin)
#define output freopen("out8.txt","w",stdout)
#define ll long long
ll a,b=-1;

class graph
{
    ll n;
    vector<pair<ll,ll>> *edge;
	vector<ll> *vt;
    public:

    graph(ll v)
    {
        n=v;
        edge = new vector<pair<ll,ll>>[v+1];
        vt = new vector<ll>[v+1];
    }
    void add_edge(ll u,ll v,ll c)
    {
        edge[u].push_back(make_pair(c,v));
        edge[v].push_back(make_pair(c,u));
    }

	void sort_edge()
	{
		for(ll i=1;i<=n;i++)
			sort(edge[i].begin(),edge[i].end());
	}

    ll fun()
    {
        for(ll i=1;i<=n;i++)
		{
			bool flag=false;
			ll p=edge[i][0].second;

			for(ll k=0;k<vt[p].size();k++)
			{
				if(vt[p][k]==i)
					flag=true;
			}
			if(!flag)
				vt[p].push_back(i);
			bool flag2=false;
			for(ll k=0;k<vt[i].size();k++)
			{
				if(vt[i][k]==p)
				    flag2=true;
			}
			if(!flag2)
			vt[i].push_back(p);
		}

		ll ans=1;
		ll vis[n+1];
		for(ll i=0 ; i<=n ; i++)
			vis[i]=false;

		for(ll i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				bool flag=false;
				queue<ll> qq;
				qq.push(i);
				vis[i]=true;
				while(!qq.empty())
				{
					ll p=qq.front();
					qq.pop();
					if(b!=-1 && p==b)
						flag=1;
					for(ll i=0;i<vt[p].size();i++)
					{
						ll q=vt[p][i];
						if(!vis[q])
						{
							qq.push(q);
							vis[q]=true;
						}
					}
				}
				if(flag)
				{
					ll z=vt[a].size()+vt[b].size()-2;
					ans*=2*pow(2,z);
				}
				else
				ans*=2;
			}
		}
		return ans;
    }
};
int main()
{
    input;
    output;
    ll t;
    cin>>t;
    ll z=1;
    while(t--)
    {
    	a=b=-1;
        cout<<"Case #"<<z<<": ";
        z++;
        ll n,e;
        cin>>n>>e;
        graph g(n);
        ll u,v,c;
        for(ll i=0 ; i<e ; i++)
        {
            cin>>u>>v>>c;
            if(c==0)
			{
				a=u; b=v;
			}
            g.add_edge(u,v,c);
        }
        g.sort_edge();
        cout<<g.fun()<<endl;
    }
   return 0;
}
