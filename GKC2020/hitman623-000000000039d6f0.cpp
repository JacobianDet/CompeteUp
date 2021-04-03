#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,q,d[100005];
const int N=100005;
int seg[N<<2];
void build(int node,int start,int end){
    if(start==end){
        seg[node]=d[start];
        return;
    }
    int mid=(start+end)>>1;
    build(node<<1,start,mid);
    build(node<<1|1,mid+1,end);
    seg[node]=max(seg[node<<1],seg[node<<1|1]);
}
int query(int node,int start,int end,int l,int r){
    if(l<=start && r>=end) return seg[node];
    if(r<start || l>end) return 0;
    int mid=(start+end)>>1;
    int ans1=query(node<<1,start,mid,l,r);
    int ans2=query(node<<1|1,mid+1,end,l,r);
    return max(ans1,ans2);
}
mi pos;
void solve(){
    pos.clear();
    cin>>n>>q;
    rep(i,2,n+1){
        cin>>d[i];
        pos[d[i]]=i;
    }
    build(1,2,n);
    while(q--){
        int s,k;
        cin>>s>>k;
        k--;
        if(k==0){
            cout<<s<<" ";
            continue;
        }
        int lo=max(0,s+k-n)-1,hi=min(s-1,k);
        while(hi-lo>1){
            int mid=(lo+hi)/2;
            if(query(1,2,n,s-mid+1,s)>query(1,2,n,s+1,s+k-mid)) hi=mid;
            else lo=mid;
        }
        int l=s-hi+1,r=s+k-hi;
        if(r+1<=n){
            if(d[l]>query(1,2,n,s+1,r+1)) l++,r++;
        }
        if(pos[query(1,2,n,l,r)]<=s) cout<<l-1<<" ";
        else cout<<r<<" ";
    }
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    rep(i,1,t+1){
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}