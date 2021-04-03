#include <bits/stdc++.h>
using namespace std;
#define fi first
#define endl "\n"
#define se second
#define ll long long
#define inf 0x3f3f3f3f
#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 3e5+5;
const ll mod =   1e9+7;
ll tr[4*N],arr[N],n,q;
void build(ll node, ll st, ll en)
{
    if(st == en)
    {
        tr[node] = arr[st];
    }
    else
    {
        int mid = (st + en) / 2;
        build(2*node, st, mid);
        build(2*node+1, mid+1, en);
        tr[node] = 1ll*(tr[2*node] + tr[2*node+1]);
    }
}
void update(ll node, ll st, ll en, ll l, ll r, ll val)
{
    if (st > en or st > r or en < l)
        return;
    if (st == en)
    {
        tr[node] += val;
        return;
    }
    ll mid = (st + en) / 2;
    update(node*2, st, mid, l, r, val);
    update(node*2 + 1, mid + 1, en, l, r, val);
    tr[node] =1ll*( tr[node*2] + tr[node*2+1]);
}
ll query(ll node, ll st, ll en, ll l, ll r)
{
    if(r < st or en < l)
    {
        return 0;
    }
    if(l <= st and en <= r)
    {
        return tr[node];
    }
    ll mid = (st + en) / 2;
    ll p1 = query(2*node, st, mid, l, r);
    ll p2 = query(2*node+1, mid+1, en, l, r);
    return 1ll*(p1 + p2);
}
int main()
{  fast
cin>>n>>q;
for(int i=1;i<=n;i++)
cin>>arr[i];
build(1,1,n);
for(int i=1;i<=q;i++) {
	int x;
	cin>>x;
	if(x==2)
	{ll y;cin>>y;
		cout<<query(1,1,n,y,y)<<endl;
	}
	else{
		ll a,b,c;
		cin>>a>>b>>c;
		update(1,1,n,a,b,c);
	}
}
 
}