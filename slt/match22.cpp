#include <bits/stdc++.h>
using namespace std;

map <int,vector<int>> m;
map <int,vector<int>> :: iterator it;
int a[100000],b[100000],c[400000],d[400000];
int x,y,z;

void call(int p,int l,int r)
{
    if(l==r)
    {
        if(a[l]==b[l])
            c[p]=1;
        else
            c[p]=0;
        return;
    }
    int m=(l+r)>>1;
    call(2*p+1,l,m);
    call(2*p+2,m+1,r);
    c[p]=c[2*p+1]+c[2*p+2];
}

void update(int p,int l,int r)
{
    if(d[p]!=-1)
    {
        it=m.find(d[p]);
        if(it==m.end())
            c[p]=0;
        else
        {
            int i=lower_bound((it->second).begin(),(it->second).end(),l)-(it->second).begin();
            int j=upper_bound((it->second).begin(),(it->second).end(),r)-(it->second).begin();
            c[p]=j-i;
        }
        if(l!=r)
        {
            d[2*p+1]=d[p];
            d[2*p+2]=d[p];
        }
        d[p]=-1;
    }
    if(l>y || r<x)
        return;
    if(l>=x && r<=y)
    {
        it=m.find(z);
        if(it==m.end())
            c[p]=0;
        else
        {
            int i=lower_bound((it->second).begin(),(it->second).end(),l)-(it->second).begin();
            int j=upper_bound((it->second).begin(),(it->second).end(),r)-(it->second).begin();
            c[p]=j-i;
        }
        if(l!=r)
        {
            d[2*p+1]=z;
            d[2*p+2]=z;
        }
        return;
    }
    int m=(l+r)>>1;
    update(2*p+1,l,m);
    update(2*p+2,m+1,r);
    c[p]=c[2*p+1]+c[2*p+2];
}

int compute(int p,int l,int r)
{
    if(d[p]!=-1)
    {
        it=m.find(d[p]);
        if(it==m.end())
            c[p]=0;
        else
        {
            int i=lower_bound((it->second).begin(),(it->second).end(),l)-(it->second).begin();
            int j=upper_bound((it->second).begin(),(it->second).end(),r)-(it->second).begin();
            c[p]=j-i;
        }
        if(l!=r)
        {
            d[2*p+1]=d[p];
            d[2*p+2]=d[p];
        }
        d[p]=-1;
    }
    if(l>y || r<x)
        return 0;
    if(l>=x && r<=y)
        return c[p];
    int m=(l+r)>>1;
    m=compute(2*p+1,l,m)+compute(2*p+2,m+1,r);
    return m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n,q,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        for(i=0;i<n;i++)
            cin>>a[i];
        j=0;
        for(i=0;i<n;i++)
        {
            cin>>b[i];
            if(a[i]==b[i])
                j++;
            m[b[i]].push_back(i);
        }
        i=1;
        while(i<n)
            i*=2;
        i=2*i-1;
        memset(d,-1,4*i);
        call(0,0,n-1);
        while(q--)
        {
            cin>>x>>y>>z;
            x=(x^j)-1;
            y=(y^j)-1;
            z=z^j;
            update(0,0,n-1);
            x=0;
            y=n-1;
            j=c[0];
            cout<<j<<"\n";
        }
        m.clear();
    }
    return 0;
}